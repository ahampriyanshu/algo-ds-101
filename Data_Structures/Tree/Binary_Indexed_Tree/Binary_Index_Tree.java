/**
 Binary Index Tree or Fenwick Tree
 It is a data structure that can efficiently update
 elements and calculate prefix sums in a table of numbers.


 There are two types of query that the user can input in this program
 1. Get sum upto ith position
    Format - 1 i
    Ex - 1 5

 2. Update the element at ith position to k
    Format - 2 i k
    Ex - 1 5 2


    SAMPLE INPUT :-
        12
        2 1 1 3 2 3 4 5 6 7 8 9
        3
        1 5
        2 2 6
        1 5

    EXPECTED OUTPUT :-
        9
        14
*/
import java.io.*;
import java.util.StringTokenizer;

class Binary_Index_Tree {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	//Create BIT in O(n) time
	static void createBIT(int[] ftree, int n) {
		int i, j;
		for(i=1; i<=n; i++) {
			j = i + (i & (-1*i));
			if(j <= n)
				ftree[j] += ftree[i];
		}
	}

	//Update the value in the required nodes in Tree in O(log n)
	static void update(int[] ftree, int n, int val, int i) {
		while(i <= n) {
			ftree[i] += val;
			i += (i & (-1*i));
		}
	}

	//Gives the sum of elements upto ith position in O(log n)
	static int getSum(int[] ftree, int n, int i) {
		int sum = 0;
		while(i != 0) {
			sum += ftree[i];
			i -= (i & (-1*i));
		}
		return sum;
	}

	public static void main(String[] args) throws IOException{
		int n, query;
		int val, i, type;
		System.out.print("Enter size of Array: ");
		n = Integer.parseInt(br.readLine());

		int[] ftree = new int[n+1];
		int[] arr = new int[n+1];
		
		ftree[0] = arr[0] = 0;
		System.out.print("Enter " + n + " elements in array: ");
		st = new StringTokenizer(br.readLine());
		for(i=1; i<=n; i++) {
			ftree[i] = arr[i] = Integer.parseInt(st.nextToken());
		}

		System.out.print("Enter no. of Queries: ");
		query = Integer.parseInt(br.readLine()); 

		createBIT(ftree, n);
		while(query != 0) {
			System.out.print("Enter Query: ");
			st = new StringTokenizer(br.readLine());
			
			type = Integer.parseInt(st.nextToken());
			if(type == 1) {
				i = Integer.parseInt(st.nextToken());
				System.out.println("Sum: " + getSum(ftree, n, i));
			}
			else {
				i = Integer.parseInt(st.nextToken());
				val = Integer.parseInt(st.nextToken());
				update(ftree, n, val - arr[i], i);
			}
			query--;
		}
	}
}
