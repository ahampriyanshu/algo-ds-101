using System;  
  public class FactorialExample  
   {  
     public static void Main(string[] args)  
      {  
       int i,fact=1,number;      
       Console.Write("Enter a non-negative Number: ");      
       number= int.Parse(Console.ReadLine());     
       for(i=1;i<=number;i++){      
        fact=fact*i;      
       }      
       Console.Write("Factorial of " +number+" is: "+fact);    
     }  
  }  