function ackermann_peter(m, n){
    if(m===0){
        return n+1
    }else if (n===0){
        return ackermann_peter(m-1, 1)
    }else{
        return ackermann_peter(m - 1, ackermann_peter(m, n-1))
    }
}

//Example
let result = ackermann_peter(1, 2)
// this should return 4
