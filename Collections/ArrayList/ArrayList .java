import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Arraylist {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		//Array List implementation
		ArrayList<Integer> number = new ArrayList<Integer>();
		//Entering elements from 1 to 5 using add method
		for(int i=1;i<=5;i++) {
			number.add(i);
		}
		//size() method can be used to tell number of elements in the list
		for(int i=0;i<number.size();i++) {
			//Printing the array elements using get method
			System.out.print(number.get(i)+" ");
		}
		//To insert an element at specified index
		number.add(2,7);
		ArrayList<Integer> newlist = new ArrayList<Integer>();
		for(int i=10;i<=15;i++) {
			newlist.add(i);
		}
		//To add another list elements to previous list
		number.addAll(newlist);
		//To delete all elements in a list
		newlist.clear();
		System.out.println();
		//To check whether the list is empty or not
		if(newlist.isEmpty()) {
			System.out.println("The list is empty");
		}
		//To get index of an element
		int index = number.indexOf(new Integer(7));
		//To remove the element with index
		number.remove(index);
		//We can also sort an list using
		Collections.sort(number);
		for(int i=0;i<number.size();i++) {
			System.out.print(number.get(i)+" ");
		}
		

	}

}
