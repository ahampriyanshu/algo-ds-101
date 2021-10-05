#include <bits/stdc++.h>
#define int long long int
using namespace std;

int dis[21][21];
int dp[21][(1 << 21)];

int solve(int i, int mask, int n)
{
    if (mask == 0)
    {
        return dp[i][mask] = dis[i][0];
    }
    if (dp[i][mask] != -1)
    {
        return dp[i][mask];
    }
    int ans = INT_MAX;
    for (int j = 0; j < n; j++)
    {
        if (mask & (1 << j))
        {
            ans = min(ans, dis[i][j] + solve(j, (mask ^ (1 << j)), n));
        }
    }
    return ans;
}

signed main()
{
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> dis[i][j];
        }
    }
    cout << solve(0, (1 << n) - 1, n);
}
