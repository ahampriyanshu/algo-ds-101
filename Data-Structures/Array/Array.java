
import java.util.ArrayList;
import java.util.Scanner;

public class Array {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		ArrayList elements = new ArrayList();
		while(true) {
			String element = sc.next();
			if(element.equalsIgnoreCase("exit")) {
				break;
			}
			elements.add(element);
		}
		for(int i=0;i<elements.size();i++) {
			System.out.print(elements.get(i)+" ");
		}
		

	}

}
