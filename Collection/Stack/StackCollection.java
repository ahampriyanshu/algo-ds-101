import java.io.*;
import java.util.*;

public class StackCollection{
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Stack<Integer> st = new Stack<Integer>(); //create a object of class stack
        //Adding 5 elements to the stack
        int n = 5; 
        for(int i=0;i<n;i++){
            int element = input.nextInt();
            st.push(element);   //add element to the stack
        }

        int top = st.peek(); //get topmost element
        System.out.println(top); 

        st.pop(); //removes the top most element from stack and return's it

        int sizeOfStack = st.size(); // return's size of stack

        if(st.empty()){ // if stack is empty return's true
            System.out.println("Stack is empty");
        }else{
            System.out.println("Stack is not empty");
        }// Print's stack is not empty.
    }
}