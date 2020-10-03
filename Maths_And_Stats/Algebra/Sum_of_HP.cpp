Harmonic progression is a series whose inverse will be an arithmetic progression. i.e. if for a harmonic progression A1, A2, A3.. An, there is an arithmetic
progression 1/A1, 1/A2, 1/A3.

So, a general HP is :
1/a, 1/(a+d), 1/(a+2d), … 1/(a + nd),where 1/a is the first term and d is the common difference of the reversed AP.

Input:a = 3, d = 2, n = 5
Output:The sum of HP is 0.878211
Execution:Sum = ⅓ + ⅕ + 1/7 + 1/9 + 1/11 = 0.878211

Code:
#include <iostream>
using namespace std;
float findSeriesSum(int a, int d, int n){
   float sumVal = 0;
   float term = 0;
   for(float i = 1; i <= n; i++){
      term = (1.0)/(float)(a + (i-1)*d);
      sumVal += term;
   }
   return sumVal;
}
int main(){
   int n, a, d ;
   cin>>n>>a>>d;
   cout<<"The sum of HP is "<<findSeriesSum(a, d, n);
   return 0;
}
