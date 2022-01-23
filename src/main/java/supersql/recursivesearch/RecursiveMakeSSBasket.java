package supersql.recursivesearch;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

import supersql.extendclass.ExtList;
import supersql.parser.Start_Parse;

public class RecursiveMakeSSBasket {
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
			return ssbasketquery;
	}

	public static void makeGenerateFrom() {
		ssqlgenerate = new String();
		ssqlfrom = new String();
		recursive_expression = Start_Parse.recursiveExpression;
		ssqlgenerate += "GENERATE HTML{\n";
		ssqlfrom +="FROM ";
		ExtList now = new ExtList();
		now = RecursiveSearch.recursivefiletree;
		s = recursive_expression;
		yet = recursive_expression;
		yet = replaceH(recursive_expression);
		s = yet;
		makeGenerate(RecursiveSearch.recursivefiletree, 0);
		ssqlgenerate +="}";
	}

	public static void makeGenerate(ExtList now, int i) {
		int num = RecursiveSearch.checkTarget(now);
			String keepyet = yet;
			if(yet.contains("h"+String.valueOf(i)))
				s = yet.split("h"+String.valueOf(i))[0]; //[h1,h1]どうするか
			if(i==0) {
				if(yet.contains("h"+String.valueOf(i)))
					yet = yet.split("h"+String.valueOf(i))[1];
				ssqlgenerate +=s;
					writeTarget(now);
					ssqlfrom += "\"#" + now.get(0) + "\" c" + i + "_" + intlist[i];
				if(1<Start_Parse.hopCount) {
					if(num>0) {
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
					}
					if(num>0) {
						ssqlgenerate += s + "a(c" + i + "_" + intlist[i] + "." + Start_Parse.hop0name[0] +",c" + i + "_" + intlist[i] + "." + Start_Parse.hop0name[0] + ")]" + RecursiveSearch.closelist[0][i+1]+ RecursiveSearch.closelist[1][i+1];
						intlist[i]++;
					}
				}
				ssqlgenerate += "]" + RecursiveSearch.closelist[0][i]+ RecursiveSearch.closelist[1][i];
			}else{
				//子要素
				if(i<Start_Parse.hopCount-1) {
					if(yet.contains("h"+String.valueOf(i)))
						yet = yet.split("h"+String.valueOf(i))[1];//[0-9]*  ?
					if(sflg == true) {
						ssqlgenerate +=s;
					}else if(sflg == false){
						ssqlgenerate +=getCE(s.substring(0,1));
					}

					writeTarget(now);
					//再帰
					if(num>0) {
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
						}
						ssqlgenerate +=s;
						ssqlgenerate += "a(c" + i + "_" + intlist[i] + "." + value +",c" + i + "_" + intlist[i] + "." + value +")]" + RecursiveSearch.closelist[0][i+1]+ RecursiveSearch.closelist[1][i+1];
						ssqlfrom += ", \"#" + now.get(0)+ "\" c" + i + "_" + intlist[i];
						intlist[i]++;
						sflg = false;

					}else {
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

