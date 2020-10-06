//Calculating Compound Interest

import java.util.*;

class Solution
{
//function to calculate compound interest
    double compound_interest(double principle,double rate,double time){
	    return principle * Math.pow((1 + rate/100), time);
	}
}
public class Compound_Interest
{
//main class
    public static void main(String[] args)
    {
      	Scanner scanner = new Scanner(System.in);
	      Solution object = new Solution();
        double principle,rate,time;
        System.out.println("Enter the principle ");
      	principle = scanner.nextFloat();
      	System.out.println("Enter the rate ");
      	rate = scanner.nextFloat();
      	System.out.println("Enter the time period ");
	      time = scanner.nextFloat();
      	System.out.println("The compound interest is: "+object.compound_interest(principle, rate, time));
    }
} 
