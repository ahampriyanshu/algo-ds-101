#include <bits/stdc++.h>
using namespace std;

void init() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

void dfs(vector<int> graph[], int node, bool *visited, vector<int> &ordering) {
	visited[node] = true;
	for (int neigh : graph[node]) {
		if (!visited[neigh]) {
			dfs(graph, neigh, visited, ordering);
		}
	}
	// Ordering based on finish time. Finish Time: When you are going back after visiting all its neighbours
	ordering.push_back(node);
}
// Normal dfs call after reversing the graph
void dfs2(vector<int> rev_graph[], int node, bool *visited) {
	visited[node] = true;
	cout << node << ",";
	for (int neigh : rev_graph[node]) {
		if (!visited[neigh]) {
			dfs2(rev_graph, neigh, visited);
		}
	}
}
void solve(vector<int> graph[], vector<int> rev_graph[], int V) {
	bool visited[V] = {0};
	vector<int> ordering;

	for (int i = 0; i < V; i++) {
		if (!visited[i]) {
			dfs(graph, i, visited, ordering);
		}
	}

	char component_name = 'A';

	memset(visited, 0, V);
	for (int x = ordering.size() - 1; x >= 0; x--) {
		int node = ordering[x];
		if (!visited[node]) {
			cout << "Component " << component_name << "--> ";
			// There is a component starting from this node
			dfs2(rev_graph, node, visited);
		}
		cout << endl;
		component_name++;
	}
}

int main() {
	init();
	int V, E;
	cin >> V >> E;
	vector<int> graph[V], rev_graph[V];
	for (int i = 0; i < E; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);

		// graph where all the directed edges are reversed in the original graph
		rev_graph[y].push_back(x);
	}
	// Strongly Connected Components
	solve(graph, rev_graph, V);
	return 0;
}
