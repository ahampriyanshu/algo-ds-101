import java.util.*;

public class Mode {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {

		//Initialize variables
		int mode = 0;
		int maxCount = 0;
		int n;
		int count = 0;
		Set<Integer> multiModalSequence = new HashSet<Integer>();
		int multimodalCount=0;
		

		//Ask for the size of array
		System.out.println("Enter the max range of values");
		n = sc.nextInt();

		//Initialize the array
		int a[] = new int[n];

		System.out.println("Enter the numbers");
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}

		//Sort Array (Ascending order)
		Arrays.sort(a);


		//Find mode (Single and multimodal logic)
		for (int i = 0; i < n - 1; i++) {

			if (a[i] == a[i + 1]) {
				count++;
			}else {
				count=0;
			}
			if (count > maxCount) {
				maxCount = count;
				mode = a[i];
				multiModalSequence.add(mode);
			}else if(maxCount<=count && maxCount>0) {
				multiModalSequence.add(a[i]);
				multimodalCount=maxCount;
			}
			
			
		}
		
		//Print number sequence for display
		System.out.print("Sequence:[");
		for (int i = 0; i < n; i++) {
			if (i == n - 1) {
				System.out.print(a[i]);
			} else {
				System.out.print(a[i] + ",");
			}
		}
		System.out.println("]");
		
		
		//find occurences
		int occurances = maxCount+1;
		
		
		//Display mode and occurences
		if (maxCount == 0) {
			System.out.println("There is no mode for the entered number sequence!!");
		} else if(maxCount>multimodalCount) {
			System.out.println("Mode: " + mode);
			System.out.println("Occurences: " + occurances);
		}else {
			System.out.println("This is a multimodal sequence");
			System.out.print("Modes :");
			for(int x : multiModalSequence) {
				System.out.print(x+",");
			}
			System.out.println();
			System.out.println("Occurences(Each Mode): "+occurances);
		}

	}

}
