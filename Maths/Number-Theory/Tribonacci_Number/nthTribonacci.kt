fun nthTribonacci(n: Int): Int{
    
    //create a dp array of size n+1 filled with 0's
    val dp = IntArray(n+1){0}
    for(i in 0..n){
        if(i < 3)
            dp[i] = i/2 
        //since first three elements are 0, 0 and 1
        //so we can cleverly write dp[i] = i/2
        else 
        //otherwise, the sum of preceeding three values is the ith Tribonacci
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3]
    }
    return dp[n]
}

fun main(){
    
    //read input value of n
    val n = readLine()!!.toInt()
    
    //print the corresponding output
    println(nthTribonacci(n))
}