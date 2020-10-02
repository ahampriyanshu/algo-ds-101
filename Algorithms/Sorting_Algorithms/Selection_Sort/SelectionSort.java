import java.util.*; 
public class SelectionSort {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(); //taking input the size of the array
        int a[] = new int[n];//array a
        //taking input to the array
		for(int i = 0; i < n; i++)
		{
			a[i] = sc.nextInt();
        }
        //selection sort algorithm
		for(int i = 0; i < n-1; i++)
		{
			int minInd = i;
			for(int j = i; j < n; j++)
			{
				if(a[j] < a[minInd])
				{
					minInd = j;
				}
            }
            //sorting 
			int temp = a[i];
			a[i] = a[minInd];
			a[minInd] = temp;
		}
		//printing the sorted array
		for(int e : a)
		{
			System.out.print(e + " ");
		}
		sc.close();
	}

}