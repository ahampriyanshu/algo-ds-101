class Node: 
  def __init__(self,data): 
    self.data=data; 
    self.next=None;
    self.previous=None;

class DoubleLinkedList:
  def __init__(self): 
    self.start=None;
    
  def merge(self,a,b): 
    if (a==None): 
      return b; 
    if (b==None): 
      return a;
    if (a.data < b.data): 
      a.next=self.merge(a.next,b); 
      a.next.previous=a; 
      a.previous=None;
      return a; 
    else: 
      b.next=self.merge(a,b.next); 
      (b.next).previous=b;
      b.previous=None;
      return b;
  def mergesort(self,head): 
    if (head==None): 
      return head; 
    if (head.next==None): 
      return head; 
    b = self.div(head); 
    head = self.mergesort(head); 
    b = self.mergesort(b);
    return self.merge(head,b); 
 
  def div(self,head): 
    first=last=head; 
    while(True): 
      if (first.next==None): 
        break;
      if ((first.next).next==None): 
        break;
      first=(first.next).next;
      last=last.next;
      
    t=last.next;
    last.next=None;
    return t; 
     
  def insert(self,d):  
    n=Node(d); 
    n.next=self.start; 
 
    if (self.start!=None): 
      self.start.previous=n; 
    self.start=n; 
  
  def display(self,node):  
    t=node;
    while(node!=None): 
      print (node.data); 
      t=node; 
      node=node.next;

ob=DoubleLinkedList();
inp=int(input("Enter the number of nodes you want to enter:"));
for i in range(inp):
        j=int(input("Enter the data of the node:"));
        ob.insert(j);
ob.start=ob.mergesort(ob.start) 
print ("\nDisplaying the double linked list after merge sort (in ascending order):");
ob.display(ob.start);