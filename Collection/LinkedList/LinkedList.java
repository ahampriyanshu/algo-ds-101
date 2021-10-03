import java.util.*;
import java.lang.*;
import java.io.*;


// This file two methods for LinkedList insert and print

class Node{
	int data;
	Node next;
	Node(int data){
	this.data=data;
	this.next=null;
	}
}

class LinkedListMethods{
	Node head=null;
	Node tail=null;
	public void insert(int data){ // Insert method will insert the node at the end of the list and update the tail.
		Node newNode=new Node(data);
		if(head==null){
			head=newNode;
			tail=newNode;
		}
		else{
			tail.next=newNode;
			tail=tail.next;
		}

	}
	public void print(){ // This method will print the entire list space seperated.
		Node travalNode=head;
		while(travalNode!=null){
			System.out.print(travalNode.data+" ");
			travalNode=travalNode.next;
		}
		System.out.println();
	}
}
public class LinkedList{
	public static void main(String[] args) {
		LinkedListMethods methods= new LinkedListMethods();
		methods.insert(1);
		methods.insert(3);
		methods.insert(4);
		methods.insert(8);
		methods.insert(9);
		methods.insert(10);
		methods.print();
	}
}