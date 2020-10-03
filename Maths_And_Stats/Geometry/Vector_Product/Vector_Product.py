"""
LANGUAGE: PYTHON
AUTHOR: Diadochokinetic
GITHUB: https://github.com/Diadochokinetic
"""

def Vector_Product(a, b):
    return [a[1]*b[2] - a[2]*b[1], a[2]*b[0] - a[0]*b[2], a[0]*b[1] - a[1]*b[0]]
