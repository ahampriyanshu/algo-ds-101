import java.util.Scanner;
class Main
{
    // swap
    private static void swap(int[] A, int i, int j)
    {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
 
    // rearrange
    public static void rearrangeArray(int[] A)
    {
        for (int i = 1; i < A.length; i += 2)
        {
            if (A[i - 1] > A[i]) {
                swap(A, i - 1, i);
            }
            if (i + 1 < A.length && A[i + 1] > A[i]) {
                swap(A, i + 1, i);
            }
        }
    }
    public static void main (String[] args)
    {
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter no. of elements in array:");
        n = sc.nextInt();
        int A[] = new int[n];
        System.out.println("Enter all the elements:");
        for(int i = 0; i < n; i++)
        {
            A[i] = sc.nextInt();
        }
 
        rearrangeArray(A);
        System.out.println(Arrays.toString(A));
    }
}
