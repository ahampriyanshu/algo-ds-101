import java.util.*;
import java.lang.*;

class pythogoras_theorem{
	public static void main(String args[]){
		Scanner sc= new Scanner(System.in);
		double arr[] = new int[3];
		System.out.println("Enter the length of the sides of the triangle");
		for(int i = 0;i<3;i++){
			arr[i] = sc.nextDouble();
		}
		
		// The user may enter sides length in any order
		Arrays.sort(arr);
		
		if(Math.pow(arr[0],2) + Math.pow(arr[1],2) == Math.pow(arr[2],2)){
			System.out.println("The sides of the triangle follow pythogorean theorem.");
		}
		else{
			System.out.println("The sides of the triangle does not follow pythogorean theorem.");
		}
	}
}
