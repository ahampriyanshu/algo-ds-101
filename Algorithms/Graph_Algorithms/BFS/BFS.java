//Implementation of BFS in java

//importing the libraries
import java.util.*;

//declaring the class name
public class Graph {
  //declaring the variables
  private int V;
  private LinkedList<Integer> list[];

  // creating a graph
  Graph(int v) {
    V = v;
    list = new LinkedList[v];
    for (int i = 0; i < v; ++i)
      list[i] = new LinkedList();
  }

  //adding edges to graph
  void addEdge(int v, int w) {
    list[v].add(w);
  }

  //implementation of algorithm
  void BFS(int s) {

    boolean visit[] = new boolean[V];
    LinkedList<Integer> q = new LinkedList();

    visit[s] = true;
    q.add(s);

    while (q.size() != 0) {
      res = q.poll();
      System.out.print(res + " ");

      Iterator<Integer> i = adj[s].listIterator();
      while (i.hasNext()) {
        int num = i.next();
        if (!visit[num]) {
          visit[num] = true;
          q.add(num);
        }
      }
    }
  }

  public static void main(String args[]) {
    Graph graph1 = new Graph(4);

    graph1.addEdge(0, 1);
    graph1.addEdge(0, 2);
    graph1.addEdge(1, 2);
    graph1.addEdge(2, 0);
    graph1.addEdge(2, 3);
    graph1.addEdge(3, 3);

    System.out.println("Breadth First Traversal(BFS) is as follows: " + "(start from vertex position 2)");

    graph1.BFS(2);
  }
}
