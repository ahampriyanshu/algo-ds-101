#include <iostream>
#include <vector>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
int n=5;
void DFS(int matrix[5][5], int visit[],int visitTo=0){
    cout<<(char)(visitTo+65)<<" ";
    visit[visitTo]=1;
    for(int i=0; i<5; i++){
        if(matrix[visitTo][i] && !visit[i])
            DFS(matrix,visit,i);
    }
}
void BFS(int matrix[5][5], int visit[], int row=0){
    int queue[n];
    int top =-1, i, bottom =-1;
    visit[row]=1;
    queue[++bottom] = row;
    cout<<(char)(row+65)<<" ";
    while(top != bottom){
        row= queue[++top];
        for(i=0; i<n; i++){
            if(matrix[row][i] && !visit[i]){
                visit[i]=1;
                cout<<row<<" "<<(char)(i+65)<<" ";
                queue[++bottom] =i;
            }
        }
    }
}
int main()
{
   int matrix[5][5]={ {0,0,3,0,4}, {0,0,6,0,1},{3,6,0,5,0},{0,0,5,0,7},{4,1,0,7,0} };
   int visit[5]={0};
    DFS(matrix,visit);
    return 0;
}
//Contributed by Vaishnavi Shah