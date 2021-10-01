package main

import "fmt"

func max(x, y int) int {
	if x < y {
		return y
	}
	return x
}

func sol(s1 string, s2 string, n int, m int) int {
	dp := make([][]int, n+1)
	for i := 0; i <= n+1; i++ {
		dp[i] = make([]int, m+1)
	}
	for i := 1; i <= n; i++ {
		for j := 1; j <= m; j++ {
			if s1[i-1] == s2[j-1] {
				dp[i][j] = 1 + dp[i-1][j-1]
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1])
			}
		}
	}
	return dp[n][m]
}

func main() {
	var t int
	fmt.Scanf("%d", t)
	for _ = 0; t >= 0; t-- {
		var s1, s2 string
		fmt.Scanf("%s", s1)
		fmt.Scanf("%s", s2)

		n, m := len(s1), len(s2)
		raw_res := sol(s1, s2, n, n)
		res := n + m - raw_res
		fmt.Printf("%d\n", res)
	}
}
