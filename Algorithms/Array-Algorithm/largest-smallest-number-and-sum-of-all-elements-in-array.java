import java.io.*;
class t17question7
{
    public static void main(String args[])throws IOException
    {
        InputStreamReader in = new InputStreamReader(System.in);
        BufferedReader y = new BufferedReader(in);
        int i,ln=0,sn=0,s=0;
        int n[]=new int[20];
        System.out.println("Input 20 integers");
        for(i=0;i<20;i++)
        {
            n[i]=Integer.parseInt(y.readLine());
        }
        ln=n[0];
        for(i=1;i<20;i++)
        {
        if(n[i]>ln)
        ln=n[i];
    }
    System.out.println(" The largest number is "+ln);
    sn=n[0];
    for(i=1;i<20;i++)
    {
        if(n[i]<sn)
        sn=n[i];
    }
    System.out.println(" The smallest number is "+sn);
    for(i=0;i<20;i++)
    {
        s=s+n[i];
    }
    System.out.println(" Sum of all the elements of the array is "+s);
}
}



