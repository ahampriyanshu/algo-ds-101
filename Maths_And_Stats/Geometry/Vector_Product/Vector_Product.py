"""
LANGUAGE: PYTHON
AUTHOR: Diadochokinetic
GITHUB: https://github.com/Diadochokinetic
"""

def Vector_Product(a, b):
    return [a[1]*b[2] - a[2]*b[1], a[2]*b[0] - a[0]*b[2], a[0]*b[1] - a[1]*b[0]]

def float_input(string_input):
    return [float(element) for element in string_input.split()]

if __name__ == '__main__':
    a = float_input(input("Please enter a vector containing 3 elements, e.g. 1 2 3: "))
    b = float_input(input("Please enter another vector containing 3 elements, e.g. 4 5 6: "))
    print(f'The vector product for {a} and {b} is: {Vector_Product(a, b)}')
