import java.util.Date;
import java.util.Scanner;
 
// Function calculates and prints
// easter date for given year Y
 class Main {
 
    static void gaussEaster(int Y)
    {
        float A, B, C, P, Q,
            M, N, D, E;
 
        // All calculations done
        // on the basis of
        // Gauss Easter Algorithm
        A = Y % 19;
        B = Y % 4;
        C = Y % 7;
        P = (float)Math.floor(Y / 100);
        Q = (float)Math.floor(
            (13 + 8 * P) / 25);
        M = (15 - Q + P - P / 4) % 30;
        N = (4 + P - P / 4) % 7;
        D = (19 * A + M) % 30;
        E = (2 * B + 4 * C + 6 * D + N) % 7;
        int days = (int)(22 + D + E);
 
        // A corner case,
        // when D is 29
        if ((D == 29) && (E == 6)) {
            System.out.println(Y + "-04"
                               + "-19");
            return;
        }
        // Another corner case,
        // when D is 28
        else if ((D == 28) && (E == 6)) {
            System.out.println(Y + "-04"
                               + "-18");
            return;
        }
        else {
 
            // If days > 31, move to April
            // April = 4th Month
            if (days > 31) {
                System.out.println(Y + "-04-"
                                   + (days - 31));
                return;
            }
            // Otherwise, stay on March
            // March = 3rd Month
            else {
                System.out.println(Y + "-03-"
                                   + days);
                return;
            }
        }
    }
 
    // Driver code
    public static void main(String[] args)
    {
        int Y = new java.util.Scanner(System.in).nextInt();
        gaussEaster(Y);
    }
}
