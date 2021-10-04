import java.util.*;
class BinarySearch {
    static Scanner sc=new Scanner(System.in);
    int binarySearch(int arr[], int l, int r, int x)
    {
        if (r >= l) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == x)
                return mid;
            if (arr[mid] > x)
                return binarySearch(arr, l, mid - 1, x);
            return binarySearch(arr, mid + 1, r, x);
        }
  
        // When element is not present in array
        return -1;
    }
    public static void main(String args[])
    {
        BinarySearch obj = new BinarySearch();
        System.out.println("Enter length of array");
        int n = sc.nextInt();
        int arr[]=new int[n]; 
        System.out.println("Enter elements of array");
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        Arrays.sort(arr);
        System.out.println("Enter number to be searched");
        int x = sc.nextInt();
        int result = obj.binarySearch(arr, 0, n - 1, x);
        if (result == -1)
            System.out.println("Number not present");
        else
            System.out.println("Number found at index " + result);
    }
}