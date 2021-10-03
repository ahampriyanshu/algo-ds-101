import java.util.*;
public class Linkedlist
{
	public static void main(String args[])
	{
		// create Integer type linked list
		LinkedList<Integer> linkedList = new LinkedList<>();
		
		//adding elements :-)
		linkedList.add(1);
		linkedList.add(2);
		linkedList.add(3);
		
		//printing linkedlist
		System.out.println("LinkedList:" + linkedList);
		
		
		
		
		// create String type linked list
		LinkedList<String> linkedList1 = new LinkedList<>();
		
		//adding elements ;-)
		linkedList1.add("Java");
		linkedList1.add("Python");
		linkedList1.add("JavaScript");
		
		
		//printing linkedlist
		System.out.println("LinkedList1: " + linkedList1);
		
		
		//ACCESS ELEMENTS : GET()
		String str = linkedList1.get(1);
		System.out.println("Element: " + str);
		
		//CHANGE ELEMENTS : SET()
		linkedList1.set(2, "HTML");
		System.out.println("Updated LinkedList: " +  linkedList1);
		
		//REMOVE ELEMENTS : REMOVE()
		String str1 = linkedList1.remove(1);
		System.out.println("Removed Element: " + str1);
		System.out.println("Updated LinkedList: " + linkedList1);
		
		//ELEMENT PRESENT/NOT : CONTAINS()
		if(linkedList.contains(1))
			System.out.println("TRUE");
		
		// GETTING INDEX OF SPECIFIC ELEMENT : INDEXOF()
		if(linkedList.contains(3))
			System.out.println(linkedList.indexOf(3));
		
		// LAST INDEX OF ELEMENT : LASTINDEXOF()
		System.out.println(linkedList1.lastIndexOf("HTML"));
		
		//TO REMOVE ALL ELEMENTS OF LINKEDLIST : CLEAR()
		linkedList.clear();
		System.out.println(linkedList);
		
		
		// LINKEDLIST AS QUEUE AND DEQUE
		
		//ADD ELEMENT IN THE BEGINNING : ADDFIRST()
		linkedList.addFirst(2021);
		System.out.println(linkedList);
		
		
		// ADD ELEMENT AT THE END : ADDLAST()
		linkedList.addLast(1200);
		System.out.println(linkedList);
		
		// PEEK() -> RETRUNS THE FIRST ELEMENT OF THE LINKEDLIST
        System.out.println(linkedList1.peek());

		// POLL() -> RETURNS AND REMOVES THE FIRST ELEMENT FROM THE LINKEDLIST
		linkedList.poll();
		System.out.println(linkedList);
		
		
		
		
		
	}
}
