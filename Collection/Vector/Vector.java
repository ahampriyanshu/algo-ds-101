import java.io.*;
import java.util.*;
  
class Main {
    
    public static void main(String[] args)
    {
        Scanner sc = new Scanner( System.in );
      
        int n = sc.nextInt();
      
        Vector<Integer> vec = new Vector<Integer>(n);
  
        for (int i = 0; i < n; i++)
            vec.add(sc.nextInt());
      
        System.out.println(vec);
      
        vec.remove(0);

        System.out.println(vec);
  
    }
}
