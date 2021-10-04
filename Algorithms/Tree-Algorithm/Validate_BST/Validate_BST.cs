using System;

internal class Node
{
    public int value;
    public Node left, right;

    public Node(int item)
    {
        value = item;
        left = right = null;
    }
}

public class Validate_BST
{
    static bool IsBST(
        Node node,
        int currentMinimum = Int32.MinValue,
        int currentMaximum = Int32.MaxValue)
    {
        if (node == null)
        {
            return true;
        }

        if (node.value < currentMinimum || node.value > currentMaximum)
        {
            return false;
        }

        return (IsBST(node.left, currentMinimum, node.value - 1) &&
                IsBST(node.right, node.value + 1, currentMaximum));
    }

    public static void Main(string[] args)
    {
        Node treeRoot1 = new Node(7);
        treeRoot1.left = new Node(5);
        treeRoot1.right = new Node(8);
        treeRoot1.left.left = new Node(4);
        treeRoot1.left.right = new Node(6);
        Console.WriteLine(IsBST(treeRoot1) ? "This tree is a BST" : "This tree is not a BST");

        Node treeRoot2 = new Node(2);
        treeRoot2.left = new Node(6);
        treeRoot2.left.right = new Node(5);
        treeRoot2.right = new Node(1);
        treeRoot2.right.left = new Node(8);
        treeRoot2.right.right = new Node(10);
        Console.WriteLine(IsBST(treeRoot2) ? "This tree is a BST" : "This tree is not a BST");
    }
}
