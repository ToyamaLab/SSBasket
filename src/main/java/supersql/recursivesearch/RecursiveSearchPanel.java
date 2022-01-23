package supersql.recursivesearch;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.BoxLayout;
import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;

import supersql.common.GlobalEnv;
import supersql.parser.Start_Parse;

public class RecursiveSearchPanel extends JFrame implements ActionListener{
	protected JPanel panel;
//	protected static JList jlist;
	JTextArea hopcount;
	JTextArea query;
	JTextArea expression;
	JButton selectbutton;
	JButton plushopbutton;
	JButton minushopbutton;
	JPanel sp;
	JScrollPane sp1;
	JScrollPane sp2;
	JScrollPane sp3;
	JLabel label1;
	JLabel label2;
	JLabel label3;

	public static void newPanel(String input) {
		RecursiveSearchPanel frame = new RecursiveSearchPanel(input);
		frame.setVisible(true);

	}

	public static String confilmCheckBox(DefaultListModel listModel) {
		int size = listModel.getSize();
		for (int i = 0; i < size; i++) {
		    JCheckBox cb = (JCheckBox) listModel.getElementAt(i);
		    boolean isSelected = cb.isSelected();
		    return cb.getName();
		}
		return null;
	}

	RecursiveSearchPanel(String title){

		setTitle(title);
		setBounds(100, 100, 600, 500);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		label1 = new JLabel("Hop");
		label1.setPreferredSize(new Dimension(300, 30));
		label2 = new JLabel("Recursive SPARQL Query");
		label2.setPreferredSize(new Dimension(300, 30));
		label3 = new JLabel("Recursive Expression");
		label3.setPreferredSize(new Dimension(300, 30));

		panel = new JPanel();
		panel.setLayout(new BoxLayout(panel, BoxLayout.PAGE_AXIS));

		hopcount = new JTextArea(300,10);
		hopcount.append(String.valueOf(Start_Parse.hopCount));
		sp1 = new JScrollPane(hopcount);
		sp1.setPreferredSize(new Dimension(300, 10));

		sp = new JPanel();
		sp.setLayout(new BoxLayout(sp, BoxLayout.LINE_AXIS));

		query = new JTextArea(300, 150);
		query.append(Start_Parse.recursiveSPARQLQuery);
//		query.append("SELECT ?v1 ?o1 ?s2 ?v2 \nWHERE\n{\n  {\n  dbpj:<input>  ?v1 ?o1 .\n  }\nUNION\n  {\n  ?s2 ?v2 dbpj:<input> .\n  }\n}\nLIMIT 300");
		sp2 = new JScrollPane(query);
		sp2.setPreferredSize(new Dimension(300, 150));
//		sp2.setVisible(false);

		expression = new JTextArea(300, 100);
		expression.append(Start_Parse.recursiveExpression);
		sp3 = new JScrollPane(expression);
		sp3.setPreferredSize(new Dimension(300, 100));

//		jlist = new JList(selection.toArray());
//		jlist.setSelectionMode(ListSelectionModel.MULTIPLE_INTERVAL_SELECTION);
//		sp = new JScrollPane();
//		sp.getViewport().setView(jlist);
//		sp.setPreferredSize(new Dimension(500, 200));


		selectbutton = new JButton("Search");
		selectbutton.addActionListener(this);
		selectbutton.setActionCommand("selectbutton");

		plushopbutton = new JButton("+");
		plushopbutton.addActionListener(this);
		plushopbutton.setActionCommand("plushop");

		minushopbutton = new JButton("-");
		minushopbutton.addActionListener(this);
		minushopbutton.setActionCommand("minushop");

//		JButton querybutton = new JButton("Query Visible");
//		querybutton.addActionListener(this);
//		querybutton.setActionCommand("querybutton");

//		panel.add(label);
//		panel.add(sp);
		panel.add(label1);
		sp.add(sp1);
		sp.add(plushopbutton);
		sp.add(minushopbutton);
		panel.add(sp);
		panel.add(label2);
		panel.add(sp2);
		panel.add(label3);
		panel.add(sp3);
//		panel.add(querybutton);
		panel.add(selectbutton);

		Container contentPane = getContentPane();
	    contentPane.add(panel, BorderLayout.CENTER);
	}

	public void actionPerformed(ActionEvent e) {
		String actionCommand = e.getActionCommand();

//		StringBuffer sb = new StringBuffer();

		if(actionCommand.equals("selectbutton")){
//			if(!jlist.isSelectionEmpty()) {
//				Object[] vals = jlist.getSelectedValues();
//				sb.append(vals[0]);
				if(hopcount.getText().matches("[0-9]+")) {
					if(Integer.parseInt(hopcount.getText())>=Start_Parse.hopCount){
						Start_Parse.hopFlg = 1;
						GlobalEnv.setRecursiveNum(Start_Parse.hopCount+1);
						System.out.println(GlobalEnv.getRecursiveNum());
					}else {
						Start_Parse.hopFlg = 0;
						GlobalEnv.setRecursiveNum(1);
					}
					RecursiveSearch.setHopCount(Integer.parseInt(hopcount.getText()));
				}
				if(query !=null) {
				//	RecursiveSearch.RecursiveSearch(sb.toString(), query.getText());
//					System.out.println("\n--recursive query is --");
//					System.out.println(sb.toString()+" \n"+query.getText());
					RecursiveSearch.setRecursiveSPARQLQuery(query.getText());
	//				RecursiveSearch.RecursiveSearch(vals, query.getText());
				}
				if(expression !=null) {
					RecursiveSearch.setRecursiveExpression(expression.getText());
				}
					this.dispose();
					Start_Parse.beforerecursivetitletree = RecursiveSearch.recursivefiletree;
					Start_Parse.beforeintcountlist = RecursiveSearch.intcountlist;
					Start_Parse.addcsvmode = false;
					RecursiveSearch.RecursiveSearch();
			//		System.exit(-1);
					panel.setVisible(false);

//			} else {
//				return;
//			}
		}else if(actionCommand.equals("plushop")) {
			hopcount.setText(String.valueOf(Integer.parseInt(hopcount.getText())+1));
			validate();
		}else if (actionCommand.equals("minushop")) {
			hopcount.setText(String.valueOf(Integer.parseInt(hopcount.getText())-1));
			validate();
//		}else if(actionCommand.equals("querybutton")){
//			if(sp2.isVisible()==false) {
//			//	query.setVisible(true);
//				sp2.setVisible(true);
//				validate();
//				return;
//			}else if(sp2.isVisible()==true) {
//			//	query.setVisible(false);
//				sp2.setVisible(false);
//				validate();
//				return;
//			}

		}

	}

}