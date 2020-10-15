class Babylonian {

    /*Returns the square root of n. 
    Note that the function */
    static float squareRoot(float n) {

        /*We are using n itself as  
        initial approximation This  
        can definitely be improved */
        float x = n;
        float y = 1;

        // e decides the accuracy level 
        double e = 0.000001;
        while (x - y > e) {
            x = (x + y) / 2;
            y = n / x;
        }
        return x;
    }

    /* Driver program to test 
    above function*/
    public static void main(String[] args) {
        System.out.print("Please enter a number: ");
        Scanner myObj = new Scanner(System.in);
        try {
            Float n = myObj.nextFloat();
            System.out.printf("Square root of " +
                n + " is " + squareRoot(n));
        } catch (InputMismatchException e) {
            String msg = e.getMessage();
            System.out.println("That is not a number, please try again.");
        }
    }
}
