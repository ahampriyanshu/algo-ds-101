#include <iostream> 
#include <cmath>
#define EPS 1e-8
using namespace std;

double a, b, c, d;

double f(double x){
    return a*x*x*x + b*x*x + c*x + d;
}

double binsearch(double l, double r)
{
    double x = (l + r)/2;
    
    
    if(fabs(f(x)) < EPS) return x;

    if(f(x) > EPS) return binsearch(l, x);
    else return binsearch(x, r);
    
}

int main(){

    cin >> a >> b >> c >> d;
    
    if(a < 0){
        a *= -1;
        b *= -1;
        c *= -1;
        d *= -1;
    }

    int r = 1;
    while(f(r) * f(-r) >= 0){
        r *= 2;
    }
    
    printf("%.8f\n", binsearch(-r, r));
    return 0;
}
