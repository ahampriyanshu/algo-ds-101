 //classes to create the linklist
 class LinkedListNode {
    constructor(char, next) {
      this.value = char;
      this.next = next;
    }
  }
  class LinkedList {
    constructor(chars) {
      const len = chars.length;
      let currentNode = null;
      for (let i = len - 1; i >= 0; i--) {
        let node = new LinkedListNode(chars[i], currentNode);
        currentNode = node;
      }
      this.head = currentNode;
    }
  //function to check if the linked list iws a palindrome
    isPalindrome() {
      let center, slow, quick;
      center = slow = quick = this.head;
      if (slow.next == null) {
        return true;
      }
      while(quick.next != null) {
        slow = slow.next;
        slow.prev = center;
        center = slow
        quick = quick.next
        if (quick.next == null) {
          // even number
          center = slow.prev;
        } else {
          quick = quick.next;
        }
      }
      do {
        if(slow.value !== center.value) {
          return false;
        }
        slow = slow.next;
        center = center.prev;
      } while(slow != null) 
      return true;
    }
  }
var list[];
for(var i =0;i<1)
{
var x=window.prompt("enter the element: ",if done enter DONE);
if(x!=='DONE')
{
 list.push(x);
}
 else{
  i++;
 }
}
  console.log(new LinkedList(list).isPalindrome());
