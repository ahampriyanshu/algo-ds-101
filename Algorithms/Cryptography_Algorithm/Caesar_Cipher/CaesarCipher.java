import java.util.Scanner;

public class CaesarCipher {
    public static final int SHIFT_MAX = 26;

    public static int shiftChar(int c, int shift) {
        shift = (shift+SHIFT_MAX)%SHIFT_MAX;

        if ('a' <= c && c <= 'z') {
            return ((c - 'a' + shift)%SHIFT_MAX + 'a');
        } else if ('A' <= c && c <= 'Z') {
            return ((c - 'A' + shift)%SHIFT_MAX + 'A');
        } else {
            return c;
        }
    }

    public static String cipher(String str, int shift) {
        return str.chars().map(c->shiftChar(c, shift)).collect(
                StringBuilder::new,
                StringBuilder::appendCodePoint,
                StringBuilder::append).toString();
    }

    public static String cipher(String str) {
        return cipher(str, 13);
    }

    public static String decipher(String str, int shift) {
        return cipher(str, SHIFT_MAX - shift);
    }

    public static String decipher(String str) {
        return decipher(str, 13);
    }

    public static void main(String [] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter shift (Caesar's = 13): ");
        int shift = scanner.nextInt();
        System.out.println("Enter text to be encrypted:");
        System.out.print("> ");

        String text = scanner.nextLine(); // We read empty newline
        text = scanner.nextLine();

        String crypt = cipher(text, shift);
        System.out.println(crypt);
        System.out.println(decipher(crypt, shift));
    }
}
