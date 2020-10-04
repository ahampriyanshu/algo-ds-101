import java.util.Scanner;

public class FibonacciNumbers {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n1 = 0, n2 = 1, ni, i;
		System.out.print("Enter number in series : ");
		int number = sc.nextInt();
		// printing 0 and 1
		System.out.print(n1 + " " + n2);

		// loop starts from 2 as 0 and 1 are already printed
		for (i = 2; i < number; i++) {
			ni = n1 + n2;
			System.out.print(" " + ni);
			n1 = n2;
			n2 = ni;
		}

	}

}
