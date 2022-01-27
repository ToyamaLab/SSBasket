package supersql.db;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

import supersql.common.GlobalEnv;
import supersql.common.Log;
import supersql.extendclass.ExtList;
import supersql.parser.Start_Parse;

public class SQLiteRegister {
	static String nowtable;
	static String nowfile = new String();
	static String file_names[];
	static String col_n[];
	static String col_t[];

	public static void copytoDB(String input) throws Exception {
//		System.out.println("sqlite register");
		Connection conn;
		GlobalEnv.setDefaultdb(GlobalEnv.getdbname());
		GlobalEnv.setDefaultdriver(GlobalEnv.getDriverName());
		GlobalEnv.setdb(GlobalEnv.getSQLitedb());
		GlobalEnv.setdriver("sqlite3");
//		System.out.println("Defaultdb: "+GlobalEnv.getDefaultdb());
//		System.out.println("Defaultdriver: "+GlobalEnv.getDefaultdriver());

		String parent = GlobalEnv.getfileparent();
		String hostname = GlobalEnv.gethost();
		String port = GlobalEnv.getport();
		String dbname = GlobalEnv.getdbname();
		String user = GlobalEnv.getusername();
		String driver = GlobalEnv.getDriver();
		String dbms = GlobalEnv.getdbms();
		String url = GlobalEnv.geturl();
				//"jdbc:sqlite:"+GlobalEnv.getSQLitedb();
				//System.out.println(url);
		String password = GlobalEnv.getpassword();

		conn = DriverManager.getConnection(url);
		long result = 0;
		nowtable = input;
		nowfile = null;

		if(nowtable.contains(")")) {
			String col[] = nowtable.substring(nowtable.indexOf("(")+1,nowtable.length()).split("[\\s]*,[\\s]");
			col_n = new String[col.length];
			col_t = new String[col.length];
			for(int i=0; i<col.length; i++) {
				col_n[i]=col[i].split(" ")[0];
				col_t[i]=col[i].split(" ")[1];
			}
			nowtable = nowtable.substring(0,nowtable.indexOf("("));
		}

		if(GlobalEnv.getcsvfilename() != null) {
			file_names = GlobalEnv.getcsvfilename().split("[\\s]*,[\\s]*"); // 入力ファイル
			for(int i=0;i<file_names.length;i++) {
				String s[] = file_names[i].split("/");
				if(s[s.length-1].substring(0,((s[s.length-1].length())-4)).equalsIgnoreCase(nowtable)) {
					nowfile = file_names[i];
					//break;
				}
			}
			if(nowfile == null) {
				nowfile = GlobalEnv.getfileparent() + "/" + nowtable + ".csv";
			}
		}

		if(nowfile == null) {
			nowfile = GlobalEnv.getfileparent() + "/" + nowtable + ".csv";
		}
		if(Start_Parse.addcsvmode == true) {
			resetTable(conn);
			createTable(conn);
			Start_Parse.addedcsv.add(nowtable);
			insertCSVtoOtherDB(conn);
		}else {
			if(!Start_Parse.addedcsv.contains(nowtable)) {
				resetTable(conn);
				createTable(conn);
				Start_Parse.addedcsv.add(nowtable);
				insertCSVtoOtherDB(conn);
			}
		}

		try{
			if(conn != null) conn.close();
		}catch(SQLException exception) {
			System.err.println(exception);
		}

	}

	public static void createTable(Connection conn) {
		if(GlobalEnv.getcsvcolumntype()!=null) {
			Statement stmt;
			try {
				stmt = conn.createStatement();

				String column_types[] = GlobalEnv.getcsvcolumntype().split("[\\s]*,[\\s]*");
				StringBuilder sql = new StringBuilder();

				//テーブル作成
				sql.append("CREATE TABLE "+nowtable+"(");

				BufferedReader br = null;
				String file_name = nowtable;
				try {
					File file = new File(file_name);
					br = new BufferedReader(new FileReader(file));
					String line;
					String[] data;
					line = br.readLine();
					data = line.split("[\\s]*,[\\s]*");
					if(data.length==column_types.length) {
						for (int j = 0; j < data.length; j++) {
							if((column_types[j].equalsIgnoreCase("int")) || (column_types[j].equalsIgnoreCase("integer"))){
								sql.append(data[j]+" INTEGER");
							}else if((column_types[j].equalsIgnoreCase("float")) || (column_types[j].equalsIgnoreCase("decimal*"))){
								sql.append(data[j]+" REAL");
							}else if((column_types[j].equals("varchar"))|| (column_types[j].equals("char"))
//									|| (column_types[j].equalsIgnoreCase("varchar("+"[0-9]*"+")"))
//									|| (column_types[j].equalsIgnoreCase("char("+"[0-9]*"+")"))
									|| (column_types[j].equals("datetime"))){
								sql.append(data[j]+" TEXT");
							}else {
								sql.append(data[j]+" TEXT");
							}

							if(j<data.length-1) {
								sql.append(", ");
							}
						}
						sql.append(");");
	//					System.out.println(sql.toString());
						stmt.executeUpdate(sql.toString());
						sql.delete(0, sql.length());
						}
				} catch (IOException e) {
					System.err.println(e.getMessage());
				} finally {
					try {
						br.close();
					} catch (Exception e) {
						System.err.println(e.getMessage());
					}
				}
				stmt.close();
			} catch (SQLException e) {
				System.err.println(e.getMessage());
			}
		}
	}

