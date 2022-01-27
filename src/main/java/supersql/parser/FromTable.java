package supersql.parser;

import supersql.common.GlobalEnv;
import supersql.db.SPARQLManager;

public class FromTable {
    private String alias;
    private String tableName;
    private String line;

    public FromTable(String name){
        name = name.trim();
        //CSVファイル名(属性名 型)
        if(name.contains("(")) {
        	//aliasがない場合
        	if(name.split("[\\s]*[)][\\s]*").length == 1){
        		//""で括られているか
        		if (name.startsWith("\"") && name.endsWith("\"")) {
                    name = name.substring(1, name.length() - 1);
                  //#があるか
                    if(name.contains("#")) {
                    	//拡張子があるか
                    	if(name.contains(".csv")) {    //add ayumi
                        	GlobalEnv.csvFlag = true;
                        	name = name.substring(1,name.indexOf("."))+name.substring(name.indexOf("("),name.length());
                        	tableName = name.substring(0,name.indexOf("."));
                        	alias = name.substring(1,name.indexOf("."));
                        	GlobalEnv.csvTable.put(alias, name);
                        	line = tableName + " " + alias;
                        //CSV(属性名 型)
                    	}else if(name.substring(0,3).equalsIgnoreCase("csv")) {
                        	GlobalEnv.csvFlag = true;
                        	tableName = GlobalEnv.getcsvtablename();
                        	alias = "c";
                        	name = tableName + name.substring(3,name.length());
                        	GlobalEnv.csvTable.put(alias, name);
                        	line = tableName + " " + alias;
                        //SPARQL(SPARQLクエリ)
                        }else if(name.substring(0,6).equalsIgnoreCase("sparql")) {
                        	String sparqlquery = name.substring(name.indexOf("(") + 1,name.length());
                        	SPARQLManager.GetResult(sparqlquery);
                        	tableName = "sparqlresult"+GlobalEnv.outputcsvNum;
            				alias = "sparqlresult"+GlobalEnv.outputcsvNum;
            				line = tableName + " " + alias;
                        	GlobalEnv.csvTable.put(alias, tableName);
                        	GlobalEnv.plusOutputCSVNumCount();
                        }
                    	//else{
                    	//	GlobalEnv.csvFlag =true;
                    	//	tableName = name.substring(1,tableName.indexOf("("));
                    	//	alias = name.substring(1,tableName.indexOf("("));
                    	//	line = tableName + " " + alias;
                    	//	GlobalEnv.csvTable.put(alias, name);
                    	//}
                    }else {
                    	tableName = name;
                    	alias = name;
                    	line = tableName + " " + alias;
                    }
        		}else {
                	tableName = name;
                	alias = name;
                	line = tableName + " " + alias;
        		}
            //aliasがある場合
        	}else{
      //  		tableName = name.split("[\\s]*[)][\\s]*")[0]+")\"";
        //        alias = name.split("[\\s]*[)][\\s]*")[1].substring(2,name.split("[\\s]*[)][\\s]*")[1].length());
        		tableName = name.substring(0,name.lastIndexOf(" "));
        		alias = name.substring(name.lastIndexOf(" ")+1,name.length());
        		line = tableName + " " + alias;
                if (alias.startsWith("\"") && alias.endsWith("\"")) {
                    alias = alias.substring(1, alias.length() - 1);
                }
                //""で括られているか
                if (tableName.startsWith("\"") && tableName.endsWith("\"")) {
                	tableName = tableName.substring(1, tableName.length() - 1);
                    //#があるか
                    if(tableName.contains("#")) {
                    	//拡張子があるか
                    	if(tableName.contains(".csv")) {    //add ayumi
                        	GlobalEnv.csvFlag =true;
                        	tableName = tableName.substring(1,tableName.indexOf("."))+tableName.substring(tableName.indexOf("("),tableName.length());
                        	GlobalEnv.csvTable.put(alias, tableName);
                        	tableName = tableName.substring(0,tableName.indexOf("("));
                        	line = tableName + " " + alias;
                        //CSV(属性名)
                    	} else if (tableName.substring(1,4).equalsIgnoreCase("csv")) {
                    	    GlobalEnv.csvFlag = true;
                    	    tableName = GlobalEnv.getcsvtablename() + tableName.substring(4,tableName.length());
                       	    line = GlobalEnv.getcsvtablename() + " c";
                    	    GlobalEnv.csvTable.put(alias, tableName);
                    	//SPARQL(SPARQLクエリ)
                    	}else if(tableName.substring(1,7).equalsIgnoreCase("sparql")) {
                    		String sparqlquery = tableName.substring(tableName.indexOf("(") + 1,tableName.lastIndexOf(")"));
//                    		System.out.println("sparqlquery: \n"+sparqlquery);
                        	SPARQLManager.GetResult(sparqlquery);
                        	tableName = "sparqlresult"+GlobalEnv.outputcsvNum+"_"+GlobalEnv.outputcsvNum;
            				line = tableName + " " + alias;
                        	GlobalEnv.csvTable.put(alias, tableName);
                        	GlobalEnv.plusOutputCSVNumCount();
                    	}
                    	//else {
                    	//	GlobalEnv.csvFlag =true;
                    	//	GlobalEnv.csvTable.put(alias, tableName);
                    	//	tableName = tableName.substring(1,tableName.indexOf("("));
                    	//	line = tableName + " " + alias;
                    	//}
                    }

                }
            }
        //CSVファイル名
        }else {
        	//aliasがない場合
        	if(name.split(" ").length == 1){
        		//""で括られているか
        		if (name.startsWith("\"") && name.endsWith("\"")) {
        			name = name.substring(1, name.length() - 1);
        			//#があるか
        			if(name.contains("#")){
        				//拡張子があるか
        				if(name.matches(".csv)")) {    //add ayumi
            				GlobalEnv.csvFlag = true;
            				tableName = name.substring(1,name.length() - 4);
            				alias = name.substring(1,name.length() - 4);
            				 if (alias.startsWith("\"") && alias.endsWith("\"")) {
            	                    alias = alias.substring(1, alias.length() - 1);
            	                }
            				line = tableName + " " + alias;
            				GlobalEnv.csvTable.put(alias, tableName);
            			//CSV
        				}else if(name.equalsIgnoreCase("#csv")) {
        		        	GlobalEnv.csvFlag = true;
        		        	tableName = GlobalEnv.getcsvtablename();
        		        	alias = "c";
        		        	line = tableName + " " + alias;
        		            GlobalEnv.csvTable.put(alias, tableName);
        				//SPARQL
        	//			}else if(name.equalsIgnoreCase("#sparql")) {
              //      		tableName = "sparqlresult"+GlobalEnv.outputcsvNum;
            	//			alias = "sparqlresult"+GlobalEnv.outputcsvNum;
            	//			line = tableName + " " + alias;
                  //      	GlobalEnv.csvTable.put(alias, tableName);
                    	}
        				//else{
        				//	GlobalEnv.csvFlag =true;
        				//	tableName = tableName.substring(1,tableName.length());
        				//	alias = alias.substring(1,tableName.length());
        				//	line = tableName + " " + alias;
        				//	GlobalEnv.csvTable.put(alias, tableName);
        				//}
        			}else {
        				tableName = name;
        				alias = name;
        			}
        		}else {
    				tableName = name;
    				alias = name;
    			}
        	//aliasがある場合
        	}else{
        		alias = name.split(" ")[1];
        		tableName = name.split(" ")[0];
        		line = tableName + " " + alias;
            	if (alias.startsWith("\"") && alias.endsWith("\"")) {
            		alias = alias.substring(1, alias.length() - 1);
            	}
            	//""で括られているか
            	if (tableName.startsWith("\"") && tableName.endsWith("\"")) {
            		tableName = tableName.substring(1, tableName.length() - 1);
            		//#があるか
            		if(tableName.contains("#")){
            			//拡張子があるか
            			if(tableName.contains(".csv")) {    //add ayumi
                			GlobalEnv.csvFlag =true;
                			tableName = tableName.substring(1,tableName.length() - 4);
                			line = tableName + " " + alias;
                			GlobalEnv.csvTable.put(alias, tableName);
                		//CSV
            			}else if (tableName.equalsIgnoreCase("#csv")) {
                    		GlobalEnv.csvFlag = true;
                    		tableName = GlobalEnv.getcsvtablename();
                    		alias = "c";
                    		line = GlobalEnv.getcsvtablename() + " c";
                    		GlobalEnv.csvTable.put(alias, tableName);
                    	//SPARQL
            	//		}else if(tableName.equalsIgnoreCase("#sparql")) {
                  //      	tableName = "sparqlresult"+GlobalEnv.outputcsvNum;
                    //    	alias = "sparqlresult"+GlobalEnv.outputcsvNum;
                	//		line = tableName + " " + alias;
                	//		GlobalEnv.csvTable.put(alias, tableName);
                		}
            			//else {
                		//	GlobalEnv.csvFlag =true;
                		//	tableName = tableName.substring(1,tableName.length());
                		//	line = tableName + " " + alias;
                		//	GlobalEnv.csvTable.put(alias, tableName);
                		//}
            		}
            	}
        	}
        }
    }

    public String getAlias() {
        return alias;
    }

    public String getTableName() {
        return tableName;
    }

    public String getLine() {
        return line;
    }

    @Override
    public String toString() {
        return "FromTable{" +
                "alias='" + alias + '\'' +
                ", tableName='" + tableName + '\'' +
                ", line='" + line + '\'' +
                '}';
    }
}
