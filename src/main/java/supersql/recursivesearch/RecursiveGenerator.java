package supersql.recursivesearch;

import supersql.common.GlobalEnv;

public class RecursiveGenerator {

	public static void MakeChild(String input, String filename) {
		RecursiveChild child;
		int hop = GlobalEnv.getRecursiveNum();

		String key;
		if((input.contains("http")) || (input.equals("https"))){
			String[] splits = input.split("[\\s]*/[\\s]*");
			key = splits[splits.length-1];
		}else {
			key = input;
		}

		child = new RecursiveChild();
		child.setKey(key);
		child.setHop(hop);
		child.setFile(filename);
		child.makeAlias();
		RecursiveParent.addChild(child);
	}

	public static void MakeChild(String key, String filename, String parent) {
		RecursiveChild child;
		int hop = GlobalEnv.getRecursiveNum();

		child = new RecursiveChild();
		child.setKey(key);
		child.setHop(hop);
		child.makeAlias();
	}

	public static void RegistChild(RecursiveChild child, RecursiveChild parent) {
		parent.setChild(child);
	}


}
