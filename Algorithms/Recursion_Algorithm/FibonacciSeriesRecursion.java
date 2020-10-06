import java.util.Scanner;

public class FibonacciSeriesRecursion {
    //Fibonacci sequence is that where each number is the sum of the previous two numbers
    //In fibonacci series the first two numbers are always 0,1
    //This is the base case
    //f(n)=f(n-1)+f(n-2) is recursive case
    public int fib(int value){
        if(value==0){
            return 0;
        }
        if(value==1){
            return 1;
        }
        return fib(value-1)+fib(value-2);   //sum of the previous two numbers
    }

    //This program calculates fibonacci number

    public static void main(String [] args){
        FibonacciSeriesRecursion f=new FibonacciSeriesRecursion();
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter a value:");
        int value=sc.nextInt();
        System.out.println("Fibonacci number : "+f.fib(value));
    }

}
