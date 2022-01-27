package supersql.db;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.Reader;
import java.sql.Connection;
import java.sql.SQLException;
import java.sql.Statement;

import org.postgresql.copy.CopyManager;
import org.postgresql.core.BaseConnection;

import supersql.common.GlobalEnv;

public class CsvRegister {
	static String nowtable;
	static String nowfile = new String();
	static String file_names[];

	public static void copytoDB(String input) throws Exception {
//		System.out.println("csv register");
		SQLiteRegister.copytoDB(input);
//if you want to use localdb instead of sqlite, please remove comment out and comment out "SQLiteRegister.copytoDB(input);".
/*		Connection conn;
		String hostname = GlobalEnv.gethost();
		String port = GlobalEnv.getport();
		String dbname = GlobalEnv.getdbname();
		String user = GlobalEnv.getusername();
		String driver = GlobalEnv.getDriver();
		String dbms = GlobalEnv.getdbms();
		String url = GlobalEnv.geturl();
		String password = GlobalEnv.getpassword();
 		conn = DriverManager.getConnection(url, user, password);
		long result = 0;
		nowfile = null;
		nowtable = input;
		System.out.println("nowfile: " + nowfile);
		if(GlobalEnv.getcsvfilename() != null) {
			file_names = GlobalEnv.getcsvfilename().split("[\\s]*,[\\s]*"); // 入力ファイル
			for(int i=0;i<file_names.length;i++) {
				String s[] = file_names[i].split("/");
				if(s[s.length-1].substring(0,((s[s.length-1].length())-4)).equalsIgnoreCase(nowtable)) {
					System.out.println("s: " +s[s.length-1].substring(0,((s[s.length-1].length())-4)));
					nowfile = file_names[i];
					//break;
				}
			}
			if(nowfile == null) {
				nowfile = GlobalEnv.getfileparent() + "/" + input + ".csv";
			}
		}
		System.out.println("nowfile: "+nowfile);
		if(nowfile == null) {
			nowfile = GlobalEnv.getfileparent() + "/" + input + ".csv";
		}



		resetTable(conn);
		//テーブル作成・データ挿入
		if(dbname.equals("postgresql")) {
			if(GlobalEnv.getcsvcolumntype()!=null) {
				createTable(conn);
				result = insertCSVtoPostgreSQL(conn);
			}else {
				insertCSVtoOtherDB(conn);
			}
		}else {
			insertCSVtoOtherDB(conn);
		}

		try{
			if(conn != null) conn.close();
		}catch(SQLException exception) {
			System.err.println(exception);
		}
*/
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
					data = line.split(",");
					if(data.length==column_types.length) {
						for (int j = 0; j < data.length; j++) {
							if((!(column_types[j].equals("varchar"))) && (!(column_types[j].equals("int")))
									&& (!(column_types[j].equals("float"))) && (!(column_types[j].equals("char")))
									&&(!(column_types[j].equals("datetime")))){
								sql.append(data[j]+" varchar");
							}else {
								sql.append(data[j]+" "+column_types[j]);
							}
							if(j<data.length-1) {
								sql.append(", ");
							}
						}
						sql.append(");");
						System.out.println(sql.toString());
						stmt.executeQuery(sql.toString());
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

	public static void createTable(Connection conn, String[] column_names, String[] column_types) {
			Statement stmt;
			try {
				stmt = conn.createStatement();
				StringBuilder sql = new StringBuilder();

			//テーブル作成
				sql.append("CREATE TABLE "+nowtable+"(");
				if(column_names.length==column_types.length) {
					for (int i = 0; i < column_names.length; i++) {
						if((!(column_types[i].equals("varchar"))) && (!(column_types[i].equals("int")))
								&& (!(column_types[i].equals("float"))) && (!(column_types[i].equals("char")))
								&&(!(column_types[i].equals("datetime")))) {
							sql.append(column_names[i]+" varchar");
						}else {
							sql.append(column_names[i]+" "+column_types[i]);
						}
						if(i<column_names.length-1) {
							sql.append(", ");
						}
					}
					sql.append(");");
					System.out.println(sql.toString());
					stmt.executeQuery(sql.toString());
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
				System.out.println(sql.toString());
				stmt.executeQuery(sql.toString());
			}
			stmt.close();
		} catch (SQLException e) {
			System.err.println(e.getMessage());
		}
	}

	public static long insertCSVtoPostgreSQL(Connection conn) {
		Statement stmt;
		CopyManager copyManager;

		long result = 0;
		try {
			copyManager = new CopyManager((BaseConnection) conn);
			Reader reader = new InputStreamReader(new FileInputStream(nowfile), "UTF8");
			String sql = "copy " + nowtable + " FROM STDIN WITH CSV HEADER";
			result = copyManager.copyIn(sql, reader);
			reader.close();
		} catch (IOException e) {
			System.err.println(e.getMessage());
		} catch (SQLException e) {
			System.err.println(e.getMessage());
		}
		return result;
	}

	public static void insertCSVtoOtherDB(Connection conn) {
		Statement stmt;
		long result = 0;
		try {
			stmt = conn.createStatement();
			//stmt.setQueryTimeout(30);

			FileInputStream fi = null;
			try {
				fi = new FileInputStream(new File(nowfile));
			} catch (FileNotFoundException e) {
				System.err.println(e.getMessage());
	        }
			InputStreamReader is = new InputStreamReader(fi, "UTF-8");
			BufferedReader br = new BufferedReader(is);

			boolean header_name = true;
			boolean header_type = true;
			boolean header_comp = false;

			//引数でカラム型を指定する場合
			if(GlobalEnv.getcsvcolumntype() != null) {
				createTable(conn);
				String line = br.readLine();
				while(line != null){
					StringBuilder sql = new StringBuilder();
					String[] data = line.split(",");
					sql.append("INSERT INTO " + nowtable +" VALUES(");
					for (int i = 0; i < data.length; i++) {
						sql.append(data[i]);
						if(i<data.length-1) {
							sql.append(", ");
						}
					}
					sql.append(");");
					stmt.executeQuery(sql.toString());
					line = br.readLine();
				}
			//CSVの1行目にカラム名、2行名にカラム型を指定した場合
			} else {
				String[] column_names = null;
				String[] column_types = null;
				StringBuilder sql = new StringBuilder();
				String line = br.readLine();
				while(line != null){
					String[] data = line.split(",");
					if(!header_comp) {
						if(header_name && header_type) {
							column_names = data;
							header_name = false;
						}else if(!header_name && header_type) {
							column_types = data;
							createTable(conn, column_names, column_types);
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
				System.out.println(sql.toString());
				stmt.executeQuery(sql.toString());
			}
				br.close();
			stmt.close();
		} catch (IOException e) {
			System.err.println(e.getMessage());
		} catch (SQLException e) {
			System.err.println(e.getMessage());
		}

	}
}

