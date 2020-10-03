"""
LANGUAGE: PYTHON
AUTHOR: cdefga
GITHUB: https://github.com/cdefga
"""

import numpy as np


def n_dimensional_distance(a: np.ndarray, b: np.ndarray) -> float:
    assert a.shape == b.shape, 'dimension of input must be equal'
    dist = np.sqrt(np.sum((a - b)**2))
    return dist


if __name__ == '__main__':
    a = np.array([1,2,3,4])
    b = np.array([1,2,3,5])
    dist = n_dimensional_distance(a, b)
    print(dist)