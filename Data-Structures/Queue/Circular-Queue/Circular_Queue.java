public class Circular_Queue {

	static class Node { 
		int value; 
		Node link; 
	} 

	static class CircularQueue { Node first, last; } 

	static void Insert(CircularQueue cq, int value) { 
		Node n = new Node(); 
		n.value = value; 

		if (cq.first == null) {
			cq.first = n; 
		} else { cq.last .link = n; }

		cq.last = n; 
		cq.last.link = cq.first; 
	} 

	static int Delete(CircularQueue cq) { 
		if (cq.first == null) { 
			System.out.printf ("Circular Queue is empty"); 
			return Integer.MIN_VALUE; 
		} 

		int value; 

		if (cq.first == cq.last) { 
			value = cq.first.value; 
			cq.first = null; 
			cq.last = null; 
		} else { 
			Node n = cq.first; 
			value = n.value; 
			cq.first = cq.first.link; 
			cq.last.link = cq.first; 
		} 

		return value ; 
	} 

	static void displayCircularQueue( CircularQueue cq) { 
		Node n = cq.first; 
		System.out.printf("\nElements in Circular Queue are: "); 
		while (n.link != cq.first) { 
			System.out.printf("%d ", n.value); 
			n = n.link; 
		} 
		System.out.printf("%d", n.value); 
	} 

	public static void main(String[] args) {

		CircularQueue cq = new CircularQueue(); 
		cq.first = cq.last = null; 

		System.out.println("Inserting value = 69");
		Insert(cq, 69); 
		System.out.println("Inserting value = 12");
		Insert(cq, 12); 
		System.out.println("Inserting value = 42");
		Insert(cq, 42); 

		displayCircularQueue(cq); 

		System.out.printf("\nDeleting value = %d", Delete(cq)); 
		System.out.printf("\nDeleting value = %d", Delete(cq)); 

		displayCircularQueue(cq); 

		System.out.println();
		System.out.println();
		System.out.println("Inserting value = 21");
		Insert(cq, 21); 
		System.out.println("Inserting value = 3");
		Insert(cq, 3); 
		displayCircularQueue(cq); 
	}
}
