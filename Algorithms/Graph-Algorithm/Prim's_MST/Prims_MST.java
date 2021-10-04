
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

class Node {

    int node; // Adjacent node
    int cost; // weight/cost/distance to adjacent node

    Node (int node, int cost) {
        this.node = node;
        this.cost = cost;
    }
}

public class Prims_MST {

    public static int Find_MST(int source_node, List<List<Node>> graph) {


        // Priority queue stores the object node-cost into the queue with 
        // the smallest cost node at the top.
        PriorityQueue<Node> pq = new PriorityQueue<>((a,b)-> a.cost-b.cost);

        // The cost of the source node to itself is 0
        pq.add(new Node(source_node, 0));

        boolean vis[] = new boolean[graph.size()];

        int mst_cost = 0;

        while (!pq.isEmpty()) {

            // remove the smallest element
            Node item = pq.poll();

            int node = item.node;
            int cost = item.cost;

            // If the node is node not yet added to the minimum spanning tree, add it and increment the cost.
            if ( !vis[node] ) {
                mst_cost += cost;
                vis[node] = true;

                // Iterate through all the nodes adjacent to the node taken out of priority queue.
                // Push only those nodes (node, cost) that are not yet present in the minumum spanning tree.
                for (Node pair_node_cost : graph.get(node)) {
                    int adj_node = pair_node_cost.node;
                    if (vis[adj_node] == false) {
                        pq.add(pair_node_cost);
                    }
                }
            }
        }
        return mst_cost;
    }

    public static void main(String args[]) {
    	Scanner sc =new Scanner(System.in);

        int num_nodes = 6; // Nodes (0, 1, 2, 3, 4, 5)

        List<List<Node>> adjGraph = new ArrayList<>(num_nodes);
        for (int i=0; i < num_nodes; i++) {
            adjGraph.add(new ArrayList<>());
        }
        
        for (int i=0; i < num_nodes; i++) {
        	int v1 = sc.nextInt();
        	int v2 = sc.nextInt();
        	int cost = sc.nextInt();
        	adjGraph.get(v1).add(new Node(v2,cost));
        }
        // Start adding nodes to minimum spanning tree with 0 as the souce node
        System.out.println("Cost of the minimum spanning tree in graph 1 : " + Find_MST(0, adjGraph));
        
        sc.close();

    }
}
