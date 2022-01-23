package supersql.recursivesearch;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;

import org.apache.jena.query.Query;
import org.apache.jena.query.QueryExecution;
import org.apache.jena.query.QueryExecutionFactory;
import org.apache.jena.query.QueryFactory;
import org.apache.jena.query.ResultSet;
import org.apache.jena.query.ResultSetFormatter;

import supersql.common.GlobalEnv;
import supersql.db.SPARQLManager;
import supersql.extendclass.ExtList;
import supersql.parser.Start_Parse;

public class RecursiveSearch_old {

//	public static ArrayList<String> intermediate_file = new ArrayList<String>();

//	public static ArrayList<String> origin = new ArrayList<String>();
//	public static boolean originflag = true;
	public static ExtList recursivefiletree;

	public static String nowparent = new String();
	public static int[] intnowlist;
	public static int[] intcountlist;
	public static String[][] closelist;

	public static void RecursiveSearch() {
		recursivefiletree = new ExtList();
		intnowlist = new int[Start_Parse.hopCount+2];
		intcountlist = new int[Start_Parse.hopCount+2];
		closelist = new String[2][Start_Parse.hopCount+1];
		ArrayList<String> selection = new ArrayList<String>();
		if(Start_Parse.hopFlg==0) {
			for(int i=0;i<intnowlist.length;i++) {
				intnowlist[i]=0;
				intcountlist[i]=0;
			}
			splitClose();
			String filename = "sparqlresult"+String.valueOf(GlobalEnv.getRecursiveNum()-1) + "_" + intnowlist[GlobalEnv.getRecursiveNum()-1] + ".csv";
			nowparent = filename;System .out .println ("first "+filename);
			recursivefiletree.add(filename);
//			Start_Parse.recursivetitletree.add(filename);
			addOrigin();
			selection = MakePanelList(filename);
			RecursiveSearch_old.RecursiveSearch2(selection);
		}else if(Start_Parse.hopFlg==1) {
			recursivefiletree = Start_Parse.beforerecursivetitletree;
			for(int i=0;i<intnowlist.length;i++) {
				intnowlist[i]=0;
				if(i<Start_Parse.beforeintcountlist.length) {
					intcountlist[i]=Start_Parse.beforeintcountlist[i];
				}else {
					intcountlist[i]=0;
				}
			}
			int n = GlobalEnv.getRecursiveNum()-1;
			for(int i=0;i<Start_Parse.beforeintcountlist[n];i++) {
				GlobalEnv.setRecursiveNum(n+1);
				String filename = "sparqlresult"+ n + "_" + intnowlist[n] + ".csv";
				nowparent = filename;System .out .println ("first "+filename);
				splitClose();
				addOrigin();
				selection = MakePanelList(filename);
				RecursiveSearch_old.RecursiveSearch2(selection);
			}
		}
		ExecToHop.ExecToHop();
	//	RecursiveSearchPanel.newPanel("RecursiveSearch", selection);
	}

