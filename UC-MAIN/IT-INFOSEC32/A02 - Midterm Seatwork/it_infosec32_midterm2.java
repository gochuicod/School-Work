import java.util.Scanner;

public class it_infosec32_midterm2 {
    Scanner input;

    public it_infosec32_midterm2(){
        input = new Scanner(System.in);
    }

    public static void main(String[] args){
        acceptMessage();
    }
    
    private static void acceptMessage(){
        it_infosec32_midterm2 obj = new it_infosec32_midterm2();
        
        System.out.print("Enter a message: ");
        String message = obj.input.nextLine();

        System.out.print("Enter number to shift: ");
        int shift = obj.input.nextInt();

        encryptMessage(message.trim(),shift);
    }

    private static void encryptMessage(String value, int shift){
        char[] output = value.toCharArray();
        for(int i = 0; i < output.length; output[i] = (char)((int)output[i]+shift), System.out.print(output[i]), i++);
    }
}