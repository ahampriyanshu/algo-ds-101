/*
Problem description:
For a string of n bits x1,x2,x3,...,Xn the adjacent bit count of the string (AdjBC(x)) is given by
X1*X2 + X2*X3 + X3*X4 + ... + Xn-1 * Xn

which counts the number of times a 1 bit is adjacent to another 1 bit. For example:
AdjBC(011101101) = 3
AdjBC(111101101) = 4
AdjBC(010101010) = 0

Write a program which takes as input integers n and k and returns the number of bit strings x of n bits 
(out of 2ⁿ) that satisfy AdjBC(x) = k.

Link To Problem: https://www.spoj.com/problems/GNYR09F/
*/

#include <bits/stdc++.h>
using namespace std;
//find Number of bit string with Adjacent Bit count k.
int findAns(int n, int k, int firstBit, int ***dp)
{
    //Base cases
    if (k < 0)
        return 0;
    if (dp[n][k][firstBit] != -1)
        return dp[n][k][firstBit];

    /*There are 2 cases
      1. If First bit of binary string is assigned '1'
      2. If first bit of binary string is assigned '0' 
    */
    int option1, option2;
    if (firstBit == 1)
    {
        option1 = findAns(n - 1, k - 1, 1, dp);
        option2 = findAns(n - 1, k, 0, dp);
    }
    else
    {
        option1 = findAns(n - 1, k, 1, dp);
        option2 = findAns(n - 1, k, 0, dp);
    }
    long long ans = (option1 + option2) % 1000000007;
    dp[n][k][firstBit] = (int)ans;
    return dp[n][k][firstBit];
}
int main()
{           /*
      [Problem Link : https://www.spoj.com/problems/GNYR09F/]
      Input Format is taken from Problem Link
    */
    int ts; //testcases
    cin >> ts;
    while (ts--)
    {
        int index, num, k;
        cin >> index >> num >> k;

        /*creating a dp array for storing previous state answers.
          Since dp array will depend on number of bits,k(Adjacent bit count) & firstbit(0 or 1)
          therefore dp will be 3d array.*/
        int ***dp = new int **[num + 1];
        for (int i = 0; i <= num; i++)
            dp[i] = new int *[k + 1];

        for (int i = 0; i <= num; i++)
        {
            for (int j = 0; j <= k; j++)
                dp[i][j] = new int[2];
        }
        //initialising dp
        for (int i = 0; i <= num; i++)
        {
            for (int j = 0; j <= k; j++)
                dp[i][j][0] = -1, dp[i][j][1] = -1;
        }
        dp[1][0][0] = dp[1][0][1] = 1;
        for (int i = 1; i <= k; i++)
            dp[1][i][0] = 0, dp[1][i][1] = 0;

        //calling function to find ans.
        int ans1 = findAns(num, k, 1, dp);
        int ans2 = findAns(num, k, 0, dp);
        long long int ans = (ans1 + ans2) % 1000000007;
        cout << index << " " << ans << endl;

        //deleting dp array
        delete dp;
    }
    return 0;
}
