import numpy as np


def riemann_sum(f, a, b, N: int, method='midpoint'):
    '''
    Compute the Riemann sum of f(x) over the interval [a,b].

    Parameters
    ----------
    f : function
        Vectorized function of one variable
    a , b : numbers
        Endpoints of the interval [a,b]
    N : integer
        Number of subintervals of equal length in the partition of [a,b]
    method : string
        Determines the kind of Riemann sum:
        right : Riemann sum using right endpoints
        left : Riemann sum using left endpoints
        midpoint (default) : Riemann sum using midpoints

    Returns
    -------
    float
        Approximation of the integral given by the Riemann sum.
    '''
    dx = (b - a)/N
    x = np.linspace(a, b, N+1)

    # left riemann sum
    if method == 'left':
        x_left = x[:-1]
        return np.sum(f(x_left)*dx)

    # right reimann sum
    elif method == 'right':
        x_right = x[1:]
        return np.sum(f(x_right)*dx)

    # midpoint reimann sum
    elif method == 'midpoint':
        x_mid = (x[:-1] + x[1:])/2
        return np.sum(f(x_mid)*dx)
    else:
        raise ValueError("Method must be 'left', 'right' or 'midpoint'.")


# example problems

# 1
f = np.sin
r_sum = riemann_sum(f, 0, np.pi/2, 100)
right_r_sum = riemann_sum(f, 0, np.pi/2, 100, 'right')
left_r_sum = riemann_sum(f, 0, np.pi/2, 100, 'left')
print(f"""Sin(x) in the interval [0,pi/2] partition with 100 sub-intervals
Left Riemann Sum: {left_r_sum}
Midpoint Riemann Sum: {r_sum}
Right Riemann Sum: {right_r_sum}""")


# 2
f = lambda x : 1 / (1 + x**2)
r_sum = riemann_sum(f, 0, 5, 10)
right_r_sum = riemann_sum(f, 0, 5, 10, 'right')
left_r_sum = riemann_sum(f, 0, 5, 10, 'left')
print(f"""
1/(1+x^2) in the interval [0,5] partition with 10 sub-intervals
Left Riemann Sum: {left_r_sum}
Midpoint Riemann Sum: {r_sum}
Right Riemann Sum: {right_r_sum}""")
