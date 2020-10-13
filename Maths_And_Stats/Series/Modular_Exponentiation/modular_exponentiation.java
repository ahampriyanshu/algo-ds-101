import java.util.Scanner;

public class modular_exponentiation{
    public static void main(String[] args) {
        double b, e, m;
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter the base value: ");
        b = scan.nextDouble();
        System.out.println();
        System.out.print("Enter the exponent value: ");
        e = scan.nextDouble();
        System.out.println();
        System.out.print("Enter the modulus value: ");
        m = scan.nextDouble();
        System.out.println();
        double res_double = Math.pow(b, e) % m;
        int res = (int) (res_double);
        System.out.println("The modular exponentiation of the given set of values is: " + res);
        scan.close();
    }
}