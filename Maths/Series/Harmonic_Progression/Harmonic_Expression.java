import java.util.Scanner;

public class Harmonic_Expression{	
	public static void main(String args[]){
		Scanner scan = new Scanner(System.in);
		long difference, startTerm, numberOfTerms;
		System.out.print("Enter Starting Term : ");
		startTerm = scan.nextLong();
		System.out.print("Enter Difference : ");
		difference = scan.nextLong();
		System.out.print("Enter Number of Terms : ");
		numberOfTerms = scan.nextLong();
		if( startTerm == 0 ){
			System.out.println("Invalid start of Harmonic Progression.");
		}
		else{
			System.out.println("Sequence is :");
			for(int i = 1; i <= numberOfTerms; i++){
				System.out.print(String.format("1/%s",(startTerm+((i-1)*difference))));
				if(i!=numberOfTerms)
					System.out.print(" , ");
			}
		}
		System.out.println();
	}
}
