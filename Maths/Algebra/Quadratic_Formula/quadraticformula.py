# -*- coding: utf-8 -*-
"""
Created on Sat Oct  3 03:34:46 2020

@author: Erik

Quadratic formula
"""
import math as m

a = int(input("constant 'a' for x^2: "))

b = int(input("constant 'b' for x^1: "))

c = int(input("free constant 'c': "))

print("the function is ", a, "x^2 + ", b, "x + ", c)
#f = a*x^2 + b*x + c

root = (b**2) - (4*a*c)
x1 = (-b + m.sqrt(root))/(2*a)
x2 = (-b - m.sqrt(root))/(2*a)

print("x1 = ", x1, ". and x2 = ", x2)