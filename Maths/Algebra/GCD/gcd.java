import java.util.Scanner;
public class GCD
{
    public static void main(String args[])
    {   
                Scanner sc = new Scanner(System.in);
                System.out.println("Please enter first number to find GCD");
                int n1 = sc.nextInt();
                System.out.println("Please enter second number to find GCD");
                int n2 = sc.nextInt();
              
                System.out.println("GCD of two numbers " + n1 +" and " 
                                   + n2 +" is :" + findGCD(n1,n2));
              
              
    }
        
            /*
             * Java method to find GCD of two number using Euclid's method
             * @return GDC of two numbers in Java
             */
            private static int findGCD(int number1, int number2) 
            {
                //base case
                if(number2 == 0)
                {
                    return number1;
                }
                return findGCD(number2, number1%number2);
            }
          
 }
    
