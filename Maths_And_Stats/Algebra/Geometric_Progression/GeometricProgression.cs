using System;
class GeometricProgression {
    
    static int gp(int a, int q, int n){
        return ((int) (a * Math.Pow(q, n-1)));
    }
    
    static void Main() {
      int a = Convert.ToInt32(Console.ReadLine());
      int q = Convert.ToInt32(Console.ReadLine());
      int n = Convert.ToInt32(Console.ReadLine());
      
      Console.WriteLine("" + gp(a,q,n));
    }
}
