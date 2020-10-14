// TypeScript Implementation of Kosarajus's Algorithm

class Graph {
  public vertices: number;
  public adjancency: number[][];
  constructor(vertices: number) {
    this.vertices = vertices;
    this.adjancency = [];
    for (let i = 0; i < vertices; i++) {
      this.adjancency.push([]);
    }
  }

  addEdge(v: number, w: number): void {
    this.adjancency[v].push(w);
  }

  printSCCs(): void {
    var stack: number[] = [];

    let visited: boolean[] = new Array(this.vertices);
    for (let i = 0; i < this.vertices; i++) {
      visited[i] = false;
    }

    for (let i = 0; i < this.vertices; i++) {
      if (visited[i] == false) {
        this.fillOrder(i, visited, stack);
      }
    }

    const gr = this.getTranspose();
    for (let i = 0; i < this.vertices; i++) {
      visited[i] = false;
    }

    while (stack.length != 0) {
      let v = stack.pop() as number;

      if (visited[v] == false) {
        console.log(gr.DFSUtil(v, visited));
      }
    }
  }

  fillOrder(v: number, visited: boolean[], stack: number[]): void {
    // Mark the current node as visited and print it
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex

    for (let i = 0; i < this.adjancency[v].length; i++) {
      let n = this.adjancency[v][i];
      if (!visited[n]) this.fillOrder(n, visited, stack);
    }

    // All vertices reachable from v are processed by now,
    // push v to Stack
    stack.push(v);
  }

  getTranspose(): Graph {
    let g = new Graph(this.vertices);
    for (let v = 0; v < this.vertices; v++) {
      // Recur for all the vertices adjacent to this vertex
      for (let i = 0; i < this.adjancency[v].length; i++) {
        let n = this.adjancency[v][i];
        g.adjancency[n].push(v);
      }
    }
    return g;
  }

  DFSUtil(v: number, visited: boolean[]): string {
    // Mark the current node as visited and print it
    visited[v] = true;
    let result = "";
    result += v + " ";

    // Recur for all the vertices adjacent to this vertex

    for (let i = 0; i < this.adjancency[v].length; i++) {
      let n = this.adjancency[v][i];
      if (!visited[n]) result += this.DFSUtil(n, visited);
    }

    return result;
  }
}

// Create a graph given in the above diagram
let g = new Graph(5);
g.addEdge(1, 0);
g.addEdge(0, 2);
g.addEdge(2, 1);
g.addEdge(0, 3);
g.addEdge(3, 4);

console.log("Following are strongly connected components " + "in given graph ");
g.printSCCs();
