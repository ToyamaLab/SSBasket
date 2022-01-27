# SSBasketとは
SuperSQLを拡張し、Linked Open Data(LOD)の探索を可能としたシステムです。

SuperSQLのWHERE句に記述したSPARQLクエリによってLODを探索し、結果をHTML出力します。

連鎖的なデータであるSPARQL問い合わせ結果をSuperSQLのレイアウト力を活かし、入れ子構造で表示します。
更に、取得結果を新たな入力としてデータ探索を行い、再帰的なデータの動的に表示することができます。


# SuperSQLとは

SuperSQLとは慶應義塾大学理工学部情報工学科の遠山研究室に於いて開発されているSQLの拡張言語です。データベースにあるデータを様々なメディアに任意の構造で出力することができます。詳しくは[ポータルサイト][1]をご覧ください。

# インストール手順(ソースからビルド)

## 必要なソフトウェア
- Java
- Maven
- SQLite
- その他DBMS(PostgreSQL, MySQLなど)

## 手順
1. GitHubからのクローン

    `$ git clone https://github.com/ayumi-ttt/SSBasket.git`


2. 初期設定

    ```
    $ cd SSBasket
    $ ./configure
    ```
    これで初期設定が終わります。\
    `./configure`で行われるのは
    - $HOME直下にSSBasketディレクトリが生成されます。その中にクエリを入れる`ssbasket_query`ディレクトリと出力結果を保存する`ssbasket_result`、ライブラリが入る`libs`が生成されます。`ssbasket_query`内にはテストクエリとして`test.ssb`が保存されます。また`mvn package`コマンドが実行され生成されたjarがSSBasketディレクトリ直下に配置されます。
    - $HOME直下に`config.yaml`という設定ファイルが生成されます。設定内容は以下です。
        
        - diver: DBMSの指定。postgresql, mysql, sqliteなど 
        - db: データベース名。
        - host: データベースが動いているホスト。
        - user: データベースユーザ名。
        - outdir: 実行結果の保存場所。初期値は`$HOME/SuperSQL/ssb_result`
        - port: ポート。初期値は5432。
        - password: データベースのパスワード。

    - $HOME直下のbinディレクトリに`ssb`実行ファイルが配置されPATHを通します。

    これらの設定を$HOME以外にしてほしい場合は
    
    `$ ./configure.sh --installdir <dir_path>`
    
    で指定してください。(config.yamlは$HOMEに、ssb実行ファイルは$HOME/binに配置されます)

    ここまで行なって
    
    `$ ssb -v`

    が実行できたら無事初期設定は終了しています。

3. テストクエリの実行
   
   利用状況に応じて、3.1 あるいは 3.2 を実施してください。

   3.1 SQLite 

    以下`$HOME/SSBasket/SQLite3`にSQLiteのディレクトリが存在するとします。適宜読み替えを行なってください。
    
    ```
    SQLiteを起動
    新しいデータベース: test.db を作成
    ```

    これでサンプルデータベスが作成されます。次に`config.yaml`を以下のように書き換えます。尚`<home_dir | install_dir>`に関してはパスを明示してください。
    
    ```
    driver=sqite
    db=<db_name>
    host=localhost
    user=<user_name>
    outdir=<home_dir | install_dir>/SSBasket/ssb_result
    sqlite_dir=<SQLiteのディレクトリのパス ex. home_dir/SSBasket/SQLite3/>
    sparql_endpoint=<sparqlendpoint>
    ```
    
    [SPARQLエンドポイント][2]はデフォルトで[DBPedia Japanese][3]が指定されています。

    SPARQL PREFIXを追加したい場合`sparql_prefix=<prefix>`を追記してください。

    ここまで終わったらSSBasketフォルダに移動して実行をします。
    
    ```
    $ cd ~/SSBasket/ssb_query
    $ ssb -f test.ssb
    ```
    
    このクエリはHTMLを生成するのでssb_resultフォルダにあるtest.htmlをブラウザで確認してください。ssbコマンドのオプションは主なものが以下です。

    - -v, --version, -version: バージョン表示
    - -debug: デバッグコードの出力
    - -f: ファイル指定
    - -c: コンフィグファイルの指定(指定なしで$HOME/config.yamlを参照します)
    
   3.2 その他のDBMS

    SSBasketでは拡張子が`.ssql`のSuperSQLクエリも実行できます。
    
　　 また、現在は未対応ですが、今後、他のデータベースのデータとの結合表示の実装を考えています。これらのための設定の参考にしてください。
   
　　 SPARQL問い合わせ結果、CSVからの入力はdriverに設定したデータベースではなく、SQLiteを参照する仕様となります。

   以下`$HOME`にインストールし同マシン内でPostgreSQLが動いているとします。適宜読み替えを行なってください。
    ```
    $ createdb <db_name>
    $ cd SSBasket/test_queries/config_file_test_DB
    $ psql -d <db_name> -f test.sql
    ```

   これでサンプルデータベスが作成されます。次に`config.yaml`を以下のように書き換えます。尚`<home_dir | install_dir>`に関してはパスを明示してください。
    ```
    driver=postgresql
    db=<db_name>
    host=localhost
    user=<user_name>
    outdir=<home_dir | install_dir>/SSBasket/ssb_result
    port=5432
    sqlite_dir=<SQLiteのディレクトリのパス ex. home_dir/SSBasket/SQLite3/>
    sqlite_db=<SQLiteのdb_name>
    sparql_endpoint=<sparqlendpoint>
    ```
    
   `driver`が`sqlite`のとき、`db`と`sqlite_db`が両方設定されていた場合、`sqlite_db`が優先されます。

　　 [SPARQLエンドポイント][2]はデフォルトで[DBPedia Japanese][3]が指定されています。

   SPARQL PREFIXを追加したい場合`sparql_prefix=<prefix>`を追記してください。

   ここまで終わったらSSBasketフォルダに移動して実行をします。
    ```
    $ cd ~/SSBasket/ssb_query
    $ ssb -f test.ssb
    ```
   このクエリはHTMLを生成するのでssb_resultフォルダにあるtest.htmlをブラウザで確認してください。ssbコマンドのオプションは主なものが以下です。

    - -v, --version, -version: バージョン表示
    - -debug: デバッグコードの出力
    - -f: ファイル指定
    - -c: コンフィグファイルの指定(指定なしで$HOME/config.yamlを参照します)

[1]:http://ssql.db.ics.keio.ac.jp/
[2]:http://ja.dbpedia.org/sparql
[3]:https://ja.dbpedia.org
