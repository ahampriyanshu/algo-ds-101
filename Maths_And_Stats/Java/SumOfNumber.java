import java.util.Scanner;

class SumOfNumber{

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        
        //declaring variable
		int number;
		
		//Taking input from user
		System.out.println("Enter the nth number :");
		number = scan.nextInt();
		
		//Sum of Number Formula number/2(a+l)
		int sum;
		
		sum = (number * (1 + number))/2;
		
		//Printing Sum
		System.out.println("Sum of " + number + " number is : "+ sum);
    }
}

/*  Sample Input : 
     Enter the nth Number: 5
   
    Sample Output:
        Sum of 5 number is : 15
*/