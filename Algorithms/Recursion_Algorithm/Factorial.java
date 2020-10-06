import java.util.Scanner;

public class Factorial {
    //This program calculates factorial of a number using recursion
    //factorial of 0 is 1 and 1 is 1;
    //factorial of a number n= n*(n-1)!
    //Example= factorial of 4= 4*3*2*1= 4*3!
    //The base case in this is factorial of 1 is 1
    //recursive case is n * factorial(n-1)

    public int fact(int value){
        if(value==1){
            return 1;
        }
        else{
            return value*fact(value-1);
        }
    }
    public static void main(String [] args){
        Factorial f=new Factorial();
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter Value:");
        int value=sc.nextInt();
        System.out.println("Factorial of "+value+": "+f.fact(value));
    }

}
