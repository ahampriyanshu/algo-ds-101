import java.util.*;
 
public class Josephus {
    public static int execute(int n, int k) {
        int killIndex = 0;//stores index of person to be executed
        ArrayList<Integer> prisoners = new ArrayList<Integer>(n);
        for(int i = 0;i < n;i++){
            prisoners.add(i);
        }
        System.out.println("Prisoners executed in order:");
        while(prisoners.size() > 1) {//until only one person remains alive
            killIndex = (killIndex + k - 1) % prisoners.size();
            System.out.print(prisoners.get(killIndex) + " ");
            prisoners.remove(killIndex);
        }
        System.out.println();
        return prisoners.get(0);
    }
 
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        System.out.println("Survivor : " + execute(n,k));
    }
}
