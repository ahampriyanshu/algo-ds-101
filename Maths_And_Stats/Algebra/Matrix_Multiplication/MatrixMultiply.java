import java.util.*;

public class MatrixMultiply {

	private static Scanner sc = new Scanner(System.in);
	
	public static void main(String[] args) {
		
		
		System.out.println("Enter the number of rows of 1st matrix");
		int m = sc.nextInt();
		System.out.println("Enter the number of columns of 1st matrix");
		int n = sc.nextInt();
		System.out.println("Enter the number of rows of 2nd matirx");
		int p = sc.nextInt();
		System.out.println("Enter the number of columns of 2nd matrix");
		int q = sc.nextInt();
		
		if(n!=p) {
			System.out.println("Sorry the matrix cannot be multiplied");
		}else {
			
			int first[][] = new int[m][n];
			int second[][] = new int[p][q];
			
			System.out.println("Enter the elements of the 1st matrix");
			for(int i=0;i<m;i++) {
				for (int j=0;j<n;j++) {
					first[i][j] = sc.nextInt();
				}
			}
			
			System.out.println("Enter the elements of the 2nd matrix");
			for(int i=0;i<p;i++) {
				for(int j=0;j<q;j++) {
					second[i][j]=sc.nextInt();
				}
			}
			
			System.out.println("1st matrix");
			for(int i=0;i<m;i++) {
				for(int j=0;j<n;j++) {
					System.out.print(first[i][j]+" ");
				}
				System.out.println();
			}
			
			System.out.println("2nd matrix");
			for(int i=0;i<p;i++) {
				for(int j=0;j<q;j++) {
					System.out.print(second[i][j]+" ");
				}
				System.out.println();
			}
			
			int result[][]=new int[m][q];
			
			
			for(int i=0;i<m;i++) {
				for(int j=0;j<q;j++) {
					result[i][j]=0;
					for(int k=0;k<m;k++) {
						result[i][j]+=first[i][k]*second[k][j];
					}
				}
				
			}
			
			System.out.println("Result(1st matrix x 2nd matrix) :");
			for(int i=0;i<m;i++) {
				for(int j=0;j<q;j++) {
					System.out.print(result[i][j]+" ");
				}
				System.out.println();
			}
			
		}
		
	}
}
