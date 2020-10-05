"""
LANGUAGE: PYTHON
AUTHOR: Diadochokinetic
GITHUB: https://github.com/Diadochokinetic
"""

from operator import mul

def Scalar_Product(x, y):
    return sum(map(mul, x, y))

def float_input(string_input):
    return [float(element) for element in string_input.split()]

if __name__ == '__main__':
    a = float_input(input("Please enter a vector containing n elements, e.g. 1 2 3: "))
    b = float_input(input("Please enter another vector containing n elements, e.g. 4 5 6: "))
    print(f'The scalar product for {a} and {b} is: {Scalar_Product(a, b)}')
