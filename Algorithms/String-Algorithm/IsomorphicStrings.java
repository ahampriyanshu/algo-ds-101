import java.util.*;
class Isomorphic {
    static Scanner sc=new Scanner(System.in);
    boolean isIsomorphic(String str1 ,String str2){
        if (str1.length()!= str2.length())
        return false;
        Map<Character,Character> m= new HashMap<>();
        Set<Character> s=new HashSet<>(); 
        for(int i=0;i<str1.length();i++){
            if(m.containsKey(str1.charAt(i))){
            if(m.get(str1.charAt(i))!=str2.charAt(i))
            return false;
            }
            else{
                if(s.contains(str2.charAt(i)))
                return false;
                m.put(str1.charAt(i),str2.charAt(i));
                s.add(str2.charAt(i));
            }
        }
        return true;
    }
    public static void main(String args[]) {
        Isomorphic obj= new Isomorphic();
        String m,n;
        System.out.println("Enter first string");
        m=sc.nextLine();
        System.out.println("Enter second string");
        n=sc.nextLine();
        boolean res=obj.isIsomorphic(m, n);
        if(res==true)
        System.out.println("Entered 2 strings are isomorphic");
        else
        System.out.println("Entered 2 strings are not isomorphic");

    }    
}

