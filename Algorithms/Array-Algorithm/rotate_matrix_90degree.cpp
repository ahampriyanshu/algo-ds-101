#include <bits/stdc++.h>
using namespace std;

/*
    Author : codewithrathi
*/

/*
Problem Statement :
Rotate a matrix by 90 degree in clockwise or anticlockwise direction without using any extra space
*/

int main()
{
    int n;

    // Dimension of square matrix
    cout<<"\nEnter the dimension of Matrix : ";
    cin>>n;

    int arr[n][n],ch;

    // matrix
    cout<<"\nEnter the values of Matrix \n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }

    cout<<"Enter your choice (1 or 2) : \n";
    cout<<"[1] anti-clockwise rotation \n";
    cout<<"[2] clockwise rotation \n";

    cin>>ch;

    cout<<"Matrix before rotation :\n\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    if(ch==1)
    {
        for (int i = 0; i < n / 2; i++) 
        { 
            // Consider elements in group of 4 in 
            // current square 
            for (int j = i; j < n-i-1; j++) 
            { 
                // store current cell in temp variable 
                int temp = arr[i][j]; 

                // move values from right to top 
                arr[i][j] = arr[j][n-1-i]; 

                // move values from bottom to right 
                arr[j][n-1-i] = arr[n-1-i][n-1-j]; 

                // move values from left to bottom 
                arr[n-1-i][n-1-j] = arr[n-1-j][i]; 

                // assign temp to left 
                arr[n-1-j][i] = temp; 
            } 
        }
    }
    else if(ch==2)
    {
        for (int i = 0; i < n / 2; i++) 
        { 
            // Consider elements in group of 4 in 
            // current square 
            for (int j = i; j < n-i-1; j++) 
            { 
                // store current cell in temp variable 
                int temp = arr[i][j]; 

                // move values from right to top 
                arr[i][j] = arr[n-1-j][i]; 

                // move values from bottom to right 
                arr[n-1-j][i] = arr[n-1-i][n-1-j]; 

                // move values from left to bottom 
                arr[n-1-i][n-1-j] = arr[j][n-1-i]; 

                // assign temp to left 
                arr[j][n-1-i] = temp; 
            } 
        }
    }
    else
    {
        cout<<"Invalid input";
    }
    if(ch==1 || ch==2)
    {
        cout<<"Matrix after rotation :\n\n";
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }

    }

    return 0;
}


/* 
OUTPUT :
Enter the dimension of Matrix : 4
Enter the values of Matrix 
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
Enter your choice (1 or 2) : 
[1] anti-clockwise rotation 
[2] clockwise rotation 
2
Matrix before rotation :
1 2 3 4 
5 6 7 8 
9 10 11 12 
13 14 15 16 
Matrix after rotation :
13 9 5 1 
14 10 6 2 
15 11 7 3 
16 12 8 4 
...Program finished with exit code 0
Press ENTER to exit console.
*/ 
