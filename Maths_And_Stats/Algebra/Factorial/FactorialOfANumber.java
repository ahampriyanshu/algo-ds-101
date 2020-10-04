import java.util.Scanner;

public class FactorialOfANumber {
    static int factorial(int n) {
        int r = 1;
        int i;
        for (i = 2; i <= n; i++)
            r *= i;
        return r;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int num = scanner.nextInt();
        System.out.println("Factorial of " + num + " is " + factorial(num));
    }
}
