import java.util.Scanner;
import java.lang.Math;

public class A2_selectionsort {
    public static void main(String[] args) {

        Scanner in=new Scanner (System.in);
        int n,m,temp;

        System.out.print("\nEnter N                  : ");
        n=in.nextInt();

        int a[] = new int[n];
        int max=200;
        int min=1;
        for(int i=0;i<n;i++){a[i]=(int)(Math.random()*(max-min+1)+min);}

        System.out.print("Value of Array           : ");
        for(int i=0;i<n;i++){System.out.print(a[i]+" ");}

        long start = System.nanoTime();

        for(int i=0;i<n;i++){
            m=i;
            for(int j=i;j<n;j++)
            {
                if(a[m]>a[j])
                    m=j;
            }
            temp=a[m];
            a[m]=a[i];
            a[i]=temp;
        }

        long end = System.nanoTime();

        System.out.print("Sorted Array : ");
        for(int i=0;i<n;i++){System.out.print(a[i]+" ");}

        long elapsedTime = end - start; 
        System.out.println("\nTime Taken (NanoSeconds) : "+elapsedTime);
        
        in.close();
    }
}