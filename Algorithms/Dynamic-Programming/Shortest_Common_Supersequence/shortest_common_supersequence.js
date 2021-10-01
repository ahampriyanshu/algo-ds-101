const readline = require('readline')
const reader = readline.createInterface(process.stdin, process.stdout); 

function shortestCommonSuperstring(str1, str2) {
    let m = str1.length, n = str2.length
    let dp = Array(m+1)
    for(let i=0;i<=m;++i) {
        dp[i] = Array(n+1)
        for(let j=0;j<=n;++j) {
            if(i === 0)
                dp[i][j] = j
            else if(j === 0)
                dp[i][j] = i
            else if(str1.charAt(i-1) === str2.charAt(j-1))
                dp[i][j] = 1 + dp[i - 1][j - 1]
            else
                dp[i][j] = 1 + Math.min(dp[i - 1][j], dp[i][j - 1])
        }
    }
    return dp[m][n]
}

reader.question('Enter two string seperated by space: ', string => {
    let string_arr = string.split(" ")
    console.log("Length of the shortest supersequence is " + shortestCommonSuperstring(string_arr[0], string_arr[1]))
    reader.close()
})
