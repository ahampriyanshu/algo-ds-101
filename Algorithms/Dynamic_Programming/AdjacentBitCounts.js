const readline = require('readline')
const reader = readline.createInterface(process.stdin, process.stdout)

function countStrings(n, k) {
    let dp = Array(n+1)
    for(let i=0;i<n+1;++i) {
        dp[i] = Array(k+1)
        for(let j=0;j<k+1;++j)
            dp[i][j] = Array(2).fill(0)
    }
    dp[1][0][0] = 1
    dp[1][0][1] = 1
    for (let i=2;i<=n;i++) {
        for (let j=0;j<i&&j<k+1;j++) {
            dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1]
            dp[i][j][1] = dp[i-1][j][0]
            if (j-1>= 0) {
                dp[i][j][1] += dp[i-1][j-1][1]
            }
        }
    }
    return dp[n][k][0] + dp[n][k][1]
}

reader.question("Enter 'N' and 'K' seperated by space: ", data => {
    const arr = data.split(" ")
    console.log("Answer: " + countStrings(parseInt(arr[0]), parseInt(arr[1])))
    reader.close()
})
