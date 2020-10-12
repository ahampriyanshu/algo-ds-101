using System;

namespace palindrome
{
    public class Test
    {
	    public static void Main()
	    {
		    string inp, rev="";
		    inp = Console.ReadLine();
		    
		    for(int i=inp.Length-1 ; i>=0;i--)
		        rev = rev + inp[i].ToString();
		    
		    if(rev.ToLower() == inp.ToLower())
		        Console.WriteLine("True");
		    else
		        Console.WriteLine("False");
		        
	    }
    }
}
