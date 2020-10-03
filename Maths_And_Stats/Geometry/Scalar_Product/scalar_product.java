import java.io.*; 
  
class ScalarProduct {
	static int n = 3; 

	static int dotProduct(int vect_A[], int vect_B[]) {
		int product = 0; 
		for (int i = 0; i < n; i++) 
			product = product + vect_A[i] * vect_B[i]; 
		return product; 
	} 

	public static void main(String[] args) { 
		int vect_A[] = {1, 2, 6};
		int vect_B[] = {-5, 3, 4};
		int cross_P[] = new int[n]; 
		System.out.print("Dot product:"); 
		System.out.println(dotProduct(vect_A, vect_B)); 
	} 
}