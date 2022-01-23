package supersql.recursivesearch;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
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

public class RecursiveSearch2 {

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
			nowparent = filename;
			//System .out .println ("first "+filename);
			recursivefiletree.add(filename);
			addOrigin();
			selection = MakePanelList(filename);
			RecursiveSearch.RecursiveSearch2(selection);
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
				nowparent = filename;
				//System .out .println ("first "+filename);
				splitClose();
				addOrigin();
				selection = MakePanelList(filename);
				RecursiveSearch.RecursiveSearch2(selection);
			}
		}
		ExecToHop.ExecToHop();
	}

	public static void CheckHop(String input) {
		GlobalEnv.plusRecursiveNum();//5_4
		if(GlobalEnv.getRecursiveNum() > Start_Parse.hopCount) {
			intnowlist[GlobalEnv.getRecursiveNum()-1] = GlobalEnv.getRecursiveSPARQLNum();//4
			GlobalEnv.setRecursiveNum(GlobalEnv.getRecursiveNum()-1);
		}else {
			String filename = input+".csv";
			nowparent = filename;
			GlobalEnv.setRecursiveSPARQLNum(intnowlist[GlobalEnv.getRecursiveNum()]);
			ArrayList<String> selection = MakePanelList(filename);
			RecursiveSearch2(selection);
		}
	}

	public static void RecursiveSearch2(ArrayList<String> inputs) {
		int n = GlobalEnv.getRecursiveNum();
		String parent = nowparent;
	//	if(inputs!=null) {
		for(String s:inputs) {
			String filename = "sparqlresult"+GlobalEnv.getRecursiveNum() + "_" + intcountlist[GlobalEnv.getRecursiveNum()]+ ".csv";
			MakeRecursiveSPARQLQuery(s, Start_Parse.recursiveSPARQLQuery, filename);
		}
	//	}
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

		while(line != null){
			String[] data = line.split("[\\s]*,[\\s]*");
			for(int i=0; i<data.length; i++) {
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
		//To Do nullだった時のデフォルト値を挿入 or エスケープして次の対象へ進む
		if(selection.size()>0) {
		if(selection.get(0).equals("東京都、埼玉県、茨城県、神奈川県(（海上を隔て隣接）)")) {
			selection.clear();
			selection.add("茨城県"); selection.add("埼玉県"); selection.add("東京都"); selection.add("神奈川県");
		}
		}
		int n = intcountlist[GlobalEnv.getRecursiveNum()];
		for(int i=0; i<selection.size(); i++) {
			String file = "sparqlresult"+GlobalEnv.getRecursiveNum() + "_" + n + ".csv";
			makeChild(file);
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
		while(line != null){
			String[] data = line.split("[\\s]*,[\\s]*");
			for(int i=0; i<data.length; i++) {
				selection.add(data[i]);
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
		}
		String selectwhere = inputquery.replace("<input>", s);
		String service = "http://ja.dbpedia.org/sparql";
		 // String service = "https://dbpedia.org/sparql";
		String queryString =
	    		"PREFIX dbo: <http://dbpedia.org/ontology/>"
	    		+"PREFIX dbp: <http://dbpedia.org/resource/>"
	    		+"PREFIX dbpj: <http://ja.dbpedia.org/resource/>"
	    		+"PREFIX rdfs: <http://www.w3.org/2000/01/rdf-schema#>"
	    		+"PREFIX dbp-prop: <http://dbpedia.org/property/>"
	    		+"PREFIX prop-ja: <http://ja.dbpedia.org/property/>"
	            +"PREFIX geo: <http://www.w3.org/2003/01/geo/wgs84_pos#>"
	    		+selectwhere;System.out.println(queryString);
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
	    intcountlist[GlobalEnv.getRecursiveNum()]=GlobalEnv.getRecursiveSPARQLNum();
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
			if(tree.get(i) instanceof String){
				if(tree.get(i).toString().equals(target)){
					 try {
							PrintWriter pw1 = new PrintWriter(new FileWriter(GlobalEnv.getfileparent()+ "/" + "title_url_"+Start_Parse.imediatecsvcount+".csv"));
							pw1.println("title,url\n"+title+","+url);
							pw1.close();
						//	PrintWriter pw2 = new PrintWriter(new FileWriter(GlobalEnv.getfileparent()+ "/" + "url_"+Start_Parse.imediatecsvcount+".csv"));
						//	pw2.println(url);
						//	pw2.close();
						} catch (FileNotFoundException e) {
							e.printStackTrace();
						} catch (IOException e) {
							e.printStackTrace();
						}
					tree.add("title_url_"+Start_Parse.imediatecsvcount);
					if(url.matches("^http:.*|^https:.*")) {
						tree.add("true");
					}else {
						tree.add("false");
					}
						Start_Parse.imediatecsvcount++;
				}
			}else if(tree.get(i) instanceof ExtList){
				ExtList list = tree.getExtList(i);
				addTitle(list, target, title, url);
			}
			}
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
			input = input.substring(0,n);
		}
	}

	public static int checkTarget(ExtList tree) {
		int num = tree.size();
		int n = 0;
		for (int i = 0; i < num; i++) {
			if(tree.get(i) instanceof ExtList){
				n++;
			}else{
			}
		}
		return n;
	}

	public static void addOrigin(){
		String input =  Start_Parse.recursiveExpression;
		String title = new String();
		String url = new String();
		if(input.contains("s0")){
			title = (Start_Parse.origin_s);
			url = (SPARQLManager.checkPrefix(Start_Parse.origin_s));
		}else if(input.contains("v0")){
				title = (Start_Parse.origin_v);
				url = (SPARQLManager.checkPrefix(Start_Parse.origin_v));
		}else if(input.contains("o0")){
				title = (Start_Parse.origin_o);
				url = (SPARQLManager.checkPrefix(Start_Parse.origin_o));
		}else {
			title = ("origin");
			url = ("origin");
		}
		try {
			PrintWriter pw1 = new PrintWriter(new FileWriter(GlobalEnv.getfileparent()+ "/" + "title_url_"+Start_Parse.imediatecsvcount+".csv"));
			pw1.println("title,url\n'"+title+"','"+url+"'");
			pw1.close();
		//	PrintWriter pw2 = new PrintWriter(new FileWriter(GlobalEnv.getfileparent()+ "/" + "url_"+Start_Parse.imediatecsvcount+".csv"));
		//	pw2.println(url);
		//	pw2.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		recursivefiletree.add("title_url_"+Start_Parse.imediatecsvcount);
	if(url.matches("^http:.*|^https:.*")) {
		recursivefiletree.add("true");
	}else {
		recursivefiletree.add("false");
	}
		Start_Parse.imediatecsvcount++;
	}
}
