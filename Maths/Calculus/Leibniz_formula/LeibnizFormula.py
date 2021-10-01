from sympy import *
from math import comb
'''
requirements 
    - pip install sympy
'''


def leibniz_formula(u, v, n: int):
    '''
    Compute the nth order derivative of the product of two functions u and v

    Parameters
    ----------
    u : function
        function with one variable - x
    v : function
        function with one variable - x
    n : integer
        the order of the derivative to be computed

    Returns
    -------
    function
        nth order derivative of the product of u and v computed 
        using leibniz formula
    '''

    x = symbols('x')
    f = 0
    for i in range(n+1):
        f += comb(n, i) * diff(u, x, n-i) * diff(v, x, i)
    return simplify(f)


x = symbols('x')

# examples

# 1
u = exp(x)
v = sin(x)
n = 4
f = leibniz_formula(u, v, n)
print(f"The {n}th order derivative of {u}*{v} is : {f}")

# 2
u = x
v = log(x)
n = 10
f = leibniz_formula(u, v, n)
print(f"The {n}th order derivative of {u}*{v} is : {f}")
