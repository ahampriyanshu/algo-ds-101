import java.util.Scanner;
import java.lang.Math;

public class A1_bubblesort {
    public static void main(String[] args) {
        
        Scanner in=new Scanner(System.in);

        int n,temp;
        
        System.out.print("\nValue of N               : ");
        n=in.nextInt();

        int a[] = new int[n];
        int max=200;
        int min=1;
        for(int i=0;i<n;i++){a[i]=(int)(Math.random()*(max-min+1)+min);}

        System.out.print("Value of Array           : ");
        for(int i=0;i<n;i++){System.out.print(a[i]+" ");}

        long start = System.nanoTime();
        

        for(int k=0;k<n;k++)
        {
            for(int j=0;j<n-1;j++)
            {
                if(a[j]>a[j+1])
                {
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
        }

        long end = System.nanoTime();
        
        System.out.print("\nBubble Sorted Array      : ");
        for(int k=0;k<n;k++)
        {
            System.out.print(a[k]+" ");
        }
 
        long elapsedTime = end - start; 
        System.out.println("\nTime Taken (NanoSeconds) : "+elapsedTime);
        System.out.println("\n");
        in.close();
    }
}