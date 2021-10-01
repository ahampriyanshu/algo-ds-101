#include <iostream>

using namespace std;

int main()
{
    //The number of test cases
    cout << "Enter the number of testcases" << endl;
    int t;
    scanf("%d", &t);
    while(t--){
        int n,rem,ans=0;
        printf("Enter a Number: ");
        scanf("%d", &c);

        int n1=n;
        while(n1>0){
            rem = n1%10;
            ans = ans + (rem*rem*rem);
            n1 = n1/10;
        }

        if(ans == n)
             printf("The number %d is an armstrong number", n);
        else
            printf("The number %d is not an armstrong number", n);
    }
