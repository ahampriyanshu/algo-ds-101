import java.util.Scanner;

public class Factorial {
    static int factorial(int n) {
        int res = 1;
        int i;
        for (i = 2; i <= n; i++)
            res *= i;
        return res;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a non-negative number: ");
        int num = scanner.nextInt();
        System.out.println("Factorial of " + num + " is " + factorial(num));
    }
}