	public static void CheckHop(String input) {
//		System.out.println("filenamename "+filename);4_4
		GlobalEnv.plusRecursiveNum();//5_4
//		System.out.println("before "+GlobalEnv.getRecursiveNum()+"_"+GlobalEnv.getRecursiveSPARQLNum()); //2.1
		if(GlobalEnv.getRecursiveNum() > Start_Parse.hopCount) {
			intnowlist[GlobalEnv.getRecursiveNum()-1] = GlobalEnv.getRecursiveSPARQLNum();//4
		//	intcountlist[GlobalEnv.getRecursiveNum()-1] = GlobalEnv.getRecursiveSPARQLNum();
			GlobalEnv.setRecursiveNum(GlobalEnv.getRecursiveNum()-1);
		//	GlobalEnv.setRecursiveSPARQLNum(intcountlist[GlobalEnv.getRecursiveNum()]);
	//		nowparent = "sparqlresult"+ String.valueOf(GlobalEnv.getRecursiveNum()-1) + "_" + intnowlist[GlobalEnv.getRecursiveNum()-1] + ".csv";
	//	System.out.println("nowparent: "+nowparent);
		}else {
			String filename = input+".csv";
			nowparent = filename;
			GlobalEnv.setRecursiveSPARQLNum(intnowlist[GlobalEnv.getRecursiveNum()]);
			ArrayList<String> selection = MakePanelList(filename);
//			System.out.println("recursivesearch2 "+filename);
			RecursiveSearch2(selection);
		}
//		RecursiveSearchPanel.newPanel("RecursiveSearch", selection);
	}

//	public static void RecursiveSearch(Object[] inputs, String inputquery) {
//		if(inputs[0].equals("東京都、埼玉県、茨城県、神奈川県(（海上を隔て隣接）)")) {
//			inputs= new Object[]{"東京都", "埼玉県", "茨城県", "神奈川県"};
//		}
//		for(int i=0; i<inputs.length; i++) {
//			String filename = "sparqlresult"+GlobalEnv.getRecursiveNum() + "_" + GlobalEnv.getRecursiveSPARQLNum()+ ".csv";
//			makeChild(filename);
//			MakeRecursiveSPARQLQuery((String)inputs[i], inputquery, filename);
//		}
//		ExecToHop.ExecRecursiveSSQL(RecursiveMakeSSBasket.MakeRecursiveSSBasketQuery(origin));
//		GlobalEnv.setRecursiveSPARQLNum(intlist[GlobalEnv.getRecursiveNum()]);
//		GlobalEnv.plusRecursiveNum();
//	}

	public static void RecursiveSearch2(ArrayList<String> inputs) {
		int n = GlobalEnv.getRecursiveNum();
		String parent = nowparent;

		for(String s:inputs) {
			String filename = "sparqlresult"+GlobalEnv.getRecursiveNum() + "_" + intcountlist[GlobalEnv.getRecursiveNum()]+ ".csv";
//			System.out.println("\nrecursivesearch2 "+filename + " " + n +" "+nowparent);//
//			makeChild(filename);
//System.out.println(filename);
//			System.out.println(s);
			MakeRecursiveSPARQLQuery(s, Start_Parse.recursiveSPARQLQuery, filename);
		}
		intnowlist[GlobalEnv.getRecursiveNum()-1]++;
		if(GlobalEnv.getRecursiveNum()>1) {
			nowparent = "sparqlresult"+String.valueOf(GlobalEnv.getRecursiveNum()-2)+"_"+intnowlist[GlobalEnv.getRecursiveNum()-2]+".csv";
		}else {
			nowparent = "sparqlresult0_0.csv";
		}
		GlobalEnv.setRecursiveNum(GlobalEnv.getRecursiveNum()-1);
		GlobalEnv.setRecursiveSPARQLNum(intcountlist[GlobalEnv.getRecursiveNum()]);
		System.out.println("***********************************");
	}


