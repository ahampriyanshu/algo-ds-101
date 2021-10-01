
//Java program to generate Recaman's Sequence upto nth term

import java.util.*;


class Sequence{

	//Prints Sequence upto first n term
	void recamansSeq(int n){

		//Array to store sequence
		int seqenceArray[] = new int [n];

		//First term of Sequence is always 0
		seqenceArray[0] = 0;

		System.out.print("Recanman's Sequence is: "+seqenceArray[0] + ", ");

		
		//Generate remaining terms using recursive formula
		for(int i=1; i<n; i++){

			int currentValue = seqenceArray[i-1] - i;

			for(int j=0; j<i; j++){


				//If seqenceArray[i-1] -i is Negative or already exists
				//then add i in sequenceArray[i-1]
				if((seqenceArray[j] == currentValue) || currentValue < 0){

					currentValue = seqenceArray[i-1] + i;
					break;
				}
			} 

			//Insert new term in array
			seqenceArray[i] = currentValue;
			System.out.print( seqenceArray[i] + ", ");
		}
	}


	public static void main (String[] args)
	{
		
		Scanner sc = new Scanner(System.in);  //Create object
		
		int n;

		System.out.print("Enter nth term (upto which sequence should be generated): ");
		n = sc.nextInt();  

		//Create object for class Sequence
		Sequence sq = new Sequence();

		sq.recamansSeq(n);
	}
}