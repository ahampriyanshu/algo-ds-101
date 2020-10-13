#include <bits/stdc++.h>
using namespace std;

double knightProbability(int N, int K, int sr, int sc) 
    {
        vector<vector<double> > dp(N, vector<double>(N));
        int dr[8] = {2, 2, 1, 1, -1, -1, -2, -2};
        int dc[8] = {1, -1, 2, -2, 2, -2, 1, -1};

        dp[sr][sc] = 1;
        for (; K > 0; K--) {
            vector<vector<double> > dp2(N, vector<double>(N));
            for (int r = 0; r < N; r++) {
                for (int c = 0; c < N; c++) {
                    for (int k = 0; k < 8; k++) {
                        int cr = r + dr[k];
                        int cc = c + dc[k];
                        if (0 <= cr && cr < N && 0 <= cc && cc < N) {
                            dp2[cr][cc] += dp[r][c] / 8.0;
                        }
                    }
                }
            }
            dp = dp2;
        }
        double ans = 0.0;
        for (auto row: dp) {
            for (double x: row) ans += x;
        }
        return ans;
    }
    
int main()
{
    int n, k, sr, sc;
    cout << "Please enter size of chessboard, number of moves, starting row and starting column" << endl;
    cin >> n >> k >> sr >> sc;
    cout << "The probability that the knight remains on the board after it has stopped moving is " << knightProbability(n, k, sr, sc) << endl;
    return 0;
}
