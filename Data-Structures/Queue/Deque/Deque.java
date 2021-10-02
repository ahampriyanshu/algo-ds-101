import java.util.ArrayList;
import java.util.List;

public class Deque{
    private List<Integer> deque = new ArrayList<Integer>();
    
    //add element at the beginning of the queue
    public void insertFront(int item){
        System.out.println("element added at front: "+item);
        deque.add(0,item);
        System.out.println(deque);
    }
    
    //add element at the end of the queue
    public void insertRear(int item){
        System.out.println("element added at rear: "+item);
        deque.add(item);
        System.out.println(deque);
    }

    //remove an item from the beginning of the queue
    public void removeFront(){
        if(deque.isEmpty()){
            System.out.println("Deque underflow, unable to remove.");
            return;
        }
        int rem = deque.remove(0);
        System.out.println("element removed from front: "+rem);
        System.out.println(deque);
    }
 
    //remove an item from the beginning of the queue
    public void removeRear(){
        if(deque.isEmpty()){
            System.out.println("Deque underflow, unable to remove.");
            return;
        }
        int rem = deque.remove(deque.size()-1);
        System.out.println("element removed from front: "+rem);
        System.out.println(deque);
    }
 
    //gets the element from the front without removing it
    public int peakFront(){
        int item = deque.get(0);
        System.out.println("Element at first: "+item);
        return item;
    }
     
    //gets the element from the rear without removing it
    public int peakRear(){
        int item = deque.get(deque.size()-1);
        System.out.println("Element at rear: "+item);
        return item;
    }
 
    public static void main(String a[]){
        Deque deq = new Deque();
        deq.insertFront(34);
        deq.insertRear(45);
        deq.removeFront();
        deq.removeFront();
        deq.removeFront();
        deq.insertFront(21);
        deq.insertFront(98);
        deq.insertRear(5);
        deq.insertFront(43);
        deq.removeRear();
    }
}
