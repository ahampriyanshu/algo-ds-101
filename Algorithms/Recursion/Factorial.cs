using System;

namespace Demo {

   class Factorial {

      public int checkFact(int n) {
         if (n == 1)
         return 1;
         else
         return n * checkFact(n - 1);
      }

      static void Main(string[] args) {

         int value = 9;
         int ret;

         Factorial fact = new Factorial();
         ret = fact.checkFact(value);
         Console.WriteLine("Value is : {0}", ret );
         Console.ReadLine();
      }
   }
}
