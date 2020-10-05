import java.util.Scanner;

public class PolarCartesian {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Input radius: ");
        double radius = sc.nextDouble();
        System.out.print("Input theta in degrees: ");
        double theta = sc.nextDouble();

        // converting theta from degrees to radians
        theta = theta * Math.PI / 180f;

        double x = radius * Math.cos(theta);
        double y = radius * Math.sin(theta);

        System.out.printf("Cartesian coordinates: (%5.3f, %5.3f)", x, y);
    }
}
