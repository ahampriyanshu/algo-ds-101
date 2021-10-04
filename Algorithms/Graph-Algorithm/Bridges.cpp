//In graph theory, a bridge is an edge of a graph whose deletion increases the graph's number of connected components.
//For more information on it visit the following link:-https://en.wikipedia.org/wiki/Bridge_(graph_theory)

#include<bits/stdc++.h> 
using namespace std;
// let's make a dfs(depth first search for the graph) function for the multiple components.


void dfs(int node,int parent,vector<bool>&vis,vector<int>&t_vis,vector<int>&low_t,
	int  &timer,vector<int> adj[],vector<pair<int,int>> &ans){
	//first mark the node visited.
	vis[node] = true;
	//Now first we assume visiting time and the lowest time to visit is equal and equal to timer.
	//Also as its adjacent nodes are going to be visited later so we also increase the timer.
	t_vis[node] = low_t[node] = timer++;

	//Now let's traverse its adjacent nodes.
	for(auto it:adj[node]){
		//if it's a parent so there is no need to traverse it as we already came from there.
		if(it==parent)	continue;

		//If the adjacent node is not visited than we make dfs on it.
		if(!vis[it]){
			dfs(it,node,vis,t_vis,low_t,timer,adj,ans);

			//Now update the minimum time to visit current node from it's adjacent.

			low_t[node] = min(low_t[node],low_t[it]);

			//If minimum time to visit the adjacent node is greater than the visiting time than it is a bridge.

			if(low_t[it] > t_vis[node]){
				ans.emplace_back(make_pair(node,it));
			}
		}
		// If the node is alredy visited than check the later case of visiting time.
		else{
			low_t[node] = min(low_t[node] , low_t[it]);
		}
	}
}
int main(){
	// take input of the number of nodes and the number of edges in the graph.
	int node,edges;
	cin >> node >> edges;
	//take graph input in form of adjacency list .
	vector<int> adj[node];
	for(int i = 0;i<edges;i++){
		//take input of the nodes between which there is an edge
		int u,v;
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	//Declare three vectors:-
	//1.For the time we visited the node .
	//2.Minimum time needed to visit this node according to its adjacent node.
	//3.If the current node is visited or not.
	vector<int> t_vis(node,-1);
	vector<int> low_t(node,-1);
	vector<bool> vis(node,false);

	//Now for every unvisited node check for the bridge and store all the bridges in a vector of Pairs.

	vector<pair<int,int>> ans;
	// Declare the timer variable for marking the visiting time.
	int time = 0;
	for(int i = 0;i<node;i++){
		if(!vis[i]){
			//every unvisited node have no parent so mark that as -1.
			dfs(i,-1,vis,t_vis,low_t,time,adj,ans); 
		}
	}
	//Now print the bridges.
	cout << "\n";
	for(auto i:ans){
		cout << i.first << ' ' << i.second << "\n";
	}

}
