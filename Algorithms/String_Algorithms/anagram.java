import java.util.Scanner;

public class anagram {
    static boolean isAnagram(String a, String b) {
        a = a.toLowerCase();
        b = b.toLowerCase();
        int countA=0, countB=0;
        if(a.length()!=b.length())
            return false;
        else{
        for(char i ='a';i<='z';i++){
            for(int j=0;j<a.length();j++)
                if(a.charAt(j)==i)
                    countA++;
            for(int j=0;j<b.length();j++)
                if(b.charAt(j)==i)
                    countB++;
            if(countA!=countB)
                return false;
            countA=0;
            countB=0;
        } 
        return true;
        }   
    }
  public static void main(String[] args) {
    
        Scanner scan = new Scanner(System.in);
        String a = scan.next();
        String b = scan.next();
        scan.close();
        boolean ret = isAnagram(a, b);
        System.out.println( (ret) ? "Anagrams" : "Not Anagrams" );
    }
}