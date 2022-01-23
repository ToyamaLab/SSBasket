package supersql.parser;


import java.io.Serializable;
import java.util.Hashtable;
import java.util.StringTokenizer;

import supersql.common.Log;

public class FromInfo implements Serializable {

	private String line;

	private Hashtable from_table;


	public FromInfo(String line) {
		this.line = line;
		this.from_table = new Hashtable();
//		this.makeInfo(line);
		if(line.split(" ")[0].equalsIgnoreCase("sparql")){
			Start_Parse.setSparqlQuery(true); //add ayumi
		}else if(line.split(" ")[0].equalsIgnoreCase("dbpedia")){
			Start_Parse.setDbpediaQuery(true);
		}else if(line.split(" ")[0].toLowerCase().startsWith("api")){
			Start_Parse.setJsonQuery(true);
		}
		Log.out("FromInfo [line] : " + line);
	}

	public void makeInfo(String line) {
		Start_Parse.set_from_info_st(line);
		if(line.equalsIgnoreCase("sparql")){
			Start_Parse.setSparqlQuery(true); //add ayumi
		}else if(line.equalsIgnoreCase("dbpedia")){
			Start_Parse.setDbpediaQuery(true);
		}else if(line.toLowerCase().startsWith("api")){
			Start_Parse.setJsonQuery(true);
		}else {
	//		try {
	//			CsvRegister.copytoDB();
	//		} catch (Exception e) {
	//			System.err.println("CSV load error");
	//		}
			StringTokenizer st = new StringTokenizer(line, ",");
			while (st.hasMoreTokens()) {
				String ch = st.nextToken().trim();
//				Log.out("ch : " + ch);
				String decos = new String();
				if(ch.contains("@")){
					decos = addDeco(ch.substring(ch.indexOf("@")+1));
					ch = ch.substring(0,ch.indexOf("@"));
					FromParse fp = new FromParse(ch);
					from_table.put(fp.alias, fp);
//				} else if(ch.equalsIgnoreCase(".csv")) {
//					System.out.println("csv on");
//					GlobalEnv.csvFlag = true; //add ayumi
//					if(GlobalEnv.getcsvtablename()!=null) {
//						String[] csvtables = GlobalEnv.getcsvtablename().split("[\\s]*,[\\s]*");
//						for(int i=0; i<csvtables.length;i++) {
//							if(ch.substring(0, ch.length()-4).equals(csvtables[i])) {
//								try {
//									CsvRegister.copytoDB(csvtables[i]);
//								} catch (SQLException e) {
//									System.err.println("CSV load SQL error");
//								} catch (IOException e){
//									System.err.println("CSV load IO error");
//								} catch (Exception e) {
//									System.err.println("CSV load error");
//								}
//								FromParse fp = new FromParse(ch.substring(0, ch.length()-4));
//								from_table.put(fp.alias, csvtables[i]);
//								break;
//							}
//						}
//					}else{
//						for(String key: GlobalEnv.csvTable.keySet()) {
//							 if(ch.substring(0, ch.length()-4).equals(From.getFromTable(key).getTableName())) {
//								 try {
//										CsvRegister.copytoDB(ch.substring(0, ch.length()-4));
//									} catch (SQLException e) {
//										System.err.println("CSV load SQL error");
//									} catch (IOException e){
//										System.err.println("CSV load IO error");
//									} catch (Exception e) {
//										System.err.println("CSV load error");
//									}
//								    FromParse fp = new FromParse(ch.substring(0, ch.length()-4));
//									from_table.put(fp.alias, ch.substring(0, ch.length()-4));
//									break;
//							 }
//						}
//					}
//				}else if(ch.equalsIgnoreCase("csv")) {
//					System.out.println("csv on");
//					GlobalEnv.csvFlag = true; //add ayumi
			//	Start_Parse.setCsvQuery(true);
//				try {
//					CsvRegister.copytoDB(GlobalEnv.getcsvtablename());
//				} catch (Exception e) {
//					System.err.println("CSV load error");
//				}
//				FromParse fp = new FromParse(ch);
//				from_table.put(fp.alias, GlobalEnv.getcsvtablename());

			}else {
				FromParse fp = new FromParse(ch);
				from_table.put(fp.alias, fp);
			}
				if(decos!= "" && decos.equalsIgnoreCase("update")){
					Start_Parse.set_from_info_st(ch);
				}

			}
		}
	}

	private String addDeco(String st){
//		Log.out("@from decoration found@");
		TFEtokenizer toks = new TFEtokenizer(st);
		String token = new String();
		int equalidx;
		String name = new String();
		String value = new String();
		String decos = new String();
		while(toks.hasMoreTokens()){
			token = toks.nextToken();
            Log.out("decoration*looktoken=" + token);
			if (token.equals("}")) {
                break;
            }
			if (token.equals("{")) {
                continue;
            }
			equalidx = token.indexOf('=');
            if (equalidx != -1) {
            //    key = idx
                name = token.substring(0, equalidx);
                value = token.substring(equalidx + 1);
                while (toks.hasMoreTokens()) {
                    token = toks.lookToken();
//                    Log.out("decoration*looktoken=" + token);
                    if (token.equals(",") || token.equals("}")) {
                        break;
                    }
                    value = value.concat(toks.nextToken());
                }
        		decos = value;
            } else {
            //    key only
            	while(toks.hasMoreTokens()){
            		name += token;
            		token = toks.nextToken();
            		if(token.equals(",") || token.equals("}")){
            			break;
            		}
            	}
//            	Log.out(name);
        		decos = name;
            }
            if (token.equals("}")) {
                // end of decoration
                break;
            }
            if (!token.equals(",")) {
            //    not close in "}"
                System.err
                        .println("*** Found Illegal Token after Decoration value ***");
                throw (new IllegalStateException());
            }
        }
//        Log.out("@ from decoration end @");
        return decos;
	}

	@Override
	public String toString() {
		return "{ line : " + line + ", from_table : " + from_table + " }";
	}

	public String getLine() {
		return line;
	}

	public Hashtable getFromTable() {
		return from_table;
	}

	public String getOrigTable (String alias) {
		return ((FromParse)from_table.get(alias)).getRealName();
	}

}
