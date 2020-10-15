import java.util.HashSet; 
public class CheckDuplicateValues { 
   
    public static boolean checkDupUtil(Node root, HashSet<Integer> s)  
    {  
        if (root == null)  
            return false;  
        if (s.contains(root.data))  
            return true;  
        s.add(root.data);  
        
        return checkDupUtil(root.left, s) || checkDupUtil(root.right, s);  
    }  
    
    public static boolean checkDup(Node root)  
    {  
        HashSet<Integer> s=new HashSet<>(); 
        return checkDupUtil(root, s);  
    }  
  
    public static void main(String args[]) { 
        Node root = new Node(1);  
        root.left = new Node(2);  
        root.right = new Node(2);
        root.left.left = new Node(3);
        root.left.right = new Node(4);
        if (checkDup(root))  
            System.out.print("Yes This tree contains Duplicates value.");  
        else
            System.out.print("No duplicates values exist");  
    } 
} 
class Node {  
    int data;  
    Node left;
    Node right;
    Node(int data) 
    { 
        this.data=data; 
    } 
}; 
