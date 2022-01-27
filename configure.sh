#/bin/sh

for OPT in "$@"
do
	case "$OPT" in
		'--installdir' )
			FLAG_installdir=1
			INSTALL_NAME=$2
			;;
	esac
	shift
done

INSTALLDIR=$HOME
if [ "$FLAG_installdir" ]; then
	INSTALLDIR=$INSTALL_NAME
fi


SCRIPT_DIR=$(cd $(dirname $0); pwd)

#SSBasket用のディレクトリ作成
mkdir -p $INSTALLDIR/SSBasket

#SSBasket出力用のディレクトリ作成
mkdir -p $INSTALLDIR/SSBasket/ssb_result

#SuperSQLクエリ置き場の作成
mkdir -p $INSTALLDIR/SSBasket/ssb_query

#テストクエリの作成
cat $SCRIPT_DIR/test_queries/test_ssbasket_queries/test.ssb > $INSTALLDIR/SSBasket/ssb_query/test.ssb

#SSBasketのコンフィグファイルの作成
cat << EOS > $HOME/config.yaml
driver=
db=
host=
user=
outdir=$INSTALLDIR/SSBasket/ssb_result
port=
sparql_endpoint=http://ja.dbpedia.org/sparql
sqlite_dir=$INSTALLDIR/SSBasket/sqlite3/
sqlite_db=test.db
EOS

#jarの作成
mvn package
cp $SCRIPT_DIR/target/newssql-1.0-jar-with-dependencies.jar $INSTALLDIR/SSBasket/ssbasket.jar

#ライブラリの移動
mkdir -p $INSTALLDIR/SSBasket/libs
cp -r $SCRIPT_DIR/lib/* $INSTALLDIR/SSBasket/libs/

#ssql実行ファイルの移動
mkdir -p $HOME/bin
cat << EOS > ./ssb.sh
#!/bin/sh

#ssbasket.jarの位置指定
CLASSDIR=$INSTALLDIR/SSBasket

EOS

cat << 'EOS' >> ./ssb.sh
#オプションのチェック
files=()
conf=""
options=()
VMs=()
FLAG_filespace=
FLAG_confspace=
for OPT in "$@"
do
	case "$OPT" in
		'-f' )
			FLAG_file=1
			FLAG_filespace=1
			FLAG_confspace=
			;;
		'-c' )
			FLAG_filespace=
			FLAG_confspace=1
			FLAG_conf=1
			;;
		'-v' | '--version' | '-version' )
			FLAG_filespace=
			FLAG_confspace=
			FLAG_version=1
			;;
		-D*)
			VMs+=($OPT)
			;;
		-* )
			FLAG_filespace=
			FLAG_confspace=
			options+=($OPT)
			;;
		* )
			if [ "$FLAG_filespace" ]; then
				files+=($OPT)
			elif [ "$FLAG_confspace" ]; then
				conf=$OPT
			else
				options+=($OPT)
			fi
			;;
	esac
	shift
done

if [ "$FLAG_version" ]; then
	echo "java -cp $CLASSDIR/libs/*:$CLASSDIR/ssbasket.jar ssbasket.FrontEnd -v"
	java -cp $CLASSDIR/libs/*:$CLASSDIR/ssbasket.jar ssbasket.FrontEnd -v
	exit 0
fi

files_full=()
#ssbasketファイル指定
for file in ${files[@]}
do
	if [ ! -e $file ]; then
   		echo "Not found: $file"
   		exit 1
	fi
	cd `dirname $file`
	file_path=`pwd`/`basename $file`
	files_full+=($file_path)
done

#configファイル
if [ "$FLAG_conf" ]; then
	if [ ! -e $conf ]; then
   		echo "Not found: $conf"
   		exit 1
	fi
	cd `dirname $conf`
	conf_path=`pwd`/`basename $conf`
	options+=("-c" $conf_path)
fi

for o in ${options[@]}
do
	option_str+="${o} "
done


for file in ${files_full[@]}
do
	echo "java ${VMs} -cp $CLASSDIR/libs/*:$HOME/SSBasket/ssbasket.jar ssbasket./FrontEnd -f ${file} ${option_str}"
	java $VMs -cp $CLASSDIR/libs/*:$CLASSDIR/ssbasket.jar supersql.FrontEnd -f $file $option_str
done
EOS
mv ssb.sh $HOME/bin/ssb
chmod 755 $HOME/bin/ssb

if [ `echo $PATH | grep "${HOME}/bin"` ]; then
	:
else
	export PATH=$PATH:$HOME/bin
fi
