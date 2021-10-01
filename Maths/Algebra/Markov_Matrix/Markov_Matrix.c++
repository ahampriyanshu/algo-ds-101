#include <bits/stdc++.h> 
using namespace std; 

  
int main()  
{ 
    int i ,j ,n,m;
    cout << "Enter Number of Rows and Columns :- " << "\n";
    cin >> n >> m;
    double Matrix[n][m]; 
    cout << "Enter Matrix Elements :- " << "\n";
    for (i = 0; i < n; i++)
    {
        for(j = 0 ; j < m;j++)
            cin >> Matrix[i][j];
    }
    int flag = -1;
    for(i = 0; i <n; i++) 
    { 
        double sum = 0; 
        for (j = 0; j < m; j++) 
            sum = sum + Matrix[i][j]; 
        if (sum != 1)
        {
            flag = 1;
            break;
        }        
    }
    
    if (flag == 1) 
        cout << "Not a Markov Matrix" << "\n"; 
    else
        cout << "Yes , It's a Markov Matrix" << "\n"; 
        
} 