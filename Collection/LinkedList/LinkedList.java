 // LinkedList is a very useful and famous data structure which is linear in nature. This data structure is used to add elements dynamically without any fixed memory size. 
 // This feature makes it advantageous over simple arrays, where initially the array size gets fixed and which may result in unused extra memory or shortange of memory size.

//Here we try to implement in-built LinkedList in java and see some of its methods like add(),addFist(),addLast(),remove(),removeFirst(),removeLast(),set()..etc.

//This package has the LinkedList class(which implements List interface.
import java.util.*;
class LinkedListDemo{
  public static void main(String args[]){
    
    Scanner sc=new Scanner(System.in);
    //String str=sc.next();  //Use this to input from user.
    
    //This is how we initialise a linkedlist named 'list' with Data type as String which will be stored.
    LinkedList<String> list=new LinkedList<String>();
    
    
    //Take some inputs and add the elements
    list.add("Hi");
    list.add("Welcome to");
    list.add("Hacktoberfest 2k21");
    
    //The list elements get added one after the other and its printed as in order.
    System.out.println(list);
    
    //But we can use other methods like addFirst() and addLast() to add elements at the beginning and the last
    list.addFirst("Lets begin here");
    list.addFirst("START DEMO from @PrakashAditya17");
    list.addLast("Lets do some open source contribution");
    list.addLast("ENDING DEMO");
    
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
    list.set(1,"Hello");  //"Hi" gets replaced with "Hello"
    list.remove(2);       //"Welcome to" is removed here
    
    System.out.println("FINAL LIST->"+list); 
    
    //For iteration we can use use the following way.
    for(String ele : list){
      System.out.print(ele+",");
  }
}
