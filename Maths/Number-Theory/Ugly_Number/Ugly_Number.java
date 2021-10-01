//Implementing Ugly Number in Java

import java.util.*;
class Solution{
//function to calculate whether ugly number or not
public boolean isUgly(int number) {
    if (number <= 0){ 
      return false;
    }
    if (number == 1){ 
      return true;
    }
    if (number % 2 == 0) {
        return isUgly(number/2);
    }
    if (number % 3 == 0) {
        return isUgly(number/3);
    }
    if (number % 5 == 0) {
        return isUgly(number/5);
    }
    return false;
  }
}

//main class
public class Ugly_Number
{
  public static void main(String[] args){
    Scanner scanner = new Scanner(System.in);
    System.out.println("Enter the number: ");
    int input_number = scanner.nextInt();
    Solution object = new Solution();
    boolean answer = object.isUgly(input_number);
    if(answer==true)
      System.out.println("Number is Ugly");
    else
      System.out.println("Number is not Ugly");
  }
}
