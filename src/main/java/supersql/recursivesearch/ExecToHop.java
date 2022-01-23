package supersql.recursivesearch;

import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

import supersql.codegenerator.CodeGenerator;
import supersql.codegenerator.Responsive.Responsive;
import supersql.common.GlobalEnv;
import supersql.common.Log;
import supersql.common.LogError;
import supersql.common.LogInfo;
import supersql.common.Ssedit;
import supersql.dataconstructor.DataConstructor;
import supersql.parser.Start_Parse;

public class ExecToHop {
	public static Start_Parse recursive_parser;

	public static void ExecToHop() {
		execRecursive(RecursiveMakeSSBasket.MakeRecursiveSSBasketQuery());
		RecursiveSearchPanel.newPanel("SSBasket");
	}
//	public static void ExecChildren(ArrayList<String> selection) {
//		RecursiveSearch.RecursiveSearch(selection.toArray(), Start_Parse.recursiveSPARQLQuery);
//	}
	public static void execRecursive(String ssqlquery) {
		String[] exec = new String[4];
		String file = new String();
		try {
			if(GlobalEnv.getfilename().substring(0,GlobalEnv.getfilename().indexOf(".ss")).matches(".*(_sparqlresult[0-9]+)$")){
				file = GlobalEnv.getfilename().substring(0,GlobalEnv.getfilename().indexOf("_sparqlresult")+13) + String.valueOf(Start_Parse.renum)+".ssb";
			}else {
			file = GlobalEnv.getfilename().substring(0,GlobalEnv.getfilename().indexOf(".ssb")) + "_sparqlresult"+String.valueOf(Start_Parse.renum)+".ssb";
			}
			Start_Parse.renum++;
			FileWriter fw = new FileWriter(file);
			PrintWriter pw = new PrintWriter(fw);
			pw.println(ssqlquery);
			System.out.println("\n");
			pw.close();
			fw.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		exec[0] = "-f";
		exec[1] = file;
//		exec[2] = "-singlequery";
		exec[2] = "-sep";
		exec[3] = GlobalEnv.getendpoint();
		execSSQL(exec);
	}

	public static void execSSQL(String[] args) {
			//再帰SSBasketクエリ実行
//				StringBuffer sb = new StringBuffer();
//				sb.append(ssqlquery);
		GlobalEnv.setGlobalEnv(args);
		GlobalEnv.getErrFlag();
//		if(GlobalEnv.versionProcess())	return;

		recursive_parser = new Start_Parse();
		if (GlobalEnv.isCheckquery()){
			if (GlobalEnv.getErrFlag() == 0)
				Log.info("// Parser completed normally //");
			return;
				}
	//			Log.info("2");

	//			afterparser = System.currentTimeMillis();
	//			afterdc = 0;
	//			aftercg = 0;
	//			aftersql = 0;

		if (GlobalEnv.getErrFlag() == 0) {
	//		Log.info("2-1");
			CodeGenerator codegenerator2 = recursive_parser.getcodegenerator();
	//		Log.info("2-2");
			if (GlobalEnv.getErrFlag() == 0) {
	//			Log.info("2-2-1");
				codegenerator2.CodeGenerator(recursive_parser);
	//			Log.info("2-2-2");
	//			GlobalEnv.beforedc = System.currentTimeMillis();
				DataConstructor dc2 = new DataConstructor(recursive_parser);
	//			GlobalEnv.afterdc2 = System.currentTimeMillis();
	//			Log.info("MakeSch time : " + (GlobalEnv.afterMakeSch - GlobalEnv.beforedc) + "ms");
	//			Log.info("MakeSQL time : " + (GlobalEnv.afterMakeSQL - GlobalEnv.beforeMakeSQL) + "ms");
	//			Log.info("GetFromDB time : " + (GlobalEnv.afterGetFromDB - GlobalEnv.beforeGetFromDB) + "ms");
	//			Log.info("MakeTree time : " + (GlobalEnv.afterMakeTree - GlobalEnv.beforeMakeTree) + "ms");
	//			Log.info("DataConstruct Time : " + (GlobalEnv.afterdc2 - GlobalEnv.beforedc) + "ms");
	//			System.exit(0);
	//			Log.info("2-2-3");
				if (GlobalEnv.getErrFlag() == 0) {
	//				Log.info("2-2-3-1");
					codegenerator2.generateCode(recursive_parser, dc2.getData());
	//				Log.info("2-2-3-2");
					Responsive.process(codegenerator2, recursive_parser, dc2.getData());	//added by goto 20161217  for responsive
	//				Log.info("2-2-3-3");
	//				aftercg = System.currentTimeMillis();
				}
			}
	//		Log.info("2-3");

//			Log.info("2-3");
		}
	//	Log.info("3");

	//	long end = System.currentTimeMillis();
	//	Log.info("Parsing Time : " + (afterparser - start) + "msec");
	//	Log.info("Data construction Time : "+ (afterdc - afterparser) + "msec");
	//	Log.info("Code generation Time : " + (aftercg - afterdc) + "msec");
	//	Log.info("ExecTime: " + (end - start) + "msec");

		GlobalEnv.queryInfo += GlobalEnv.getusername() + " | " + GlobalEnv.queryName +  " | ";
		if (GlobalEnv.getErrFlag() == 0){
			Ssedit.sseditInfo();
			Log.info("// completed normally //");
			LogInfo.logInfo(true);
		} else {
			LogError.logErr();
			if (GlobalEnv.isSsedit_autocorrect()) {
				Ssedit.sseditInfo();
			}
		}

	}
}
