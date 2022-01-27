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
		sp2 = new JScrollPane(query);
		sp2.setPreferredSize(new Dimension(300, 150));

		expression = new JTextArea(300, 100);
		expression.append(Start_Parse.recursiveExpression);
		sp3 = new JScrollPane(expression);
		sp3.setPreferredSize(new Dimension(300, 100));

		selectbutton = new JButton("Search");
		selectbutton.addActionListener(this);
		selectbutton.setActionCommand("selectbutton");

		plushopbutton = new JButton("+");
		plushopbutton.addActionListener(this);
		plushopbutton.setActionCommand("plushop");

		minushopbutton = new JButton("-");
		minushopbutton.addActionListener(this);
		minushopbutton.setActionCommand("minushop");

		panel.add(label1);
		sp.add(sp1);
		sp.add(plushopbutton);
		sp.add(minushopbutton);
		panel.add(sp);
		panel.add(label2);
		panel.add(sp2);
		panel.add(label3);
		panel.add(sp3);
		panel.add(selectbutton);

		Container contentPane = getContentPane();
	    contentPane.add(panel, BorderLayout.CENTER);
	}

	public void actionPerformed(ActionEvent e) {
		String actionCommand = e.getActionCommand();

		if(actionCommand.equals("selectbutton")){
			if(hopcount.getText().matches("[0-9]+")) {
				if(Integer.parseInt(hopcount.getText())>=Start_Parse.hopCount){
					Start_Parse.hopFlg = 1;
					GlobalEnv.setRecursiveNum(Start_Parse.hopCount+1);
					System.out.println(GlobalEnv.getRecursiveNum());
				}else {
					Start_Parse.hopFlg = 0;
					GlobalEnv.setRecursiveNum(1);
				}

			}
			if(query !=null) {
			//	RecursiveSearch.RecursiveSearch(sb.toString(), query.getText());
//				System.out.println("\n--recursive query is --");
//				System.out.println(sb.toString()+" \n"+query.getText());
				if(query.getText().trim().equals(Start_Parse.recursiveSPARQLQuery.trim())) {
					Start_Parse.hopFlg = 0;
					GlobalEnv.setRecursiveNum(1);
				}else {
					RecursiveSearch.setRecursiveSPARQLQuery(query.getText());
				}
//				RecursiveSearch.RecursiveSearch(vals, query.getText());
			}
			if(expression !=null) {
				if(expression.getText().trim().equals(Start_Parse.recursiveExpression.trim())) {
					Start_Parse.hopFlg = 0;
					GlobalEnv.setRecursiveNum(1);
				}else {
					RecursiveSearch.setRecursiveExpression(expression.getText());
				}
			}

			RecursiveSearch.setHopCount(Integer.parseInt(hopcount.getText()));
			Start_Parse.beforerecursivetitletree = RecursiveSearch.recursivefiletree;
			Start_Parse.beforeintcountlist = RecursiveSearch.intcountlist;
			Start_Parse.addcsvmode = false;
			panel.setVisible(false);
			RecursiveSearch.RecursiveSearch();
//			System.exit(-1);
			this.dispose();

		}else if(actionCommand.equals("plushop")) {
			hopcount.setText(String.valueOf(Integer.parseInt(hopcount.getText())+1));
			validate();
		}else if (actionCommand.equals("minushop")) {
			hopcount.setText(String.valueOf(Integer.parseInt(hopcount.getText())-1));
			validate();
		}

	}

}