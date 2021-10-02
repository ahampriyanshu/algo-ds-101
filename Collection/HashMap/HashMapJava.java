import java.util.*;
public class HashMapJava{
    public static void main(String[] args) {
        HashMap<Integer, Integer> hm = new HashMap<Integer, Integer>(); //create a hashmap object

        hm.put(1,2); // insert key value pair
        int val = hm.get(1); //return's the value 2
        System.out.println(val);

        int size = hm.size(); // return's the number of key value pairs present in java

        if(hm.containsKey(1)){ //return's true if 1 is present in hashmap
            System.out.println("Yeaaaa contains key 1");
        }

        if(hm.isEmpty() == true){ //if hashmap is empty it return's true
            System.out.println("Hashmap hm is empty");
        }

        hm.remove(1); // remove's '1' the key and it's corresponding value
    }
}