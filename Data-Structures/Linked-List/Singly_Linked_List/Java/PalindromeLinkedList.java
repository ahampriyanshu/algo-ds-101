

  class ListNode {
     int val;
     ListNode next;
     ListNode() {}
     ListNode(int val) { this.val = val; }
     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 }

class LinkedList {
	private ListNode head;
	public void addToTheLast(ListNode node) {
		 
		if (head == null) {
			head = node;
		} else {
			ListNode temp = head;
			while (temp.next != null)
				temp = temp.next;
 
			temp.next = node;
		}
	}
 
	
    public boolean isPalindrome(ListNode head) {
    ListNode fast = head, slow = head;
    while (fast != null && fast.next != null) {
        fast = fast.next.next;
        slow = slow.next;
    }
    if (fast != null) { // odd nodes: let right half smaller
        slow = slow.next;
    }
    slow = reverse(slow);
    fast = head;
    
    while (slow != null) {
        if (fast.val != slow.val) {
            return false;
        }
        fast = fast.next;
        slow = slow.next;
    }
    return true;
}

public ListNode reverse(ListNode head) {
    ListNode prev = null;
    while (head != null) {
        ListNode next = head.next;
        head.next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
}


 class PalindromLinkedList{
 public static void main(String args[]){
	 LinkedList list = new LinkedList();
	 ListNode head=new ListNode(1);
		list.addToTheLast(head);
		list.addToTheLast(new ListNode(2));
		list.addToTheLast(new ListNode(1));
		list.addToTheLast(new ListNode(4));
		list.addToTheLast(new ListNode(1));

  
  if(list.isPalindrome(head)){
    System.out.println("Linked List is Palindrome!");
 }else{
    System.out.println("Linked List is Not Palindrome!");
  }
}
 
}
