
import java.util.Scanner;

public class Arithmetic_Progression {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		StringBuffer answer;
		double firstTerm, prevTerm, commonDiff;
		int numTerms;
		
		// user prompts
		System.out.print("What is the first term in the arithmetic progression? ");
		firstTerm = sc.nextDouble();
		System.out.print("How many terms? ");
		numTerms = sc.nextInt();
		System.out.print("What is the difference between each term? ");
		commonDiff = sc.nextDouble();
		
		answer = new StringBuffer(firstTerm + " ");
		prevTerm = firstTerm;
		
		for (int i = 0; i < numTerms; i++) {
			prevTerm += commonDiff;
			answer.append(prevTerm + " ");
		}
		
		System.out.println(answer.toString());
	} 
}
