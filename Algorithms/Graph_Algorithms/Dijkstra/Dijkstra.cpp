//This program is used to implement Dijkstra's Algorithm using priority queue(min heap)

//Time Complexity: O(ElogV)

#include<iostream>
#include<list>
#include<utility>
#include<queue>

using namespace std;

typedef pair<int,int> ipair;      

class Graph{
    int v;
    list<ipair> *adj;
    public:
        Graph(int v);
        void Edge(int edge,int weight,int vertex);
        void dijkstra_pq(int src);
};

Graph::Graph(int v){
    this->v=v;
    adj=new list<ipair> [v];

}
void Graph::Edge(int u, int v, int w) 
{ 
    adj[u].push_back(make_pair(v, w)); 
    adj[v].push_back(make_pair(u, w)); 
} 

void Graph::dijkstra_pq(int src){
    priority_queue<ipair,vector<ipair>,greater<ipair>> pq;  //This is the syntax of creating a min heap using priority queue

    // Create a vector for distances and initialize all 
    // distances as infinite (INF) 

    vector<int> dist(v,INT16_MAX);

    //Insert source itself in priority queue and initialize 
    // its distance as 0. 

    pq.push(make_pair(0,src));
    dist[src]=0;
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        
        for(auto i=adj[u].begin();i!=adj[u].end();i++){
            int V=(*i).first;
            int w=(*i).second;
            if(dist[V]>dist[u]+w){       // Edge Relaxation
                dist[V]=dist[u]+w;
                pq.push(make_pair(dist[V],V));
            }
        }
    }

    // Print shortest distances stored in dist[] 
    
    cout<<"Vertex\t\tDistance"<<endl;
    for(int i=0;i<v;i++){
        cout<<i<<"\t\t"<<dist[i]<<endl;
    }
}

int main(){
    int v=9;
 Graph g(v);
    g.Edge(0, 1, 4); 
    g.Edge(0, 7, 8); 
    g.Edge(1, 2, 8); 
    g.Edge(1, 7, 11); 
    g.Edge(2, 3, 7); 
    g.Edge(2, 8, 2); 
    g.Edge(2, 5, 4); 
    g.Edge(3, 4, 9); 
    g.Edge(3, 5, 14); 
    g.Edge(4, 5, 10); 
    g.Edge(5, 6, 2); 
    g.Edge(6, 7, 1); 
    g.Edge(6, 8, 6); 
    g.Edge(7, 8, 7); 

    g.dijkstra_pq(0);
    return 0;
}


