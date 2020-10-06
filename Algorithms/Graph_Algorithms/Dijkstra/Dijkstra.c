#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int getMinVertex(bool* visited,int* distance,int n){
	int minVertex = -1;
	for(int i=0;i<n;i++){
		if( !visited[i] && ( (minVertex==-1) || (distance[i]<distance[minVertex]) )  ){
			minVertex = i;
		}
	}
	return minVertex;
}

void dijkstra(int** edges,int n){
	bool* visited = (bool*) calloc(sizeof(bool),n);
	int* distance = (int*) calloc(sizeof(int),n);
	for(int i=1;i<n;i++) distance[i] = INT_MAX;

	for(int i=0;i<n-1;i++){
		int minVertex = getMinVertex(visited,distance,n);
		visited[minVertex] = true;
		for(int j=0;j<n;j++){
			if(!visited[j] && (edges[minVertex][j]))
				if( distance[j] > (edges[minVertex][j]+distance[minVertex]) ){
					distance[j] = edges[minVertex][j] + distance[minVertex];
				}
		}

	}

	for(int i=0;i<n;i++){
		printf("%d %d\n",i,distance[i]);
	}

}

int main(){
	int n,e;
	printf("Enter number of vertices and the number of edges:\n");
	scanf("%d%d",&n,&e);
	int** edges = (int**) calloc(sizeof(int*),n);
	for(int i=0;i<n;i++) edges[i] = (int*)calloc(sizeof(int),n);

	printf("Enter the edges along with its weight:\n");
	for(int i=0;i<e;i++){
		int a,b,w;
		scanf("%d%d%d",&a,&b,&w);
		edges[a][b] = edges[b][a] = w;
	}

	dijkstra(edges,n);

	return 0;
}
