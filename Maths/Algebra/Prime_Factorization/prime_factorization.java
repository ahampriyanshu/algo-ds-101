import java.util.*;
import java.lang.Math;

/*
 sample input 1: 60
 sample output 1: 
 Prime Factorization of 60 ->
      60 = 2x2x3x5
 
 sample input 2: 297
 sample output 2:
 Prime Factorization of 297 ->
      297 = 3x3x3x11
 
 sample input 3: 1024
 sample output 3:
 Prime Factorization of 1024 ->
      1024 = 2x2x2x2x2x2x2x2x2x2
 
 sample input 4: 547
 sample output 4: 
 Prime Factorization of 547 ->
      547 = 547
 */
class prime_factorization{

    // method for factorization.
    private static void factorize(int n){

        System.out.println("Prime Factorization of "+n+" -> ");

        System.out.print("\t "+n+" = ");

        // any number can have atmost 1 prime factor greater than sqrt(n). 
        for(int i=2;i<=(int)Math.sqrt(n);i++){

            // if n=1 exit the loop 
            if(n<2){
                break;
            }

            // until n is divisible by i print i and divide n
            while(n%i==0){
                System.out.print(i);
                n/=i;  
                if(n>=2){
                    System.out.print("x");
                }
            }
        }

        if(n>2){
            // prints the only prime factor that is greater than sqrt(n)
            System.out.print(n);
        }

    }
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        int n; // input variable for which prime factors are to be generated
        try{
            n = input.nextInt();  // scanning for input
            if(n>2){
                factorize(n);  // passing parameter to 'factorize' method.
            }
            else{
                System.out.println(n+" cannot have any prime factors");   // negative and numbers lesser than 2 are excluded
            }
        }catch(Exception e){
            System.out.println("error: invalid input\nValid input: Integers only");  // handling execption for invalid or large input
        }finally{
            input.close();
        }
        
    }
}