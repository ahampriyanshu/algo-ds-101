
//Java program to check given numbers are Amicable Numbers or not

import java.util.*;

class AmicableNum{

	//Checks for valid Amicable Number
	boolean findAmicable(int num1, int num2){
		int sumofDiv1 =0;
		int sumofDiv2 =0;

		//Calculate sum of divisor for number 1
		for(int i=1; i <= num1/2; i++){

			if(num1%i==0){
				sumofDiv1 += i;
			}

		}

		//Calculate sum of divisor for number 2
		for(int j=1; j <= num2/2; j++){

			if(num2%j==0){
				sumofDiv2 += j;
			}

		}


		//Validate amicable numbers conditions
		if((num1 == sumofDiv2) && (num2 == sumofDiv1)){
			
			return true;

		}
		else{

			return false;

		}


	}

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in); //Create object

		int num1,num2;

		System.out.print("Enter first Number: ");
		num1 = sc.nextInt(); //first number

		System.out.print("Enter second Number: ");
		num2 = sc.nextInt(); //second number


		//Create object for class AmicableNum
		AmicableNum ami = new AmicableNum();

		//valdiating numbers
		if(ami.findAmicable(num1, num2)){

			System.out.println( num1 + " and " + num2 + " are Amicable Numbers.");

		}
		else{

			System.out.println( num1 + " and " + num2 + " are not Amicable Numbers.");

		}

	}
}