//Detecting a cycle in singly linked list
import java.util.*;

class Node {
//class describing structure of the node
  int data;
  Node next;
  Node(int value) { 
    data = value; 
    next = null;
    }
 }
 
 class Solution{
 
 //creates a new linked list;
    public void create_list(Node head,int node_value){
    Node newNode = new Node(node_value);
    if(head==null){
      head = newNode;
      }
    else{
      Node pointer = head;
      while(pointer.next!=null)
        pointer = pointer.next;
      pointer.next = newNode;
    } 
  }
  
  //detects cycle in list
  public boolean hasCycle(Node head) {
        Node fast=head,slow=head;
        if(head==null || head.next==null)
            return false;
        while(fast!=null && fast.next!=null)
        {
            slow = slow.next;
            fast = fast.next.next;
            if(fast==slow)
                return true;  
        }
        return false;
    }
 }
 
 //main class
 public class CycleDetection{
  public static void main(String[] args){
    Solution object = new Solution();
    Node head = new Node(10);
    object.create_list(head,20);
    object.create_list(head,30);
    object.create_list(head,40);
    object.create_list(head,50);
    head.next.next.next = head;
    boolean answer = object.hasCycle(head);
    if(answer==true)
      System.out.println("Cycle is present");
    else
      System.out.println("Cycle is not present");
    
  }
}
