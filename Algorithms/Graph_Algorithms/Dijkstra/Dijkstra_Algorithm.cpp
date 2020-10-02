//Assuming undirected graphs
#include<bits/stdc++.h>
using namespace std;
/* Creation of Adjacency List */
void addEdge(vector<pair<int,int> > adj[], int u,int v,int w)
{  adj[u].push_back(make_pair(v,w));
   adj[v].push_back(make_pair(u,w)); //Remove this line for using it with directed graphs
   }
   /* Dijkstra Algorithm */
void Dijkstra(vector <pair <int,int> > G[],int n,int source)
{  priority_queue <pair<int,int> > pq; //<distance,vertex>
   int dist[n];
   for(int i=0;i<n;i++)
   {  dist[i]=INT_MAX; }
   pq.push(make_pair(0,source));
   dist[source]=0;
   while(!pq.empty())
   {  int v=pq.top().second;
      pq.pop();
      for(int x=0;x<G[v].size();x++)
      {  int weight=G[v][x].second;
         if(dist[G[v][x].first]>dist[v]+weight)
         {  dist[G[v][x].first]=dist[v]+weight;
            pq.push(make_pair(dist[G[v][x].first],G[v][x].first));
            }
          }
    }
    for(int i=0;i<n;i++)
    { cout<<"Minimum Distance of "<<source<<" from "<<i<<" = "<<dist[i]<<endl; }
  }
  /*Driver*/
  int main()
  {  int V;//vertices
     cin>>V;
     vector<pair<int,int> > g(V);
     int E;//edges
     cin>>E;
     while(E--)
     {  int a,b,w;
        cin>>a>>b>>w;
        addEdge(g,a,b,w);
     }
     Dijkstra(g,V,source);
    }
  
    
       
         
   
   