	public static ArrayList<String> MakePanelList(String filename) {
//		System.out.println("tttt "+GlobalEnv.getfileparent() + "/" + filename);
		ArrayList<String> selection = new ArrayList<String>();
		FileInputStream fi = null;
		try {
			fi = new FileInputStream(new File(GlobalEnv.getfileparent()+ "/" +filename));
		} catch (FileNotFoundException e) {
			System.err.println(e.getMessage());
        }
		InputStreamReader is;
		try {
			is = new InputStreamReader(fi, "UTF-8");
		BufferedReader br = new BufferedReader(is);
		String line = br.readLine();
		line = br.readLine();

	//	line = br.readLine();
		while(line != null){
			String[] data = line.split("[\\s]*,[\\s]*");
			for(int i=0; i<data.length; i++) {
			//	System.out.println(data[i]);
				if(!data[i].equals("\"\"")) {
				selection.add(data[i]);
				}
			}
			line = br.readLine();
		}
		br.close();
		} catch (UnsupportedEncodingException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		if(selection.get(0).equals("東京都、埼玉県、茨城県、神奈川県(（海上を隔て隣接）)")) {
//			System.out.println(selection.get(0));
			selection.clear();
			selection.add("茨城県"); selection.add("埼玉県"); selection.add("東京都"); selection.add("神奈川県");
		}
		int n = intcountlist[GlobalEnv.getRecursiveNum()];
//		System.out.println("*"+selection.size()+"*");
		for(int i=0; i<selection.size(); i++) {
			String file = "sparqlresult"+GlobalEnv.getRecursiveNum() + "_" + n + ".csv";
//			System.out.println("makefilename " +file);
			makeChild(file);
//			System.out.println("makefilename " +file);
			n++;
		}
		return selection;
	}

	public static ArrayList<String> MakePanelList(String filename, String parent) {
		ArrayList<String> selection = new ArrayList<String>();
		try {
		BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(GlobalEnv.getfileparent() + "/" + filename), "UTF-8"));
		String line = br.readLine();
		line = br.readLine();

	//	line = br.readLine();
		while(line != null){
			String[] data = line.split("[\\s]*,[\\s]*");
			for(int i=0; i<data.length; i++) {
				//System.out.println(data[i]);
				selection.add(data[i]);
			//	RecursiveGenerator.MakeChild(data[i], filename, parent);
			}
			line = br.readLine();
		}
		br.close();
		} catch (UnsupportedEncodingException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return selection;
	}

