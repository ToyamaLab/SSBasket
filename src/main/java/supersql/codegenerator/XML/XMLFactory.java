package supersql.codegenerator.XML;

import supersql.codegenerator.Attribute;
import supersql.codegenerator.Connector;
import supersql.codegenerator.Factory;
import supersql.codegenerator.Function;
import supersql.codegenerator.Grouper;
import supersql.codegenerator.IfCondition;
import supersql.codegenerator.Manager;
import supersql.codegenerator.TFE;



public class XMLFactory extends Factory {

	XMLEnv xml_env;
	XMLEnv xml_env2;

	public void createLocalEnv() {
		xml_env = new XMLEnv();
		xml_env2 = new XMLEnv();
	}

	public Manager createManager() {
		return new XMLManager(xml_env, xml_env2);
	}

	public Connector createC0(Manager manager) {
		return new XMLC0(manager, xml_env, xml_env2);
	}

	public Connector createC1(Manager manager) {
		return new XMLC0(manager, xml_env, xml_env2);
	}

	public Connector createC2(Manager manager) {
		return new XMLC0(manager, xml_env, xml_env2);
	}

	public Connector createC3(Manager manager) {
		return new XMLC0(manager, xml_env, xml_env2);
	}

	public Connector createC4(Manager manager) {
		return new XMLC0(manager, xml_env, xml_env2);
	}

	public Grouper createG0(Manager manager) {
		return new XMLG0(manager, xml_env, xml_env2);
	}

	public Grouper createG1(Manager manager) {
		return new XMLG0(manager, xml_env, xml_env2);
	}

	public Grouper createG2(Manager manager) {
		return new XMLG0(manager, xml_env, xml_env2);
	}

	public Grouper createG3(Manager manager) {
		return new XMLG0(manager, xml_env, xml_env2);
	}

	public Grouper createG4(Manager manager) {
		return new XMLG0(manager, xml_env, xml_env2);
	}

	public Attribute createAttribute(Manager manager) {
		return new XMLAttribute(manager, xml_env, xml_env2);
	}

	public Function createFunction(Manager manager) {
		return new XMLFunction(manager, xml_env, xml_env2);
	}

	@Override
	public Attribute createConditionalAttribute(Manager manager) {
		return null;
	}

	@Override
	public IfCondition createIfCondition(Manager manager, Attribute condition,
			TFE thenTfe, TFE elseTfe) {
		// TODO Auto-generated method stub
		return null;
	}

}