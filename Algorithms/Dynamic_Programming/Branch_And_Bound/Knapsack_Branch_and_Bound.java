import java.io.*;
import java.util.*;

public class Knapsack_Branch_and_Bound {
	
	static boolean sol_found = false;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	//Node of Branch and Bound tree
	static class Node {
		int lvl, val;       //lvl indicates depth of current node
		double cap, bound;
		Node next;

		Node(int lvl, int val, double cap, double bound) {
			this.lvl = lvl;
			this.val = val;
			this.cap = cap;
			this.bound = bound;
			this.next = null;
		}
	}
	
	//List to store node of Branch and Bound tree
	static class List {
		Node head;
	
		//add node in list in such a way that list always stay sorted in descending order by bound value of nodes
		void add(Node n)
		{
			if(this.head == null)
				head = n;
			else
			{
				Node temp = this.head;
				if(n.bound >= temp.bound) {
					n.next = temp;
					this.head = n;
				}
				else {
					while(temp.next != null && n.bound < temp.next.bound)
						temp = temp.next;

					if(temp.next != null)
						n.next = temp.next;
					temp.next = n;
				}
			}
		}
		
		//returns the node with maximum upper bound i.e. the first node
		//in the list since list is always sorted in descending order
		Node get() {
			Node n = head;
			head = n.next;
			n.next = null;
			return n;
		}
	}
	
	
	static class Item {
		double weight;
		int value;
		
		Item(double weight, int value) {
			this.weight = weight;
			this.value = value;
		}
	}
	
	//to sort the item array by value/weight in descending order
	static class Sort_Value_By_Weight implements Comparator<Item> {
		public int compare(Item a, Item b) {
			double x, y;
			x = a.value / a.weight;
			y = b.value / b.weight;
			if(x > y)
				return -1;
			else if(x == y)
				return 0;
			return 1;
		}
	}
	
	//get upperbound for a node of depth k
	static double upperBound(Item item[], double cap, int k, int n) {
		int i;
		double tot_val = 0;
		i = k;
		while(cap > 0 && i < n)
		{
			if(item[i].weight <= cap)
				tot_val += item[i].value;
			else
				tot_val += (1.0 * item[i].value / item[i].weight) * cap;
			cap -= item[i].weight;
			i++;
		}
		return tot_val;
	}
	
	//Solves 0-1 knapsack by branch and bound technique
	static void knapsackBnB(Item[] item, int n, Node curr, List list)
	{
		if(curr.lvl == n && curr.cap >= 0) {
			System.out.println("Max Value: " + curr.val);
			sol_found = true;
		}

		else if(curr.cap >= 0) {
			int k = curr.lvl;
			Node temp;
			
			//right child of current node
			temp = new Node(k+1, curr.val, curr.cap, curr.val + upperBound(item, curr.cap, k+1, n));
			list.add(temp);
			
			//left child of current node
			curr = new Node(k+1, curr.val + item[k].value, curr.cap - item[k].weight, curr.bound);

			//function call itself for left child of current node
			//since it is the node with current max upperbound
			knapsackBnB(item, n, curr, list); 
			if(!sol_found)
				knapsackBnB(item, n, list.get(), list);//call the function for max value of node in list
		}
	}

	public static void main(String[] args) throws IOException{
		int i, n;
		double cap;
		
		System.out.print("Enter no. of Items: ");
		n = Integer.parseInt(br.readLine());

		Item[] item = new Item[n];

		System.out.println("Enter weight-value pair :-");
		for(i=0; i<n; i++) {
			st = new StringTokenizer(br.readLine());
			item[i] = new Item(Double.parseDouble(st.nextToken()), Integer.parseInt(st.nextToken()));
		}

		System.out.print("Enter capacity of knapsack: ");
		cap = Double.parseDouble(br.readLine());

		//Sort the Item array by value/weight in descending order
		Arrays.sort(item, new Sort_Value_By_Weight());

		List list = new List();
		list.head = null;
		//root of the branch and bound tree
		Node curr = new Node(0, 0, cap, upperBound(item, cap, 0, n));

		knapsackBnB(item, n, curr, list);
	}
}

