import java.awt.event.*;  
import javax.swing.*;  
import java.awt.*;  
import java.io.*;

public class it_infosec32_semifinals_practice2 {
    public static void main(String[] args) {
        JFrame frame= new JFrame("Employee's Data Entry Form");  
        JTextField employee_id_textfield,firstname_textfield,middlename_textfield, lastname_textfield, date_of_birth_textfield;
        JLabel employee_id_label, firstname_label, middlename_label, lastname_label, gender_label, date_of_birth_label;
        JButton save_button, clear_button, close_button;
        JRadioButton gender_male, gender_female;
        ButtonGroup gender_button_group;
        
        employee_id_label = new JLabel("Employee ID: ");
        employee_id_label.setBounds(15,20,150,20);
        employee_id_textfield = new JTextField();
        employee_id_textfield.setBounds(115,20,150,20);  
        
        firstname_label = new JLabel("First Name: ");
        firstname_label.setBounds(15,40,150,20);
        firstname_textfield = new JTextField();  
        firstname_textfield.setBounds(115,40,150,20);  
        
        middlename_label = new JLabel("Middle Name: ");
        middlename_label.setBounds(15,60,150,20);
        middlename_textfield = new JTextField();  
        middlename_textfield.setBounds(115,60,150,20);  
        
        lastname_label = new JLabel("Last Name: ");
        lastname_label.setBounds(15,80,150,20);
        lastname_textfield = new JTextField();  
        lastname_textfield.setBounds(115,80,150,20);  

        gender_button_group = new ButtonGroup();
        
        gender_label = new JLabel("Gender: ");
        gender_label.setBounds(15,100,150,20);
        
        gender_male = new JRadioButton("Male");
        gender_male.setBounds(115,100,150,20);
        gender_male.setActionCommand("male");

        gender_female = new JRadioButton("Female");
        gender_female.setBounds(115,120,150,20);
        gender_female.setActionCommand("female");
        
        gender_button_group.add(gender_male);
        gender_button_group.add(gender_female);

        date_of_birth_label = new JLabel("Date of Birth: ");
        date_of_birth_label.setBounds(15,140,150,20);
        date_of_birth_textfield = new JTextField();
        date_of_birth_textfield.setBounds(115,140,150,20);

        save_button = new JButton("Save");
        save_button.setBounds(15,180,80,20);
        clear_button = new JButton("Clear");
        clear_button.setBounds(100,180,80,20);
        close_button = new JButton("Close");
        close_button.setBounds(185,180,80,20);

        save_button.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                try{
                    FileWriter fileWriter = new FileWriter("./"+employee_id_textfield.getText()+".txt");
                    fileWriter.write("First Name: " + firstname_textfield.getText()+"\n");
                    fileWriter.write("Middle Name: " + middlename_textfield.getText()+"\n");
                    fileWriter.write("Last Name: " + lastname_textfield.getText()+"\n");
                    fileWriter.write("Gender: " + gender_button_group.getSelection().getActionCommand()+"\n");
                    fileWriter.write("Date of Birth: " + date_of_birth_textfield.getText());
                    fileWriter.close();
                    System.out.println("Successfully wrote to the file.");
                } catch (IOException io){
                    System.out.println("An error occurred.");
                    io.printStackTrace();
                }
            }
        });

        clear_button.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                employee_id_textfield.setText("");
                firstname_textfield.setText("");
                middlename_textfield.setText("");
                lastname_textfield.setText("");
                gender_button_group.clearSelection();
                date_of_birth_textfield.setText("");
            }
        });

        close_button.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                frame.dispose();
            }
        });

        frame.add(employee_id_label);
        frame.add(employee_id_textfield);
        frame.add(firstname_label);
        frame.add(firstname_textfield);
        frame.add(middlename_label);
        frame.add(middlename_textfield);
        frame.add(lastname_label);
        frame.add(lastname_textfield);
        frame.add(gender_label);
        frame.add(gender_male);
        frame.add(gender_female);
        frame.add(date_of_birth_label);
        frame.add(date_of_birth_textfield);
        frame.add(save_button);
        frame.add(clear_button);
        frame.add(close_button);
        
        frame.setSize(280,250);
        frame.setLocationRelativeTo(null);
        frame.setLayout(null);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);  
    }
}