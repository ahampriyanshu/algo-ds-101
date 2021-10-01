using System;  
public class Exercise3  
{  
    public static void Main() 
{
   int i,n,sum=0;
   Console.Write("\n\n");
   Console.Write("Input Value of terms : ");
   n= Convert.ToInt32(Console.ReadLine());   
   for(i=1;i<=n;i++)
   {
     sum+=i;
   }
   Console.Write("\nThe Sum of Natural Number upto {0} terms : {1} \n",n,sum);
  }
}