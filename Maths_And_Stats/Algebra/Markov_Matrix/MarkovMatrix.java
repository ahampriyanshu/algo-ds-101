import java.util.Scanner;

public class MarkovMatrix{

     public static void main(String []args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        double[][] markovMatrix = new double[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                markovMatrix[i][j] = sc.nextDouble();
            }
        }
        double rowSum = 0;
        for (int i = 0; i < n; i++)
        {
            rowSum = 0;
            for (int j = 0; j < m; j++)
            {
                rowSum += markovMatrix[i][j];
            }
            if (rowSum != 1) throw new RuntimeException("Row sum != 1");
        }
        System.out.print ("Input matrix is a Markov matrix");
     }
}

/*
2 2 0.4 0.6 0.5 0.5 = Markov matrix
2 2 0.1 0.1 1 1 = not a Markov matrix, results in error
*/