 // LinkedList is a very useful and famous data structure which is linear in nature. This data structure is used to add elements dynamically without any fixed memory size. 
 // This feature makes it advantageous over simple arrays, where initially the array size gets fixed and which may result in unused extra memory or shortange of memory size.

//Here we try to implement in-built LinkedList in java and see some of its methods like add(),addFist(),addLast(),remove(),removeFirst(),removeLast(),set()..etc.

//This package has the LinkedList class(which implements List interface.
import java.util.*;
class LinkedListDemo{
  public static void main(String args[]){
    //This is how we initialise a linkedlist named 'list' with Data type as String which will be stored.
    LinkedList<String> list=new LinkedList<String>();
    
    Scanner sc=new Scanner(System.in);
    System.out.println("Enter the number strings to be added in list initially");
    int n=sc.nextInt();
    while(n-->0){
     String str=sc.next();  //Use this to input from user.
     list.add(str);  //keep on adding the strings.
    }
    //The list elements get added one after the other and its printed as in order.
    System.out.println(list);
    
   // we can use other methods like addFirst() and addLast() to add elements at the beginning and the last
    System.out.println("Enter the string you want to add at the beginning");
    String starting_str=sc.next();
    list.addFirst(starting_str);
    
    System.out.println("Enter the string you want to add at the ending");
    String ending_str=sc.next();
    list.addLast(ending_str); 
    
    
    
    System.out.println("Updated list->"+list);    
    
    //Other common methods are removing elements from front and last;
    list.removeFirst();
    list.removeLast();
    
    System.out.println("Updated list after deleting first and last node->"+list);
    
    String str1=list.getFirst();
    String str2=list.getLast();
    
    System.out.println("First Node is"+str1);
    System.out.println("Last Node is"+str2);
    
    //Since its indexed, we can also set element at specified position and also remove by specifying the position
    System.out.println("Enter the index and String you want to insert at");
    int ind=sc.nextInt();
    String new_str=sc.next();
    list.set(ind,new_str); 
 
    list.addFirst("LinkedList DEMO from @PrakashAditya17::");  //Random string added here
   
    System.out.println("UPDATED LIST->"+list); 
    System.out.println("Enter the position of any String you want to remove");
    int ind_remove=sc.nextInt();
    list.remove(ind_remove);       
    
   //For iteration we can use use the following way.
    for(String ele : list)
      System.out.print(ele+",");
  }
}
