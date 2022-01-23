package supersql.recursivesearch;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import supersql.extendclass.ExtList;
import supersql.parser.Start_Parse;

public class RecursiveMakeSSBasket_old {
	private static String recursive_expression;
	static String ssqlgenerate;
	static String ssqlfrom;

	static String s = new String();
	static String yet = new String();
	static String value = "o1";
	static int[] intlist = new int[Start_Parse.hopCount+2];
	static boolean sflg = true;
	static boolean eflg = true;

	public static String MakeRecursiveSSBasketQuery() {
		for(int i=0;i<intlist.length;i++) {intlist[i]=0;}
			//SPARQLクエリの ?変数 を取り出しtに格納する
	//		String s = input.substring(input.indexOf("SELECT")+7,input.indexOf("WHERE"));
	//		String[] t = s.split(" ");
	//		String[] select = new String[t.length];
			//SSQLクエリ再帰部分 [origin,[]!]!
	//				String origin_alias = "sparqlresult" + String.valueOf(GlobalEnv.getRecursiveNum()-1);
	//				String origin_alias = "sparqlresult0";
	//				String ssqlsubquery = "";
	//				ssqlsubquery += "a(" + origin_alias + ".related_subject),[";
				//	for(int i=0;i<t.length-1;i++) {
	//				int ii=1;
	//					select[ii] = t[ii].substring(1,t[ii].length());
	//					if(select[ii]!=null && select[ii]!="") {
						//	if(ii>0) {
						//		ssqlsubquery +="!";
						//	}
	//					}
				//	}
	//				ssqlsubquery += "}\n";
				//			for(int j=0;j<GlobalEnv.getRecursiveSPARQLNum()+1;j++) {
				//			if(j>0) {ssqlsubquery +="!";}
				//			ssqlsubquery += "[a(c"+GlobalEnv.getRecursiveSPARQLNum()+".o1)]!";
				//			}


				//SSBasketクエリ全体
			String ssbasketquery=new String();
			ssbasketquery+=  "SSBASKET("
							 +Start_Parse.hopCount
							 +"){\nSSQL{\n";
							 makeGenerateFrom();
			ssbasketquery+=	 ssqlgenerate
							 +ssqlfrom
							 +"\n}\nRECURSIVE_SPARQL{\n"
						     + Start_Parse.recursiveSPARQLQuery
						     +"\n}\nRECURSIVE_EXPRESSION{\n"
						     +Start_Parse.recursiveExpression
						     +"\n}\n}";
//			System.out.println("---------------recursive ssbasket query--------------");
//			System.out.println(ssbasketquery);
			return ssbasketquery;
	}

	public static void makeGenerateFrom() {
		ssqlgenerate = new String();
		ssqlfrom = new String();
//		ssqlfrom += "FROM \"#sparqlresult" + String.valueOf(GlobalEnv.getRecursiveNum()-1)+".csv\" " + origin_alias;
		recursive_expression = Start_Parse.recursiveExpression;
//		String key = new String();
		ssqlgenerate += "GENERATE HTML{\n";
		ssqlfrom +="FROM ";
		ExtList now = new ExtList();
		now = RecursiveSearch.recursivefiletree;
		s = recursive_expression;
		yet = recursive_expression;
//		s.replaceAll("[svo][0-9]*", "h[0-9]*");
//		yet.replaceAll("[svo]","h[0-9]*");
		yet = replaceH(recursive_expression);
		s = yet;
		makeGenerate(RecursiveSearch.recursivefiletree, 0);
//		ssqlgenerate +=yet.substring(yet.indexOf("h"+String.valueOf(Start_Parse.hopCount))+2,yet.length());
		ssqlgenerate +="}";
				//@{table}";
		//		+ ",cssfile='"+ GlobalEnv.getfileparent() + "/jscss/"+GlobalEnv.getfilename().substring(GlobalEnv.getfileparent().length()+1,GlobalEnv.getfilename().indexOf(".ssql"))+".css'}\n";
				//,charset=\'UTF-8\'
	}

