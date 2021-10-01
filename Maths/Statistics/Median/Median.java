package Maths_And_Stats.Statistics.Median;

import java.util.Arrays;
import java.util.Scanner;

public class Median {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("Enter no of elements: ");
        int n = sc.nextInt();

        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        System.out.println("Elements are: ");

        for (int i = 0; i < n; i++) {
            System.out.print(arr[i]+" ");
        }
        System.out.println();

        System.out.println("Median is:"+ findMedian(arr, n));
    }

    private static double findMedian(int[] arr, int n) {

        Arrays.sort(arr);

        if(n % 2 != 0) {
            return (double) arr[n/2];
        }
        else {
             return (double) (arr[(n - 1) / 2] + arr[n / 2] / 2.0);

        }
    }
}
