 function tribonacci (num) {
    if (num === 0 || num === 1 || num === 2){
       return 0;
    };
    if (num == 3){
       return 1;
    }else{
       return tribonacci(num - 1) +
       tribonacci(num - 2) +
       tribonacci(num - 3);
    }
 }
 function trib (num)  {
    let arr = [];
    for (let i = 1; i <= num; i++){
       arr.push(tribonacci(i));
    };
    return arr
};
 //printing first 20 tribonacci numbers 
 console.log(trib(20));