	public static void makeGenerate(ExtList now, int i) {
		int num = RecursiveSearch.checkTarget(now);
	//	System.out.println("num "+num);
	//	if(num>0) {
			String keepyet = yet;
			if(yet.contains("h"+String.valueOf(i)))
				s = yet.split("h"+String.valueOf(i))[0]; //[h1,h1]どうするか
//			else if(yet.contains("s"+String.valueOf(i)))
//				s = yet.split("s"+String.valueOf(i))[0];
//			else if(yet.contains("v"+String.valueOf(i)))
//				s = yet.split("v"+String.valueOf(i))[0];
//			else if(yet.contains("o"+String.valueOf(i)))
//				s = yet.split("o"+String.valueOf(i))[0];
			//i==0
			if(i==0) {
				if(yet.contains("h"+String.valueOf(i)))
					yet = yet.split("h"+String.valueOf(i))[1];
//				else if(yet.contains("s"+String.valueOf(i)))
//					yet = yet.split("s"+String.valueOf(i))[1];
//				else if(yet.contains("v"+String.valueOf(i)))
//					yet = yet.split("v"+String.valueOf(i))[1];
//				else if(yet.contains("o"+String.valueOf(i)))
//					yet = yet.split("o"+String.valueOf(i))[1];
				ssqlgenerate +=s;
	//			System .out.println(""+now.get(0));

	//			if(eflg==true) {
			//		ssqlgenerate += "\'" + now.get(1) +  "\'";)
					writeTarget(now);
					ssqlfrom += "\"#" + now.get(0) + "\" c" + i + "_" + intlist[i];
	//				eflg = false;
	//			}else {
	//				ssqlgenerate += RecursiveSearch.closelist[i] + " \'" + now.get(1) + "\'";
	//			}

				if(1<Start_Parse.hopCount) {
					if(num>0) {
	//				eflg = true;
					sflg = true;
						for(int j=3; j<now.size();j++) {
							if(now.get(j) instanceof ExtList)
								makeGenerate(now.getExtList(j), i+1);
						}
						ssqlgenerate += "]" + RecursiveSearch.closelist[0][i]+ RecursiveSearch.closelist[1][i];
						sflg = false;
					}
				}else if(Start_Parse.hopCount==0) {
					ssqlgenerate +=yet;
				}else if(Start_Parse.hopCount==1) {
					if(yet.contains("h1")) {
						s = yet.split("h1")[0];
						yet = yet.split("h1")[1];
//					}else if(yet.contains("s1")) {
//						s = yet.split("s1")[0];
//						yet = yet.split("s1")[1];
//					}else if(yet.contains("v1")) {
//						s = yet.split("v1")[0];
//						yet = yet.split("v1")[1];
					}
					if(num>0) {
						ssqlgenerate += s + "a(c" + i + "_" + intlist[i] + "." + "related" +",c" + i + "_" + intlist[i] + "." + "related)]" + RecursiveSearch.closelist[0][i+1]+ RecursiveSearch.closelist[1][i+1];
//						ssqlfrom += ", \"#" + now.get(0) + "\" c" + i + "_" + intlist[i];
						intlist[i]++;
					}
//					ssqlgenerate += "]" + RecursiveSearch.closelist[i];
				}
				ssqlgenerate += "]" + RecursiveSearch.closelist[0][i]+ RecursiveSearch.closelist[1][i];
			//i!=0
			}else{
				//子要素
				if(i<Start_Parse.hopCount-1) {
					if(yet.contains("h"+String.valueOf(i)))
						yet = yet.split("h"+String.valueOf(i))[1];//[0-9]*  ?
//					else if(yet.contains("s"+String.valueOf(i)))
//						yet = yet.split("s"+String.valueOf(i))[1];
//					else if(yet.contains("v"+String.valueOf(i)))
//						yet = yet.split("v"+String.valueOf(i))[1];
//					else if(yet.contains("o"+String.valueOf(i)))
//						yet = yet.split("o"+String.valueOf(i))[1];

//						ssqlgenerate +=yet.substring(0, yet.indexOf("h"));
//						yet = yet.split("h"+String.valueOf(i))[1];
					if(sflg == true) {
						ssqlgenerate +=s;
					}else if(sflg == false){
						ssqlgenerate +=getCE(s.substring(0,1));
					}

					writeTarget(now);
					//再帰
					if(num>0) {
		//			eflg = true;
					sflg = true;
						for(int j=3; j<now.size();j++) {
							if(now.get(j) instanceof ExtList)
								makeGenerate(now.getExtList(j), i+1);

						}
						ssqlgenerate += "]" + RecursiveSearch.closelist[0][i] + RecursiveSearch.closelist[1][i];
						sflg = false;
					}
				}else if(i==Start_Parse.hopCount-1) {
					if(yet.contains("h"+String.valueOf(i)))
						yet = yet.split("h"+String.valueOf(i))[1];//[0-9]*  ?
//					else if(yet.contains("s"+String.valueOf(i)))
//						yet = yet.split("s"+String.valueOf(i))[1];
//					else if(yet.contains("v"+String.valueOf(i)))
//						yet = yet.split("v"+String.valueOf(i))[1];
//					else if(yet.contains("o"+String.valueOf(i)))
//						yet = yet.split("o"+String.valueOf(i))[1];
//						ssqlgenerate +=yet.substring(0, yet.indexOf("h"));
//						yet = yet.split("h"+String.valueOf(i))[1];
					if(sflg == true) {
						ssqlgenerate +=s;
						sflg = false;
					}else if(sflg == false){
						ssqlgenerate +=getCE(s.substring(0,1));
					}
					//CSV
					writeTarget(now);
					if(num>0) {
						if(yet.contains("h"+String.valueOf(i))) {
							s = yet.split("h"+String.valueOf(i+1))[0];
							yet = yet.split("h"+String.valueOf(i))[1];//[0-9]*  ?
//						}else if(yet.contains("s"+String.valueOf(i))) {
//							s = yet.split("s"+String.valueOf(i+1))[0];
//							yet = yet.split("s"+String.valueOf(i))[1];
//						}else if(yet.contains("v"+String.valueOf(i))) {
//							s = yet.split("v"+String.valueOf(i+1))[0];
//							yet = yet.split("v"+String.valueOf(i))[1];
//						}else if(yet.contains("o"+String.valueOf(i))) {
//							s = yet.split("o"+String.valueOf(i+1))[0];
//							yet = yet.split("o"+String.valueOf(i))[1];
						}
//						s=yet.split("[svoh]"+String.valueOf(i+1))[0];
//						yet = yet.split("h"+String.valueOf(i+1))[1];
//						if(yet.contains("[svoh]")) {
//						yet = yet.split("[svoh][0-9]*")[1];
//						}
						ssqlgenerate +=s;
						ssqlgenerate += "a(c" + i + "_" + intlist[i] + "." + value +",c" + i + "_" + intlist[i] + "." + value +")]" + RecursiveSearch.closelist[0][i+1]+ RecursiveSearch.closelist[1][i+1];
					//	ssqlgenerate += "]" + RecursiveSearch.closelist[i];
						ssqlfrom += ", \"#" + now.get(0)+ "\" c" + i + "_" + intlist[i];
						intlist[i]++;
				//		eflg=true;
				//		yet = yet.substring(2,yet.length());
				//		ssqlgenerate += yet.substring(0,2);
						sflg = false;

					}else {
				//		ssqlgenerate += yet.substring(0,2);
					}
				}
			}
			yet = keepyet;
	//	}
	}

	public static String replaceH(String input) {
		String s = input;
		Pattern p = Pattern.compile("[svo][0-9]+");
		Matcher m = p.matcher(s);
		while (m.find()) {
			String matched = m.group();
//			System.out.println(matched);
			s = s.substring(0,s.indexOf(matched))+"h"+s.substring(s.indexOf(matched)+1,s.length());
		}
		return s;
	}

	public static void writeTarget(ExtList now) {
		if(((String) now.get(2)).matches("^http:.*|^https:.*")) {
			ssqlgenerate+="a('"+now.get(1)+"','"+now.get(2)+"')";
		}else {
			ssqlgenerate += "'" + now.get(1) + "'";
		}
		if(yet.matches("^@\\{.*\\}.*")) {
			ssqlgenerate+=yet.substring(0,yet.indexOf("}")+1);
			yet = yet.substring(yet.indexOf("}")+1,yet.length());
		}
	}

	public static String getCE(String s) {
		if(s.equals(",")) {
			return "!";
		}else {
			return ",";
		}
	}
}
