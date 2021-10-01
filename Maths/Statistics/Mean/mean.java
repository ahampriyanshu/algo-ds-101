package Maths_And_Stats.Statistics.Mean;


public class mean {

   public static void main(String args[]){
      float mean;
      int sum, i;
      int n = 5;
      int a[] = {2,6,7,4,9};
      sum = 0;

      for(i = 0; i < n; i++) {
         sum+=a[i];
      }
      System.out.println("Mean ::"+ sum/(float)n);
   }
}