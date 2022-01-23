package supersql.parser;


import java.io.Serializable;

import supersql.common.Log;

public class FromParse implements Serializable {

	private String line;

	private String real_name;

	protected String alias;


	public FromParse(String line) {
		this.line = line;
		this.real_name = "";
		this.alias = "";
		this.parseString(line);
	}

	public void parseString(String line) { //add ayumi
		int ind = line.indexOf(" ");
		if (ind == -1) {
			if(line.equalsIgnoreCase(".csv")) {
				this.real_name = line.substring(0,line.length() - 4);
				this.alias = line.substring(0,line.length() - 4);
			}else if(line.equalsIgnoreCase("csv")){
				this.real_name = line.substring(0,line.length() - 3);
				this.alias = line.substring(0,line.length() - 3);
			}else {
				this.real_name = line;
				this.alias = line;
				Log.out("[FromParse] alias name omitted table = "+ line);
			}
		} else {
			if (line.substring(0,ind).equalsIgnoreCase(".csv")){
				this.real_name = line.substring(0, ind - 4);
				this.alias = line.substring(ind + 1);
			}else if(line.substring(0,ind).equalsIgnoreCase("csv")){
				this.real_name = line.substring(0, ind - 3);
				this.alias = line.substring(ind + 1);
			}else {
				this.real_name = line.substring(0, ind);
				this.alias = line.substring(ind + 1);
			}
		}
	}

	@Override
	public String toString() {
		return "{ line : " + line + ", real_name : " + real_name + ", alias : "
				+ alias + " }";
	}

	public String getLine() {
		return line;
	}

	public String getRealName() {
		return real_name;
	}

	public String getAlias() {
		return alias;
	}

}
