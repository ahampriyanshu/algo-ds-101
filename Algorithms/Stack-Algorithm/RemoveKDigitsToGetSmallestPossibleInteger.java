import java.util.Scanner;
import java.util.Stack;
public class RemoveKDigitsToGetSmallestPossibleInteger{
  public static void main(String[]args){
    //create scanner
    Scanner kb=new Scanner(System.in);
    
    //prompt user
    System.out.println("Provide an integer to make smallest possible with k removals");
    
    //read in input integer
    String input=kb.next();
    
    System.out.println("Please provide an integer k representing how many digits to remove from your integer");
    int k=kb.nextInt();
    
    System.out.println(removeKdigits(input, k));
  }
  public static String removeKdigits(String num, int k) {
        //make a stack of characters
        Stack<Character>s=new Stack<Character>();
        //set the number of elements removed so far to be 0
        int count=0;
        //create our string to return
        String str="";
        //loop over the length of our string
        for(int i=0; i<num.length(); i++){
            /*first condition ensures we don't go out of bounds
              
              also, if the stack is empty or the next element is > than what is already on 
              the stack we push the stack and move forward an element.  
              
              We do this because we want to ensure we get the largest element
              we can to remove.  
              
              For example, if we had 089, 1 as our input, we would want to return 8 
              rather than 9.  So, we have to keep adding the next element as long as it 
              is larger than the current one to our stack so we remove it from our string
              before the current element.  This is of course always true, since
              if we end up with a fixed length num-k, if we will always wind up with the
              same length, so if we remove anything before this largest element, we will
              move the largest element left 1 position in the string, so we would have simply
              been better off ommitting this largest element instead since the preceding element
              was smaller.  (Example: 089, we are better off removing 9 as opposed to 8, because
              otherwise, 9 gets shifted into 8's position, but 9 is larger than 8, so we are better
              off simply removing the 9 to begin with).
              
              Also, note that we go left to right over our string since the digits on the left of an
              integer hold greater value than those on the right, so we favor choosing those to remove
              first if possible
            */
            while(i!=num.length() && (s.isEmpty() || s.peek()<num.charAt(i))){
                s.push(num.charAt(i));
                i++;
            }
            
            /*conversely, as long as we keep seeing smaller elements than our current one, we
            keep popping the stack since as we will prefer the smaller digits to 'bubble' towards
            the left of our integer, removing the larger digits in its way.  
            Example: 980, 1 => after pushing 9, we want to move something smaller than 9 to the left,
            since it would make our integer smaller, so we do so by popping 9, which in effect would give
            us 80 for this example.  
            */
            while(count!=k && i!=num.length()&&!s.isEmpty() && s.peek()>num.charAt(i)){
                s.pop();
                count++;
            }
            /*after the previous loop finishes, we can push the next character onto our stack, 
            since if we aren't out of bounds, we know our next element must no longer be smaller
            than the current one.  
            */
            if (i!= num.length())
                s.push(num.charAt(i));
        }
        
        /*if we didn't remove k elements, then the final k of them must exist at the end. and thus,
        must exist at the top of our stack, so we can pop all the remaining elements until we get to k
        off the stack.  
        */
        while(count<k){
            s.pop();
            count++;
        }
        /*we remove elements from our stack and add them in reverse order to our string 
        (since using a stack inverts the order of the characters in our string). 
        */
        while(!s.isEmpty()){
            str=s.peek()+str;
            s.pop();
        }
        //count the # of leading 0s
        int i=0;
        while(i!=str.length() && str.charAt(i)=='0')
            i++;
        //remove all leading 0s
        str= str.substring(i);
        
        //if our string is empty, return 0
        if(str.length()==0)
            return "0";
        
        //otherwise, just return the string
        return str;
        
        
        
/*this takes O(n) time, since we do an O(1) push operation to each element of n elements maximum 1 time and
do an O(1) pop operation on each of n elements 1 maximum 1 time.  We also count maximum n leading 0s 
(if every digit is a leading 0), so we count each of maximum n 0s maximum 1 time each.  
Thus, since each of the finite list of operations above was O(n) time, our algorithm is worst case O(n) time. 

And it is worst case O(n) space as well since we create a stack which at most holds n characters, where 
n=#of characters in our string, and our output string similarly contains at most n characters, for a total
of O(n) space for each of the 2 data structures, hence worst case O(n) space.  
*/
  }
 }
