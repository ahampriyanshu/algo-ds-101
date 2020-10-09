/*Problem description 
Given a m * n matrix of ones and zeros return 
how many square submatrices have all ones.*/

#include<bits/stdc++.h>
using namespace std;
//----------------------FUNCTION_DECLARATION----------------------------
    int countSquares(vector<vector<int>>& matrix) 
    {
        int result=0;
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(matrix[i][j]>0 && i>0 && j>0)
                {
                    matrix[i][j]=min(matrix[i-1][j],min(matrix[i-1][j-1],matrix[i][j-1]))+1;
                    
                }
                result+=matrix[i][j];
            }
        }
        
        return result;
    }
//--------------------------MAIN_FUNCTION----------------------------------------------------

int main()
{
	int n,m; //number_of_rows and number_of_columns
    cin>>n>>m;
    vector<vector<int>>matrix(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<m;j++)
    		cin>>matrix[i][j];
    }
//-------------------------FUNCTION_CALLING-----------------------------------------
    
	int number_sq_matrices = countSquares(matrix);

//-------------------------PRINTING_RESULT------------------------------------------------------

	cout<<number_sq_matrices<<endl;
//---------------------------------------------------------------------------------------------
	return 0;
}


