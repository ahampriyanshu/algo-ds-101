
import java.util.ArrayList;
import java.util.Scanner;

public class Array {

	public static void main(String[] args) {
		//Scanner to get input
		Scanner sc = new Scanner(System.in);
		//ArrayList to dynamic array elements
		ArrayList elements = new ArrayList();
		//While loop for iterating dynamically
		while(true) {
			String element = sc.next();
			//Enter exit when done entering the elements
			if(element.equalsIgnoreCase("exit")) {
				break;
			}
			elements.add(element);
		}
		//Printing the elements
		for(int i=0;i<elements.size();i++) {
			System.out.print(elements.get(i)+" ");
		}
		

	}

}