	public static void createTable(Connection conn, String tableName, String[] column_names, String[] column_types) {
		nowtable = tableName;
		createTable(conn, column_names, column_types);
	}

	public static void createTable(Connection conn, String[] column_names, String[] column_types) {
			Statement stmt;
			try {
				stmt = conn.createStatement();
				StringBuilder sql = new StringBuilder();

			//テーブル作成
				sql.append("CREATE TABLE "+nowtable+"(");
				if(column_names.length==column_types.length) {
					for (int i = 0; i < column_names.length; i++) {

						if((column_types[i].equalsIgnoreCase("int")) || (column_types[i].equalsIgnoreCase("integer")
								|| (column_types[i].contains("int")))){
							column_types[i] = "INTEGER";
							sql.append(column_names[i]+" INTEGER");
						}else if((column_types[i].equalsIgnoreCase("float")) || (column_types[i].equalsIgnoreCase("decimal*"))){
							column_types[i] = "REAL";
							sql.append(column_names[i]+" REAL");
						}else if(((column_types[i].equals("varchar"))) || ((column_types[i].equals("char")))
					//			|| (column_types[i].equalsIgnoreCase("varchar("+"[0-9]*"+")"))
					//			|| (column_types[i].equalsIgnoreCase("char("+"[0-9]*"+")"))
								|| (column_types[i].equals("datetime"))){
							column_types[i] = "TEXT";
							sql.append(column_names[i]+" TEXT");
						}else {
							column_types[i] = "TEXT";
							sql.append(column_names[i]+" TEXT");
						}

						if(i<column_names.length-1) {
							sql.append(", ");
						}
					}
					sql.append(");");
	//				System.out.println(sql.toString());
					stmt.executeUpdate(sql.toString());
					sql.delete(0, sql.length());
					col_n = column_names;
					col_t = column_types;
				}
				stmt.close();
				} catch (SQLException e) {
					System.err.println(e.getMessage());
				}
	}

	public static void resetTable(Connection conn) {
		Statement stmt;
		try {
			stmt = conn.createStatement();
			StringBuilder sql = new StringBuilder();

			sql.append("DROP TABLE if exists "+nowtable+";");
		//テーブルが既に存在する場合空にする
		//	sql.append("truncate TABLE "+nowtable+" RESTART IDENTITY;");
			if(!sql.toString().equals("")){
	//			System.out.println(sql.toString());
				stmt.executeUpdate(sql.toString());
			}
			stmt.close();
		} catch (SQLException e) {
			System.err.println(e.getMessage());
		}
	}
	public static void resetTable(Connection conn, String tableName) {
		Statement stmt;
		try {
			stmt = conn.createStatement();
			StringBuilder sql = new StringBuilder();

			sql.append("DROP TABLE if exists "+tableName+";");
		//テーブルが既に存在する場合空にする
		//	sql.append("truncate TABLE "+nowtable+" RESTART IDENTITY;");
			if(!sql.toString().equals("")){
	//			System.out.println(sql.toString());
				stmt.executeUpdate(sql.toString());
			}
			stmt.close();
		} catch (SQLException e) {
			System.err.println(e.getMessage());
		}
	}

//	public static long insertCSVtoPostgreSQL(Connection conn) {
//		Statement stmt;
//		CopyManager copyManager;

//		long result = 0;
//		try {
//			copyManager = new CopyManager((BaseConnection) conn);
//			Reader reader = new InputStreamReader(new FileInputStream(nowfile), "UTF8");
//			String sql = "copy " + nowtable + " FROM STDIN WITH CSV HEADER";
//			System.out.println("ok");System.out.println(sql.toString());
//			result = copyManager.copyIn(sql, reader);
//			reader.close();
//		} catch (IOException e) {
//			System.err.println(e.getMessage());
//		} catch (SQLException e) {
//			System.err.println(e.getMessage());
//		}
//		return result;
//	}

