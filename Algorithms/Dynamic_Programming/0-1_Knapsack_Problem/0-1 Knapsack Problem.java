/*0-1 Knapsack problem */
import java.util.*;
public class Knapsack {

    //function to return max. of two integers
    static int max(int a, int b)
    {
        return (a > b) ? a : b;
    }

   //function to return proper max. value to fill knapsack of weight W
    static int knapSack(int W, int wt[], int val[], int n)
    {
        int i, w;
        int K[][] = new int[n + 1][W + 1];

        // Build table K[][] in bottom up manner
        for (i = 0; i <= n; i++) {
            for (w = 0; w <= W; w++) {

                if (i == 0 || w == 0)
                    K[i][w] = 0;
                else if (wt[i - 1] <= w)
                    K[i][w] = max(
                        val[i - 1] + K[i - 1][w - wt[i - 1]],
                        K[i - 1][w]);
                else
                    K[i][w] = K[i - 1][w];
            }
        }

        return K[n][W];
    }
    //Main function
    public static void main(String args[])
    {
        Scanner input=new Scanner(System.in);
        System.out.println("Enter the number of items in a Knapsack:");
        int n = input.nextInt();
        int v[]=new int[n];
        int w[]=new int[n];
        for (int i=0; i<n; i++)
        {
            System.out.println("Enter value and weight for item "+i+ ":");
            v[i] = input.nextInt();
            w[i] = input.nextInt();
        }
        System.out.println("Enter the capacity of knapsack");
        int W = input.nextInt();
        System.out.println(knapSack(W, w, v, n));
    }
}
