package supersql.recursivesearch;

import java.util.ArrayList;

public class RecursiveParent {
	public static ArrayList<RecursiveChild> childs = new ArrayList<RecursiveChild>();

	public ArrayList<RecursiveChild> getChilds() {
		return childs;
	}

	public void setChilds(ArrayList<RecursiveChild> list) {
		this.childs = list;
	}

	public static void addChild(RecursiveChild child) {
		childs.add(child);
	}

	public static RecursiveChild searchRecursiveChild(String key) {
		for(RecursiveChild child : childs) {
			if(child.getKey().equals(key)) {
				return child;
			}
		}
		return null;
	}
}
