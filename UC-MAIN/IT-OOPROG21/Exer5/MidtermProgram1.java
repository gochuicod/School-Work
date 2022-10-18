/**
Name: Darelle Gochuico
BSIT - 2

OOProg21 - Object-Oriented Programming 
Midterm - Programming Exercise1

Problem:

Write a program that uses while loops to perform the following steps:
Prompt the user to input two integers: firstNum and secondNum. (firstNum must be less than secondNum).
Output all the odd numbers between firstNum and secondNum inclusive.
Output the sum of all the even numbers between firstNum and secondNum inclusive
Output the sum of the squares of all the even numbers between firstNum and secondNum inclusive
Output the sum of the squares of all the odd numbers between firstNum and secondNum inclusive.
*/

public class MidtermProgram1{
    private static int firstNum, secondNum;
    public static void main(String[] args){
        char session;
        do{
            Input();
            displayOdd();
            displayEven();
            Sum_Square_of_Even();
            Sum_Square_of_Odd();
            displayCubes();
            System.out.print("\n\nRestart session?(y/n): ");
            session = new java.util.Scanner(System.in).next().toLowerCase().charAt(0);
        }while(session == 'y');
    }//end of main

    public static void Input(){
        try{
            System.out.print("\nEnter the first number: ");
            firstNum = new java.util.Scanner(System.in).nextInt();
            System.out.print("Enter the second number: ");
            secondNum = new java.util.Scanner(System.in).nextInt();
            if(firstNum > secondNum){ System.out.print("\nFirst number must be less than second number!\n"); Input(); }
        }catch(Exception e){ System.out.print("\nCharacters are not allowed!\n"); Input(); }
    }//end of Input

    public static void displayOdd(){
        System.out.print("\nThe odd numbers between " + firstNum + " and " + secondNum + " inclusive: ");
        for(int i = firstNum; i <= secondNum; i++){
            if(i % 2 != 0){ System.out.print(i + " "); }
        }
    }//end of Odd

    public static void displayEven(){
        int sum = 0;
        System.out.print("\nThe even numbers between " + firstNum + " and " + secondNum + " inclusive: ");
        for(int i = firstNum; i <= secondNum; i++){
            if(i % 2 == 0){ System.out.print(i + " "); sum += i; }
        }
        System.out.print("\nThe sum of even numbers between " + firstNum + " and " + secondNum + " is " + sum);
    }// end of Even

    public static void Sum_Square_of_Even(){
        int sum = 0;
        for(int i = firstNum; i <= secondNum; i++){
            if((int)Math.pow(i,2) % 2 == 0) { sum += ((int)Math.pow(i,2)); }
        }
        System.out.print("\nThe sum of squared even numbers is " + sum);
    }//end of Sum_Square_of_Even

    public static void Sum_Square_of_Odd(){
        int sum = 0;
        for(int i = firstNum; i <= secondNum; i++){
            if((int)Math.pow(i,2) % 2 != 0) { sum += ((int)Math.pow(i,2)); }
        }
        System.out.print("\nThe sum of squared odd numbers is " + sum);
    }//end of Sum_Square_of_Odd

    public static void displayCubes(){
        System.out.print("\nThe cubes of the numbers between " + firstNum + " and " + secondNum + " inclusive: ");
            for(int i = firstNum; i <= secondNum; i++){
                System.out.print((int)Math.pow(i,3) + " ");
            }
    }//end of displayCubes
}//end of class
