using System; 
  
class GFG  
{ 
    public static int squaresum(int n) 
    { 
        return (n * (n + 1) *  
               (2 * n + 1)) / 6; 
    } 
  
   
    public static void Main() 
    { 
        int n = 10; 
  
        Console.WriteLine(squaresum(n)); 
    } 
} 
