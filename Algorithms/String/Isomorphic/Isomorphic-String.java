import java.util.*;
 
class Main
{
    // Find if strings 'X' and 'Y' are Isomorphic or not
    public static boolean isIsomorphic(String X, String Y)
    {
        // base case
        if (X == null || Y == null) {
            return false;
        }
 
        // if 'X' and 'Y' have different lengths, they cannot be isomorphic
        if (X.length() != Y.length()) {
            return false;
        }
 
        // use a map to store a mapping from characters of string 'X' to string 'Y'
        Map<Character, Character> map = new HashMap<>();
 
        // use set to store a pool of already mapped characters
        Set<Character> set = new HashSet<>();
 
        for (int i = 0; i < X.length(); i++)
        {
            char x = X.charAt(i), y = Y.charAt(i);
 
            // if `x` is seen before
            if (map.containsKey(x))
            {
                // return false if the first occurrence of `x` is mapped to a
                // different character
                if (map.get(x) != y) {
                    return false;
                }
            }
 
            // if `x` is seen for the first time (i.e., it isn't mapped yet)
            else {
                // return false if `y` is already mapped to some other char in 'X'
                if (set.contains(y)) {
                    return false;
                }
 
                // map `y` to `x` and mark it as mapped
                map.put(x, y);
                set.add(y);
            }
        }
 
        return true;
    }
 
    public static void main(String[] args)
    {
        Scanner sc= new Scanner(System.in); 
        System.out.println("Enter string x");
        String X = sc.nextLine(); 
        sc.nextLine();
        System.out.println("Enter string y");
        String Y = sc.nextLine(); 
 
        if (isIsomorphic(X, Y)) {
            System.out.print(X + " and " + Y + " are Isomorphic");
        }
        else {
            System.out.print(X + " and " + Y + " are not Isomorphic");
        }
    }
}