	public static void insertCSVtoOtherDB(Connection conn) {
		Statement stmt;
		long result = 0;
		try {
			stmt = conn.createStatement();
			//stmt.setQueryTimeout(30);
			BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(nowfile), "UTF-8"));
			boolean header_name = true;
			boolean header_type = true;
			boolean header_comp = false;

			//CSVの1行目にカラムを指定する場合
			if(GlobalEnv.getcsvcolumntype() != null) {
				//createTable(conn);

				StringBuilder sql = new StringBuilder();

				sql.append(".mode csv");
				stmt.executeQuery(sql.toString());
				sql.delete(0, sql.length());
				sql.append(".import " + nowfile + " " + nowtable);
				stmt.executeQuery(sql.toString());



			} else {
				StringBuilder sql = new StringBuilder();
				String line = br.readLine();

				//from句に記述した場合
				if(col_n != null && col_t != null) {
					createTable(conn, col_n, col_t);
					while(line != null){
						String[] data = line.split("[\\s]*,[\\s]*");
						sql.append("INSERT INTO " + nowtable +" VALUES(");
						for (int i = 0; i < data.length; i++) {
							if(col_t[i].equalsIgnoreCase("TEXT")) {
								if(data[i].contains("\'")) {
									data[i].replace("\'", "\\'");
								}
								if(!(data[i].startsWith("'")) && (!(data[i].endsWith("'")) || !(data[i].endsWith("\'")))){
									sql.append("'"+data[i]+"'");
								}else {
									sql.append(data[i]);
								}
							} else {
								sql.append(data[i]);
							}
							if(i<data.length-1) {
								sql.append(", ");
							}
						}
						sql.append(");");
						line = br.readLine();
					}


				} else {
					if(nowfile.matches( GlobalEnv.getfileparent() + "/title_url_[0-9]*.csv")) {
						while(line != null){
							String[] data = line.split("[\\s]*,[\\s]*");
							if(!header_comp) {
								if(header_name) {
									col_n = data;
									header_name = false;
									col_t = new String[col_n.length];
									for(int i=0;i<col_t.length;i++) {
										col_t[i] = "TEXT";
									}
									createTable(conn, col_n, col_t);
									header_comp= true;
								}
							}else {
								sql.append("INSERT INTO " + nowtable +" VALUES(");
								for (int i = 0; i < data.length; i++) {
									if(data[i].contains("'")) {
										String s = data[i].replaceAll("'", "''");
											data[i] = s;
//									System.out.println(s);
									}
									sql.append("'"+data[i]+"'");
									if(i<data.length-1) {
										sql.append(", ");
									}
								}
								sql.append(");");
							}
							line = br.readLine();
						}
					}else if(nowfile.matches( GlobalEnv.getfileparent() + "/sparqlresult[0-9]*_[0-9]*.csv")) {
						while(line != null){
							String[] data = line.split("[\\s]*,[\\s]*");
							if(!header_comp) {
								if(header_name) {
									col_n = data;
									Start_Parse.hop0name = data;
									header_name = false;
									col_t = new String[col_n.length];
									for(int i=0;i<col_t.length;i++) {
										col_t[i] = "TEXT";
									}
									createTable(conn, col_n, col_t);
									header_comp= true;
								}
							}else {
								sql.append("INSERT INTO " + nowtable +" VALUES(");
								for (int i = 0; i < data.length; i++) {
									if(data[i].contains("'")) {
										String s = data[i].replaceAll("'", "''");
											data[i] = s;
	//									System.out.println(s);
									}
									sql.append("'"+data[i]+"'");
									if(i<data.length-1) {
										sql.append(", ");
									}
								}
								sql.append(");");
							}
							line = br.readLine();
						}
		//			}else if(nowfile.matches( GlobalEnv.getfileparent() + "/sparqlresult[0-9]*.csv")) {
		//				while(line != null){
		//					String[] data = line.split("[\\s]*,[\\s]*");
		//					if(!header_comp) {
		//						if(header_name) {
		//							col_n = data;
		//							Start_Parse.hop0name = data;
		//							header_name = false;
		//							col_t = new String[col_n.length];
		//							for(int i=0;i<col_t.length;i++) {
		//								col_t[i] = "TEXT";
		//							}
		//							createTable(conn, col_n, col_t);
		//							header_comp= true;
		//						}
		//					}else {
		//						sql.append("INSERT INTO " + nowtable +" VALUES(");
		//						for (int i = 0; i < data.length; i++) {
		//							if(data[i].contains("'")) {
		//								String s = data[i].replaceAll("'", "''");
		//									data[i] = s;
	    //									System.out.println(s);
		//							}
		//							sql.append("'"+data[i]+"'");
		//							if(i<data.length-1) {
		//								sql.append(", ");
		//							}
		//						}
		//						sql.append(");");
		//					}
		//					line = br.readLine();
		//				}
					}else {
				//CSVの1行目にカラム名、2行名にカラム型を指定した場合
					while(line != null){
						String[] data = line.split("[\\s]*,[\\s]*");
						if(!header_comp) {
							if(header_name && header_type) {
								col_n = data;
								header_name = false;
							}else if(!header_name && header_type) {
								col_t = data;
								createTable(conn, col_n, col_t);
								header_comp= true;
							}
						}else {
							sql.append("INSERT INTO " + nowtable +" VALUES(");
							for (int i = 0; i < data.length; i++) {
								sql.append(data[i]);
								if(i<data.length-1) {
									sql.append(", ");
								}
							}
							sql.append(");");
						}
						line = br.readLine();
					}
					}
				}

				stmt.executeUpdate(sql.toString());
//				System.out.println(sql.toString());
				sql.delete(0,sql.length());
			}
			col_n=null;
			col_t=null;
			br.close();
			stmt.close();
		} catch (IOException e) {
			System.err.println(e.getMessage());
		} catch (SQLException e) {
			System.err.println(e.getMessage());
		}
	}

	public static void SearchDefaultDB(ArrayList<String> tableName) {
	//		System.out.println("SearchDefaultDB");

			String user = GlobalEnv.getusername();
			String password = GlobalEnv.getpassword();

			ArrayList<String> header_name = new ArrayList<String>();
			ArrayList<String> header_type = new ArrayList<String>();
	        ExtList<ExtList<String>> tuples = new ExtList<ExtList<String>>();

			tableName.forEach(table -> {
	//			System.out.println("foreachtable: "+table);
	//		if(GlobalEnv.getdbname().equals("sqlite") || GlobalEnv.getdbname().equals("sqlite3")) {
	//			if(!GlobalEnv.csvTable.containsKey(tableName[i])) {
					try {
						Connection conn = DriverManager.getConnection(GlobalEnv.getDefaultdburl(), user, password);

						 ResultSet rs;
					     ResultSetMetaData rsmd;
					     ExtList<String> tmplist;

					     String val;
					     StringBuffer tmp = new StringBuffer();

					    String query = "SELECT * FROM "+ table + ";";
						Statement stmt = conn.createStatement();
						rs = stmt.executeQuery(query);
	//					System.out.println(query);
						rsmd = rs.getMetaData();
						int columnCount = rsmd.getColumnCount();
	//					System.out.println(columnCount);
						for (int j = 1; j <= columnCount; j++) {
							header_name.add(rsmd.getColumnName(j));
							header_type.add(rsmd.getColumnTypeName(j));
						}
//						header_type.forEach(s->System.out.println(s));

			            while (rs.next()) {
			                tmplist = new ExtList();
			                for (int j = 1; j <= columnCount; j++) {
			                	if(rs.getObject(j) != null) {
									val = rs.getObject(j).toString();
									tmp.append(val);
								}else{
			                		val = "";
								}
			                    if (val != null) {
			                        tmplist.add(val.trim());
			                    } else {
			                        tmplist.add("");
			                        Log.out("[Warning] null value exist!");
			                    }
			                }
			               tuples.add(tmplist);
			            }


			            stmt.close();
					} catch (SQLException e) {
						e.printStackTrace();
					}

		            try {
		            	Connection conn2 =  DriverManager.getConnection(GlobalEnv.geturl());
		            	Statement stmt2 = conn2.createStatement();
		            	resetTable(conn2, table);
		            	createTable(conn2, table, header_name.toArray(new String[0]), header_type.toArray(new String[0]));

		            	StringBuilder query2 = new StringBuilder();
		            	StringBuilder sb = new StringBuilder();
		            	Boolean b;

		            	tuples.forEach(n->{

		            	query2.append("INSERT INTO " + table + " VALUES(");

		            	n.forEach(s->sb.append("'"+ s + "',"));
		            	query2.append(sb.toString().substring(0,sb.toString().length()-1));

		            //	s[0] = s[0].substring(0,s[0].length());
		            //	System.out.println(s[0]);

		            	query2.append(");");
		            	sb.delete(0,sb.length());
		            	});
	//	            	System.out.println(query2.toString());
		            	stmt2.executeUpdate(query2.toString());

						query2.delete(0,query2.length());
		            	stmt2.close();
		            } catch (SQLException e) {
			            	e.printStackTrace();
		            }
				long result = 0;

	//		}
	//			}
		}
		);
		}
}

