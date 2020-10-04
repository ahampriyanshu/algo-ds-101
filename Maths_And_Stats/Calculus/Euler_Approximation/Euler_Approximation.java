
public class Euler_Approximation {


    /**
     * Represents dy/dx. Change this function to your desired differential equation
     * @return dy/dx evaluated at the coordinate (x, y)
     */
    public static double function(double x, double y) {
        return (x + y);
    }


    /**
     * Uses Euler's method to approximate a point.
     * @param xInitial initial coniditon for the X value
     * @param yInitial initial coniditon for the Y value
     * @param xApprox value to approximate
     * @param steps number of steps to use for the appromixation. Used to determine step size.
     * @return approximation of f(xApprox)
     * @see #function(double, double)
     */
    public static double approximate(final double xInitial, final double yInitial, double xApprox, int steps) {
        // find step size
        // (b - a) / n
        final double stepSize = (xApprox - xInitial) / (double)steps;

        // check track of the X and Y coordinates
        double prevX = xInitial;
        double prevY = yInitial;

        // iterate until we meet our end coordinate
        for(int i = 0; i < steps; i++) {
            // apply Euler's method
            // f(x) = f(prevY) + stepSize * dy/dx(prevX, prevY)
            prevY = prevY + stepSize * function(prevX, prevY);
            prevX += stepSize;
        }

        return prevY;
    }

    public static void main(String[] args) {
        
        // approximates f(2) given dy/dx = x + y; y(-1) = 1
        //  using 6 equal subdivisions
        System.out.println(approximate(-1, 1, 2, 6));
    }

}