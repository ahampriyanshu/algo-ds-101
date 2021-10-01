#include <stdio.h>
int ackermann_peter(int m, int n)
{
    if (m == 0){
        return n+1;
    }
    else if((m > 0) && (n == 0)){
        return ackermann_peter(m-1, 1);
    }
    else if((m > 0) && (n > 0)){
        return ackermann_peter(m-1, ackermann_peter(m, n-1));
    }
}

int main(){
    //accept values
    int ackermann_result, num1, num2;
    scanf("%d %d", &num1, &num2);

    //compute the result and print it
    ackermann_result = ackermann_peter(num1, num2);
    printf("%d", ackermann_result);
    return 0;
}
