import java.util.Scanner;

public class Sum_of_GP {

    static double sumGP(double firstTerm, double commonRatio, int numberOfTerms) {
        return firstTerm * ((1 - Math.pow(commonRatio, numberOfTerms)) / (1 - commonRatio));
    }

    static double sumGPToInfinity(double firstTerm, double commonRatio) {
        return firstTerm * (1 / (1 - commonRatio));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the GP values belows");
        System.out.println("first term: ");
        double firstTerm = sc.nextDouble();

        System.out.println("number of terms (zero, if you want to get sum to infinity): ");
        int numberOfTerms = sc.nextInt();

        System.out.println("ratio (a non zero number, for sum to infinity, number should be between -1 & 1): ");
        double commonRatio = sc.nextDouble();

        // common ratio of a GP should not be zero
        if (commonRatio == 0) {
            System.out.println("common ratio cannot be zero");
            return;
        }

        if (numberOfTerms <= 0) {
            // if numberOfTerms is 0 or less than, sum to infinity is considered
            if (commonRatio > -1 && commonRatio < 1) {
                System.out.println("Geometric progression sum to infinity is: " + sumGPToInfinity(firstTerm, commonRatio));
            } else {
                System.out.println("Common ratio for sum to infinity should be between -1 and 1");
                return;
            }
        } else {
            System.out.println("Geometric Progression sum is: " + sumGP(firstTerm, commonRatio, numberOfTerms));
        }
    }
}
