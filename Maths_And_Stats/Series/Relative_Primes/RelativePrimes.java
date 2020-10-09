
public class relativelyPrime {
	
	static int gcd(int a, int b)
    {
      if (b == 0)
        return a;
      return gcd(b, a % b); 
    }
	
	private static boolean relativelyPrime(int a, int b) {
	    return gcd(a,b) == 1;
	}
	
	
	public static void main(String[] args) {
		int n = 10,m = 9;
		System.out.println(n+" and "+ m+" is relative Prime "+relativelyPrime(n, m));
	}

}
