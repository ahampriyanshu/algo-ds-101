#include<bits/stdc++.h>
using namespace std;

// This is the amount of error we are ready to tolerate in our answer.
#define PRECISION 0.0000001

// The main aim of this problem is to find the 
// minimum and maximum value of a unimodal function
// using the ternary search algorithm.


// the unimodal function whose maxima has to be found
// Let the range be [-10^9,10^9]
double func1(double x){
    return -x*x-2*x+3;
}
// the unimodal function whose minima has to be found
// let the range be [-10^9,10^9]
double func2(double x){
    return x*x-2*x+3;
}

/*To find the maxima of a function we go in the following way:
1. We choose any two points m1 and m2 such that l<=m1<=m2<=r.
2. if func(m1)<func(m2){
        we go for the range [m1,r]
    }
    else if func(m1)>func(m2){
        we go for the range [l,m2]
    }
    else{
        we reduce our space to [m1,m2]
    }
 3. Step 2 is repeated with same conditions until we reach our desired precision value in
    our result.  
*/

double find_maxima(double l, double r){
    if(abs(l-r)<=PRECISION) return func1(l);
    else{
        double m1 = l+(r-l)/3;
        double m2 = l+2*(r-l)/3;
        if(func1(m1)<func1(m2))
            return find_maxima(m1,r);
        else if(func1(m1)>func1(m2))
            return find_maxima(l,m2);
        return find_maxima(m1,m2);
    }
}

/*
To find the minima of a unimodal function we have to do the following task:
1. We choose any two points m1 and m2 such that l<=m1<=m2<=r.
2. if func(m1)<func(m2){
        we go for the range [l,m2]
    }
    else if func(m1)>func(m2){
        we go for the range [m1,r]
    }
    else{
        we reduce our space to [m1,m2]
    }
 3. Step 2 is repeated with same conditions until we reach our desired precision value in
    our result. 
*/

double find_minima(double l, double r){
    if(abs(l-r)<=PRECISION) return func2(l);
    else{
        double m1 = l+(r-l)/3;
        double m2 = l+2*(r-l)/3;
        if(func2(m1)<func2(m2))
            return find_minima(l,m2);
        else if(func2(m1)>func2(m2))
            return find_minima(m1,r);
        return find_minima(m1,m2);
    }
}


int main(){
    cout<<"maxima for func1: ";
    cout<<find_maxima(-1000000000,1000000000)<<endl;
    cout<<"minima for func2: ";
    cout<<find_minima(-1000000000,1000000000)<<endl;
    return 0;
}