	public static void MakeRecursiveSPARQLQuery(String input, String inputquery, String filename) {
		String s;
		//SPARQL結果がURL仕様の際、単語のみにして扱う
		if((input.contains("http")) || (input.equals("https"))){
			String[] splits = input.split("[\\s]*/[\\s]*");
			s = splits[splits.length-1];
			addTitle(recursivefiletree, filename, s, input);
		}else {
			s = input;
			addTitle(recursivefiletree, filename, input, input);
		}
		if(s!=null) {
//		if(originflag) {
//			System.out.println("origin add "+s+" "+GlobalEnv.getRecursiveNum());
//			origin.add(s);
		//	originflag=false;
		}
//		System.out.println("S:  "+s +" "+filename);
		String selectwhere = inputquery.replace("<input>", s);
//		System.out.println(selectwhere);
		String service = "http://ja.dbpedia.org/sparql";
		String queryString =
	    		"PREFIX dbp-owl: <http://ja.dbpedia.org/ontology/>"
	    		+"PREFIX dbpj: <http://ja.dbpedia.org/resource/>"
	    		+"PREFIX rdfs: <http://www.w3.org/2000/01/rdf-schema#>"
	    		+"PREFIX dbpj-prop: <http://dbpedia.org/property/>"
	    		+"PREFIX prop-ja: <http://ja.dbpedia.org/property/>"
	            +"PREFIX geo: <http://www.w3.org/2003/01/geo/wgs84_pos#>"
	    		+selectwhere;

		Query query = QueryFactory.create(queryString);
	    QueryExecution qe = QueryExecutionFactory.sparqlService(service, query);
	    ResultSet results = qe.execSelect();

	    try {
			FileOutputStream fo = new FileOutputStream(new File(GlobalEnv.getfileparent()+ "/" + filename));
			ResultSetFormatter.outputAsCSV(fo,results);
			fo.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	    qe.close();
	    GlobalEnv.plusRecursiveSPARQLNum();
//	    System.out.println("before"+GlobalEnv.getRecursiveNum()+" "+intcountlist[GlobalEnv.getRecursiveNum()]);
	    intcountlist[GlobalEnv.getRecursiveNum()]=GlobalEnv.getRecursiveSPARQLNum();
//	    System.out.println("after"+GlobalEnv.getRecursiveNum()+" "+intcountlist[GlobalEnv.getRecursiveNum()]);
	    //XMLOutput();
//	    System.out.println("checkhop "+"sparqlresult"+GlobalEnv.getRecursiveNum()+"_"+String.valueOf(intnowlist[GlobalEnv.getRecursiveNum()]));
	    CheckHop("sparqlresult"+GlobalEnv.getRecursiveNum()+"_"+String.valueOf(intnowlist[GlobalEnv.getRecursiveNum()]));
	}

	public static void setRecursiveSPARQLQuery(String input) {
		Start_Parse.recursiveSPARQLQuery = input;
	}

	public static void setRecursiveExpression(String input) {
		Start_Parse.recursiveExpression = input;
	}

	public static void setHopCount(int input) {
		Start_Parse.hopCount = input;
	}

	private static void makeChild(String filename) {
		ExtList child = new ExtList();
		child.add(filename);
		addChild(recursivefiletree, nowparent, child);
	}

	private static void addChild(ExtList tree, String target, ExtList child) {
		int num = tree.size();
//		System.out.println("target "+target+" child "+child);
		for (int i = 0; i < num; i++) {
			if(tree.get(i) instanceof String){
				if(tree.get(i).toString().equals(target)){
					System.out.println(child.get(0) +" add " +tree.get(0));
					tree.add(child);
				}
			}else if(tree.get(i) instanceof ExtList){
				ExtList list = tree.getExtList(i);
				addChild(list, target, child);
			}
		}
	}

	private static void addTitle(ExtList tree, String target, String title, String url) {
		int num = tree.size();
		for (int i = 0; i < num; i++) {
		//	if(i==1 || i==2) {
				//nothing to do
		//	}else {
			if(tree.get(i) instanceof String){
				if(tree.get(i).toString().equals(target)){
	////				System.out.println("title "+ title + "URL " + url + " add " +tree.get(0));
					tree.add(title);
					tree.add(url);
	//				System.out.println(tree.getExtList());
				}
			}else if(tree.get(i) instanceof ExtList){
				ExtList list = tree.getExtList(i);
				addTitle(list, target, title, url);
			}
			}
		//}
	}

	public static void splitClose() {
		String input = Start_Parse.recursiveExpression;
		for(int i=0; i<Start_Parse.hopCount+1; i++) {
			int n = input.lastIndexOf("]");
			closelist[0][i] = input.substring(n+1,n+2);
			if(input.length()>n+1)
				closelist[1][i] = input.substring(n+2,input.length());
			else
				closelist[1][i]="";
//			System.out.println(closelist[i]);
			input = input.substring(0,n);
		}
	}

	public static int checkTarget(ExtList tree) {
		int num = tree.size();
		int n = 0;
		for (int i = 0; i < num; i++) {
			if(tree.get(i) instanceof ExtList){
//				System.out.println("ddddd "+tree.get(i).toString());
				n++;
			}else{
			}
		}
		return n;
	}

	public static void addOrigin(){
		String input =  Start_Parse.recursiveExpression;
		if(input.contains("s0")){
//			Start_Parse.recursiveExpression = Start_Parse.recursiveExpression.replace("s0","h0");
			recursivefiletree.add(Start_Parse.origin_s);
			recursivefiletree.add(SPARQLManager.checkPrefix(Start_Parse.origin_s));
		}else if(input.contains("v0")){
//			Start_Parse.recursiveExpression = Start_Parse.recursiveExpression.replace("v0","h0");
				recursivefiletree.add(Start_Parse.origin_v);
				recursivefiletree.add(SPARQLManager.checkPrefix(Start_Parse.origin_v));
		}else if(input.contains("o0")){
//			Start_Parse.recursiveExpression = Start_Parse.recursiveExpression.replace("o0","h0");
				recursivefiletree.add(Start_Parse.origin_o);
				recursivefiletree.add(SPARQLManager.checkPrefix(Start_Parse.origin_o));
		}else {
			recursivefiletree.add("origin");
			recursivefiletree.add("origin");
		}
	}
}
