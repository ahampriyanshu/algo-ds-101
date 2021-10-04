public class RabinKarb {
    // d is the number of characters in the input alphabet
    public final static int d = 256;
     
    //pat -> pattern
    static void search(String pat, String txt, int primeNum) {
        
        int M = pat.length();
        int N = txt.length();
        int i, j;
        int p = 0; 
        int t = 0; 
        int h = 1;
     
        //assigning the value to the h,t,p
        for (i = 0; i < M-1; i++)
            h = (h*d)%primeNum;
     
        for (i = 0; i < M; i++) {
            p = (d*p + pat.charAt(i))%primeNum;
            t = (d*t + txt.charAt(i))%primeNum;
        }
     
        // Triversing the pattern 1 by 1
        for (i = 0; i <= N - M; i++) {
            if ( p == t ) {
                /* Check for characters one by one */
                for (j = 0; j < M; j++) {
                    if (txt.charAt(i+j) != pat.charAt(j))
                        break;
                }
                if (j == M)
                    System.out.println("Pattern found at index " + i);
            }
     
            // Calculate hash value for next window of text: Remove
            if ( i < N-M ) {
                t = (d*(t - txt.charAt(i)*h) + txt.charAt(i+M))%primeNum;
     
                // We might get negative value of t, converting it
                // to positive
                if (t < 0)
                t = (t + primeNum);
            }
        }
    }
     
    /* Main Method */
    public static void main(String[] args) {
        String txt = "enjoy the life as well as coding :)";
        String pattern = "as"; 
           
          // A prime number
        int primeNum = 101;
       
          // Function Call
        search(pattern, txt, primeNum);
    }
}
