""" The main aim of this problem is to find the 
minimum and maximum value of a unimodal function
using the ternary search algorithm."""


"""This is the amount of error we are ready to tolerate in our answer."""
PRECISION = 0.0000001

""" the unimodal function whose maxima has to be found.
Let the range be [-10^9,10^9]"""
def func1(x):
    return -x*x-2*x+3;

"""the unimodal function whose minima has to be found.
Let the range be [-10^9,10^9]"""
def func2(x):
    return x*x-2*x+3;


"""To find the maxima of a function we go in the following way:
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
"""

def find_maxima(l,r):
    if(abs(l-r)<=PRECISION):
        return func1(l)
    else:
        m1 = l+(r-l)/3;
        m2 = l+2*(r-l)/3;
        if(func1(m1)<func1(m2)):
            return find_maxima(m1,r)
        elif(func1(m1)>func1(m2)):
            return find_maxima(l,m2)
        return find_maxima(m1,m2);

"""
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
"""

def find_minima(l,r):
    if(abs(l-r)<=PRECISION):
        return func2(l);
    else:
        m1 = l+(r-l)/3;
        m2 = l+2*(r-l)/3;
        if(func2(m1)<func2(m2)):
            return find_minima(l,m2)
        elif(func2(m1)>func2(m2)):
            return find_minima(m1,r)
        return find_minima(m1,m2)


def main_func():
    print("maxima for func1: ", end="")
    print(find_maxima(-1000000000,1000000000))
    print("minima for func2: ", end ="")
    print(find_minima(-1000000000,1000000000))

main_func();