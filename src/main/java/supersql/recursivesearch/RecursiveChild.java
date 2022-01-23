package supersql.recursivesearch;

import java.util.ArrayList;

public class RecursiveChild {
 private String key;
 private int hop;
 private String file;
 private String alias;
 private ArrayList<RecursiveChild> childs = new ArrayList<RecursiveChild>();

public void setChilds(ArrayList<RecursiveChild> list) {
	this.childs = list;
}

public void setChild(RecursiveChild child) {
	this.childs.add(child);
}

public void setKey(String key) {
	 this.key = key;
}

 public void setHop(int hop) {
	 this.hop = hop;
 }

 public void setFile(String file) {
	 this.file = file;
 }

 public void makeAlias() {
	 if(this.file!=null) {
		 if(this.file.contains(".")) {
			 this.alias = this.file.substring(0,this.file.indexOf("."));
		 }else {
			 this.alias = this.file;
		 }
	 }else {
		 //how to make alias...?
	 }
 }

 public String getKey() {
	 return this.key;
 }

 public ArrayList<RecursiveChild> getChilds() {
		return this.childs;
 }

 public int getHop() {
	 return this.hop;
 }

 public String getFile() {
	 return this.file;
 }

 public String getAlias() {
	 return this.alias;
 }
}
