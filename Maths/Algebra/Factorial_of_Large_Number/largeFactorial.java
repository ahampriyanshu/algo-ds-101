import java.util.*;
import java.math.BigInteger;
public class Main 
{
   static  BigInteger facorial(BigInteger n)
    {
        if(n==BigInteger.valueOf(0))
        return BigInteger.valueOf(1);
        return n.multiply(facorial((n.subtract(BigInteger.valueOf(1)))));
    }
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number ");
        BigInteger n = BigInteger.valueOf(sc.nextInt());
        System.out.println("The facorial of the number is "+facorial(n));
    }
}

/* 
Example - 
Enter a number 
30
The facorial of the number is 265252859812191058636308480000000
*/


