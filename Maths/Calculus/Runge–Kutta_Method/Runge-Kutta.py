import numpy as np


def dydx(x, y):
    return 2*x + np.sin( x * y )


x0 = float(input("Enter value of x0:- "))
y0 = float(input("Enter value oy y0:- "))
h = float(input("Enter step size:- "))
n = int(input("Enter number of points."))

y_vec = np.zeros((n, 1))
y_vec[0] = y0
x_vec = np.zeros((n, 1))
x_vec[0] = x0
for i in range(n-1):
    xi, yi = x_vec[i], y_vec[i]
    k1 = dydx(xi, yi)
    k2 = dydx(xi + h/2, yi + h*k1/2)
    k3 = dydx(xi + h/2, yi + h*k2/2)
    k4 = dydx(xi + h, yi + k3)
    x_vec[i+1] = xi + h
    y_vec[i+1] = yi + h / 6 * (k1 + 2*k2 + 2*k3 + k4)

print("--- Results ---")
print("x    |   y")
print(np.array([x_vec, y_vec]).T)
