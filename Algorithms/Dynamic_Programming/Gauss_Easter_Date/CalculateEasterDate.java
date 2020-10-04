import java.util.HashMap;
import java.util.Map;

/**
 * @author Alessandro Arosio - 04/10/2020 08:39
 */

public class CalculateEasterDate {
    private static final String LOCATION_OF_YEAR = "locationOfYear";
    private static final String LEAP_DAYS = "leapDays";
    private static final String NON_LEAP_YEAR = "nonLeapYear";
    private static final String YEARS_DIVIDED_100 = "yearsDividedBy100";
    private static final String CENTURY = "century";
    private static final String DIFFERENCE_LEAP_DAYS = "differenceOfLeapDays";
    private static final String DAYS_TO_ADD = "numberOfDaysToAdd";
    private static final String DAYS_TO_NEXT_SUNDAY = "numberOfDaysToNextSunday";
    private static final String DAYS = "days";

    public static void main(String[] args) {
        int year = 2019;
        gaussEaster(year);
    }

    static void gaussEaster(int year) {
        Map<String, Double> gaussNumbers = getGaussNumbers(year);
        Integer days = gaussNumbers.get(DAYS).intValue();

        if (is29Days(gaussNumbers.get(DAYS_TO_ADD), gaussNumbers.get(DAYS_TO_NEXT_SUNDAY))) {
            System.out.println(year + "-04" + "-19");
        }
        else if (is28Days(gaussNumbers.get(DAYS_TO_ADD),gaussNumbers.get(DAYS_TO_NEXT_SUNDAY))) {
            System.out.println(year + "-04" + "-18");
        } else {
            if (gaussNumbers.get(DAYS) > 31) {
                System.out.println(year + "-04-" + (days - 31));
            }
            else {
                System.out.println(year + "-03-" + days);
            }
        }
    }

    private static boolean is29Days(Double days, Double daysToSunday) {
        return days.intValue() == 29 && daysToSunday.intValue() == 6;
    }

    private static boolean is28Days(Double days, Double daysToSunday) {
        return days.intValue() == 28 && daysToSunday.intValue() == 6;
    }

    private static Map<String, Double> getGaussNumbers(int year) {
        Map<String, Double> gauss = new HashMap<>();
        gauss.put(LOCATION_OF_YEAR, Double.valueOf(year % 19));
        gauss.put(LEAP_DAYS, Double.valueOf(year % 4));
        gauss.put(NON_LEAP_YEAR, Double.valueOf(year % 7));
        gauss.put(YEARS_DIVIDED_100, Math.floor(year / 100));
        gauss.put(CENTURY, calculateCentury(gauss.get(YEARS_DIVIDED_100)));
        gauss.put(DIFFERENCE_LEAP_DAYS, (4 + gauss.get(YEARS_DIVIDED_100) - gauss.get(YEARS_DIVIDED_100) / 4) % 7);
        gauss.put(DAYS_TO_ADD, (19 * gauss.get(LOCATION_OF_YEAR) + gauss.get(CENTURY)) % 30);
        gauss.put(DAYS_TO_NEXT_SUNDAY, (2 * gauss.get(LEAP_DAYS) + 4 *
                gauss.get(NON_LEAP_YEAR) + 6 *
                gauss.get(DAYS_TO_ADD) +
                gauss.get(DIFFERENCE_LEAP_DAYS)) % 7);
        gauss.put(DAYS, 22 + gauss.get(DAYS_TO_ADD) + gauss.get(DAYS_TO_NEXT_SUNDAY));

        return gauss;
    }

    private static Double calculateCentury(Double yearsDividedBy100) {
        double floor = Math.floor((13 + 8 * yearsDividedBy100) / 25);
        return (15 - floor + yearsDividedBy100 - yearsDividedBy100 / 4) % 30;
    }
}
