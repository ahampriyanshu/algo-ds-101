import java.util.*;

public class Main {
    public static void main(String[] args) {
GenericTreeImplementation tree= new GenericTreeImplementation();
    }
}
class GenericTreeImplementation {
    class Node {
        int d;
        ArrayList<Node> child;

        Node(int d) {
            this.d = d;
            child = new ArrayList<>();
        }
    }

    private Node r;

    GenericTreeImplementation() {
        Scanner s = new Scanner(System.in);
        this.r = good(s, null, 0);
    }

    private Node good(Scanner s, Node parent, int i) {
        if (parent == null) {
            System.out.println("Enter info for root node");
        } else {
            System.out.println("Enter info for " + i + "th child of " + parent.d);
        }
        int d = s.nextInt();
        Node node = new Node(d);
        System.out.println("Enter the number of child for" + node.d);
        int n = s.nextInt();

        for (int k = 0; k < n; k++) {
            Node children = good(s, node, k);
            node.child.add(children);
        }
        return node;
    }
}
