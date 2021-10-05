import java.util.Scanner;
class circleSortClass
{
  boolean circleSortInner(int a[], int low, int high) 
  {
      boolean swapped = false;
      if (low == high)
          return false;
      int l = low, h = high;
      int mid = (high - low) / 2;
      boolean left, right;
      while (l < h)
      {
	        if (a[l] > a[h])
	        {
	            swap (a,l,h);
	            swapped = true;
          }
	        l++;
	        h--;
      }
      if (l == h)
          if (a[l] > a[h + 1])
	        {
	            swap (a,l,h + 1);
  	        swapped = true;
	        }
          left = circleSortInner (a, low, low + mid);
          right = circleSortInner (a, low + mid + 1, high);
          return swapped || left || right;
  }
 

  void circleSort (int a[], int n) 
  {
      while (circleSortInner (a, 0, n - 1));
  }


  void swap(int arr[],int l,int h)
  {
      int temp=arr[l];
      arr[l]=arr[h];
      arr[h]=temp;
  }

 

  // Driver program 
  public static void main(String[] args)
  {
      int arr[];
      Scanner sc=new Scanner(System.in);
      System.out.println("Enter number of elements to be sorted:");
      int n=sc.nextInt();
      arr = new int[n]; 
      System.out.println("Enter "+n+" elements");
      for (int i=0;i<n;i++)
          arr[i]=sc.nextInt();
      circleSortClass c=new circleSortClass();
      c.circleSort (arr, n);
      System.out.println("Array after sorting:");
      for (int i = 0; i < n; i++)
          System.out.print(arr[i]+" ");
      System.out.println();
  }
}
