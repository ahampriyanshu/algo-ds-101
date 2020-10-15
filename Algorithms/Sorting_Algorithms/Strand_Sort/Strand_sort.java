import java.util.*;
public class Strand_sort {
    public static void main(String args[])
    {
        Scanner sc= new Scanner(System.in);
        List<Integer> given_array = new ArrayList<Integer>();
        List<Integer> temp = new ArrayList<Integer>();
        List<Integer> temp2 = new ArrayList<Integer>();
        List<Integer> output = new ArrayList<Integer>();

        System.out.println("How many number do you want to enter :");
        int i,j,max,no=sc.nextInt();
        System.out.println("Enter your values :");
        for(i=0;i<no;i++)
        {
            given_array.add(sc.nextInt());
        }
        System.out.println("Input: "+given_array);
        while(given_array.size()!=0)
        {
            for(i=0,max=0;i<given_array.size();i++)
            {
                if(given_array.get(i)>=max)
                {
                    temp.add(given_array.get(i));
                    max=given_array.get(i);
                    given_array.remove(i);
                    i--;
                }
            }
            for(i=0,j=0;i<temp.size()&&j<output.size();)
            {
                if(temp.get(i)>output.get(i))
                {
                    temp2.add(output.get(i));
                    output.remove(i);
                }
                else
                {
                    temp2.add(temp.get(i));
                    temp.remove(i);
                }
            }
            if(temp.size()!=0)
            {
                temp2.addAll(temp);
                temp.clear();
            }
            else if(output.size()!=0)
            {
                temp2.addAll(output);
                output.clear();
            }
            output.addAll(temp2);
            temp2.clear();
        }
        System.out.println("Output: "+output);
    }
}
