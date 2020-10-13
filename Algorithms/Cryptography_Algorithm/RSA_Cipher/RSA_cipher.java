/*
 * RSA algorithm is asymmetric cryptography algorithm. 
 * Asymmetric actually means that it works on two different keys i.e. Public Key and Private Key. 
 * As the name describes that the Public Key is given to everyone and Private key is kept private. 
 */

import java.io.DataInputStream;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Random;
 class Algorithm
{
    private BigInteger P;
    private BigInteger Q;
    public BigInteger N;
    private BigInteger PHI;
    public BigInteger e;
    private BigInteger d;
    private int maxLength = 1024;
    private Random R;
 
    public Algorithm()
    {
        R = new Random();
        
        //prime numbers 
        P = BigInteger.probablePrime(maxLength, R);
        Q = BigInteger.probablePrime(maxLength, R);
        
        //N = P*Q
        N = P.multiply(Q);
        
        //(|)(N) = (P-1)*(Q-1)
        PHI = P.subtract(BigInteger.ONE).multiply(  Q.subtract(BigInteger.ONE));
        
        
        e = BigInteger.probablePrime(maxLength / 2, R);
        
        while (PHI.gcd(e).compareTo(BigInteger.ONE) > 0 && e.compareTo(PHI) < 0)
        {
            e.add(BigInteger.ONE);
        } //e relatively prime to PHI
        
        d = e.modInverse(PHI);
        
    }
 
    public Algorithm(BigInteger e, BigInteger d, BigInteger N)
    {
        this.e = e;
        this.d = d;
        this.N = N;
    }
 
   

 
    // Encrypting the data
    public byte[] encryptMessage(byte[] data)
    {	
    	// returns (data^e)%N
        return (new BigInteger(data)).modPow(e, N).toByteArray();
    }
 
    // Decrypting the data
    public byte[] decryptMessage(byte[] data)
    {	
    	//returns (data^d)%N
    	//remember d is our private key, we never share that 
    	//otherwise our security will be compromised.
    	
        return (new BigInteger(data)).modPow(d, N).toByteArray();
    }
}

public class RSA_cipher {
	//return all the bytes concatenated in a string
    private static String byte2String(byte[] cipher)
    {
        String temp = "";
        for (byte b : cipher)
        {
            temp += Byte.toString(b);
        }
        return temp;
    }
	
	 public static void main (String [] arguments) throws IOException
	    {
	        Algorithm algorithm = new Algorithm();
	        DataInputStream input = new DataInputStream(System.in);
	        String inputString;
	        System.out.println("Enter data to send.");
	        inputString = input.readLine();
	        System.out.println("Encrypting the data: " + inputString);
	        System.out.println("The data in bytes is:: "
	                + byte2String(inputString.getBytes()));
	        System.out.printf("Shared public key:\nN: %d \ne: %d \n\n",algorithm.N, algorithm.e);
	        
	        // encryption
	        byte[] cipher = algorithm.encryptMessage(inputString.getBytes());
	        
	        // decryption
	        byte[] plain = algorithm.decryptMessage(cipher);
	        
	        System.out.println("Decrypting Bytes: " + byte2String(plain));
	        System.out.println("Original data is: " + new String(plain));
	    }
	 
}