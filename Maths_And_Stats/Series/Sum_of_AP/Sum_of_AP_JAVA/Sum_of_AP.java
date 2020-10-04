// JAVA Program to find the sum of AP Series

import java.util.Scanner;
  
class SumOfAP{ 
      
    // Function to find sum of AP. 
    static float sumOfAP(float a, float d,  
                                  int n) 
    { 
        float sum = 0; 
        for (int i = 0; i < n; i++) 
        { 
            sum = sum + a; 
            a = a + d; 
        } 
        return sum; 
    } 
      
    // Driver function 
    public static void main(String args[]) 
    { 
        Scanner sc= new Scanner(System.in);
        System.out.println("Enter the number of elements in the series:");
        int n=sc.nextInt();
        System.out.println("Enter the first element of the series:");
        float a =sc.nextFloat();
        System.out.println("Enter the common difference of the elements in the series:");
        float d =sc.nextFloat(); 
        System.out.println(sumOfAP(a, d, n)); 
    } 
}