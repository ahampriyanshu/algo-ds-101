class Generic_Tree_Implementation{
class Node{
    int key;
    Vector<Node >child = new Vector<>();
};
 Node newNode(int key)
{
    Node temp = new Node();
    temp.key = key;
    return temp;
}
  void LevelOrderTraversal(Node root)
{
    if (root == null)
        return;
    Queue<Node > q = new LinkedList<>(); 
    q.add(root); 
    while (!q.isEmpty())
    {
        int n = q.size();
        while (n > 0)
        {
            Node p = q.peek();
            q.remove();
            System.out.print(p.key + " ");
            for (int i = 0; i < p.child.size(); i++)
                q.add(p.child.get(i));
            n--;
        } 
        System.out.println();
    }
}
public static void main(String[] args)
{
    Node root = newNode(10);
    (root.child).add(newNode(2));
    (root.child).add(newNode(34));
    (root.child).add(newNode(56));
    (root.child).add(newNode(100));
    (root.child.get(0).child).add(newNode(77));
    (root.child.get(0).child).add(newNode(88));
    (root.child.get(2).child).add(newNode(1));
    (root.child.get(3).child).add(newNode(7));
    (root.child.get(3).child).add(newNode(8));
    (root.child.get(3).child).add(newNode(9));
 
    System.out.println("Level order traversal " +
                            "Before Mirroring ");
    LevelOrderTraversal(root);
}
}
