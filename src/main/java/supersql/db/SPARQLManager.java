package supersql.db;


import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

import org.apache.jena.query.Query;
import org.apache.jena.query.QueryExecution;
import org.apache.jena.query.QueryExecutionFactory;
import org.apache.jena.query.QueryFactory;
import org.apache.jena.query.ResultSet;
import org.apache.jena.query.ResultSetFormatter;

import supersql.common.GlobalEnv;
import supersql.parser.Start_Parse;



public class SPARQLManager {

	public static void GetResult(String input) {
		if (input.startsWith("\'{") && input.endsWith("}\'")) {
            input = input.substring(2, input.length() - 2);
		}
		GetCSV(input);
		try {
	//		if(GlobalEnv.RecursiveSearchFlag){
				CsvRegister.copytoDB("sparqlresult"+GlobalEnv.outputcsvNum+"_"+GlobalEnv.outputcsvNum);
	//		}else {
	//			CsvRegister.copytoDB("sparqlresult"+GlobalEnv.outputcsvNum);
	//		}
		} catch (Exception e) {
			e.printStackTrace();
		}
		GlobalEnv.setRecursiveSearchFlag(1);
//	    GlobalEnv.outputcsvnum ++;
	}


	public static void GetCSV(String input) {
    // クエリを投げるSPARQLエンドポイント
    String service = GlobalEnv.getendpoint();
//		  String service = "https://dbpedia.org/sparql";
//		String service = "https://query.wikidataja.org/sparql";
    // SPARQLクエリ
    String queryString =
    		"PREFIX dbo: <http://dbpedia.org/ontology/>"
    		+"PREFIX dbp: <http://dbpedia.org/resource/>"
    		+"PREFIX dbpj: <http://ja.dbpedia.org/resource/>"
    		+"PREFIX rdfs: <http://www.w3.org/2000/01/rdf-schema#>"
    		+"PREFIX dbp-prop: <http://dbpedia.org/property/>"
    		+"PREFIX prop-ja: <http://ja.dbpedia.org/property/>"
            +"PREFIX geo: <http://www.w3.org/2003/01/geo/wgs84_pos#>"
        	+"PREFIX dbp-owl: <http://dbpedia.org/ontology/>"
            +"PREFIX dbpj-prop: <http://ja.dbpedia.org/property/>"
    		+input;
    //       +"SELECT (COUNT(*) AS ?count) WHERE { ?s ?p ?o .}";
    System.out.println("\n--SPARQL Query is--");
    System.out.println(queryString);
    Query query = QueryFactory.create(queryString);
    QueryExecution qe = QueryExecutionFactory.sparqlService(service, query);
    ResultSet results = qe.execSelect();

    try {
    //	if(GlobalEnv.recursiveSearchFlag>0) {
    		FileOutputStream fo = new FileOutputStream(new File(GlobalEnv.getfileparent() + "/sparqlresult"+GlobalEnv.outputcsvNum+"_"+GlobalEnv.outputcsvNum+".csv"));
    		ResultSetFormatter.outputAsCSV(fo,results);
    		fo.close();
    //	}else {
    //		FileOutputStream fo = new FileOutputStream(new File(GlobalEnv.getfileparent() + "/sparqlresult"+GlobalEnv.outputcsvNum+".csv"));
    //		ResultSetFormatter.outputAsCSV(fo,results);
    //		fo.close();
    //	}
	} catch (FileNotFoundException e) {
		e.printStackTrace();
	} catch (IOException e) {
		e.printStackTrace();
	}
    qe.close();
    if(Start_Parse.originflg == true) {
		String s = input.substring(input.indexOf("{")+1,input.indexOf("}"));
		if(s.split(" ")[0].contains(":")) {
			Start_Parse.origin_s = s.split(" ")[0].split(":")[1];
		}else {
			Start_Parse.origin_s = s.split(" ")[0];
		}
		if(s.split(" ")[1].contains(":")) {
			Start_Parse.origin_v = s.split(" ")[1].split(":")[1];
		}else {
			Start_Parse.origin_v = s.split(" ")[1];
		}
		if(s.split(" ")[2].contains(":")) {
			Start_Parse.origin_o = s.split(" ")[2].split(":")[1];
		}else {
			Start_Parse.origin_o = s.split(" ")[2];
		}
		Start_Parse.originflg = false;
	}
    }

	public static String checkPrefix(String input) {
		if(input.split(":")[0].toLowerCase().equals("dbpj")) {
			return "http://ja.dbpedia.org/resource/"+input.split(":")[1];
		}else if(input.split(":")[0].toLowerCase().equals("prop-ja")) {
			return "http://ja.dbpedia.org/property/"+input.split(":")[1];
		}else if(input.split(":")[0].toLowerCase().equals("dbp")) {
			return "https://dbpedia.org/resource/"+input.split(":")[1];
		}else {
			return input;
		}
	}
}