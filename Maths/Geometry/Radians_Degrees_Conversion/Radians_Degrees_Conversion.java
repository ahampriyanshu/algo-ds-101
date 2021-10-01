class Conversion {
    private static double radiansToDegrees(double radians) {
        return round(radians * (180 / Math.PI));
    }

    private static double degreesToRadians(double degrees) {
        return round(degrees * (Math.PI / 180));
    }

    private static double round(double value) {
        return (double) Math.round(value * 100) / 100;
    }

    public static void main(String[] args) {
        final double radians = 1;
        final double degrees = 57.30;

        assert radiansToDegrees(radians) == degrees;
        assert degreesToRadians(degrees) == radians;
    }
}
