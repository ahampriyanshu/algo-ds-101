import java.util.*;

class Node {
//class describing structure of the tree node
  int value;
  Node left;
  Node right;
  Node(int value) { 
    this.value = value; 
    left = right = null;
    }
 }
 
 class Solution {
 //Recursive functions to determine whether given tree is valid BST or not
    public boolean isValidBST(Node root) {
        return helper(root,null,null);
    }
    public boolean helper(Node root, Integer small, Integer large) 
    {
        if(root==null)
            return true;
        if(small!=null && root.val<=small)
            return false;
        if(large!=null && root.val>=large)
            return false;
        return helper(root.left,small,root.val) && helper(root.right,root.val,large);
    }
}

public class Validate_BST
{
//main class
  public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        Solution object = new Solution();
        Node TreeRoot1 = new Node(10);
        TreeRoot1.left = new Node(5);
        TreeRoot1.right = new Node(12);
        TreeRoot1.left.left = new Node(4);
        TreeRoot1.left.right = new Node(6);
        boolean answer1 = object.isValidBST(TreeRoot1);
        if(answer1==true)
          System.out.println("Tree is a valid BST");
        else
          System.out.println("Tree is not a valid BST");

        Node TreeRoot2 = new Node(2);
        TreeRoot2.left = new Node(6);
        TreeRoot2.right = new Node(1);
        TreeRoot2.left.right = new Node(5);
        TreeRoot2.right.left = new Node(8);
        TreeRoot2.right.right = new Node(11);
        boolean answer2 = object.isValidBST(TreeRoot2);
        if(answer2==true)
          System.out.println("Tree is a valid BST");
        else
          System.out.println("Tree is not a valid BST");

  }
}
