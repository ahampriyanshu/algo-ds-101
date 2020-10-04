/**
 * Compile and execute: java -classpath Palindrome.jar Palindrome.java
 *
 * @author  Ytalo Ramon
 */

package String_Algorithms;

public class Palindrome {

    public static void main(String[] args) {

        String inputs[] = { "ana", "carl", "anaa", "level", "levell", "a", "deified", "deiffied", "civicc", "tesett",
                "vuc", "amaamaamaama" };

        for (String value : inputs)
            System.out.println("\"" + value + "\" is palindrome? " + (is_palindrome(value) ? "Yes" : "No"));

    }

    static boolean is_palindrome(String value) {
        int i = -1, j = value.length();
        while (i < j && value.charAt(++i) == value.charAt(--j));

        return j <= i;
    }
}
