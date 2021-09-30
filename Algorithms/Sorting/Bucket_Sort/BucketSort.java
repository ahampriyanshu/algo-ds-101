// Bucket sort in Java

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class BucketSort {
  public void bucketSort(float[] arr, int n) {
    if (n <= 0)
      return;
    @SuppressWarnings("unchecked")
    ArrayList<Float>[] bucket = new ArrayList[n];

    // Create empty buckets
    for (int i = 0; i < n; i++)
      bucket[i] = new ArrayList<Float>();

    // Add elements into the buckets
    for (int i = 0; i < n; i++) {
      int bucketIndex = (int) arr[i] * n;
      bucket[bucketIndex].add(arr[i]);
    }

    // Sort the elements of each bucket
    for (int i = 0; i < n; i++) {
      Collections.sort((bucket[i]));
    }

    // Get the sorted array
    int index = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0, size = bucket[i].size(); j < size; j++) {
        arr[index++] = bucket[i].get(j);
      }
    }
  }

  // Driver code
  public static void main(String[] args) {
    BucketSort b = new BucketSort();
    Scanner s = new Scanner(System.in);  // Create a Scanner object
    System.out.println("Enter no of elemets");
    int n=s.nextInt();
    ArrayList<Float>[] arr = new ArrayList[n];
    for(int i=0;i<n;i++){
      System.out.println("Enter a number");
      float num=s.nextFloat();
      num.add(arr[]);
    }
    
    b.bucketSort(arr, n);

    for (float i : arr)
      System.out.print(i + "  ");
  }
}
