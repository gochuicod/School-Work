import java.awt.event.*;  
import javax.swing.*;  
import java.awt.*;  

public class it_infosec32_semifinals_practice1 {
    public static void main(String[] args) {
        // initializations
        JFrame frame = new JFrame("Login Form");
        JLabel username_label, password_label;
        JTextField username_textfield;
        JPasswordField password_passwordfield;
        JButton submit_button, cancel_button;

        // creates user area
        username_label = new JLabel("Username: ");
        username_label.setBounds(15,20,150,20);
        username_textfield = new JTextField();
        username_textfield.setBounds(105,20,150,20);

        // creates password area
        password_label = new JLabel("Password: ");
        password_label.setBounds(15,50,150,20);
        password_passwordfield = new JPasswordField();
        password_passwordfield.setBounds(105,50,150,20);

        // creates submit area
        submit_button = new JButton("Submit");
        submit_button.setBounds(15,90,120,20);
        cancel_button = new JButton("Cancel");
        cancel_button.setBounds(140,90,120,20);

        // provides actions when submit button is clicked
        submit_button.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                if(username_textfield.getText().equals("infosec32") && new String(password_passwordfield.getPassword()).equals("123456")){
                    JOptionPane.showMessageDialog(frame,"Welcome to Infosec32 Semi-Finals Activity 1!");
                } else {
                    JOptionPane.showMessageDialog(frame,"Invalid username or password.", "Error!", JOptionPane.ERROR_MESSAGE);
                }
            }
        });

        // exits program when cancel button is clicked
        cancel_button.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                frame.dispose();
            }
        });

        // adds all areas to the frame
        frame.add(username_label);
        frame.add(username_textfield);
        frame.add(password_label);
        frame.add(password_passwordfield);
        frame.add(submit_button);
        frame.add(cancel_button);

        // frame configurations
        frame.setSize(280,160);
        frame.setLocationRelativeTo(null);
        frame.setLayout(null);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}  