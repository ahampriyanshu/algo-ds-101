"""
author- Ose Oaiya (esoiya)

submission description: The standard deviation is a measure of the amount of variation or dispersion of a set of values
"""

import math

def variance(data, ddof=0):
    """
    Calculate the variance

    param data: data values
    type: list

    param ddof: degrees of freedom
    type: integer
    default: 0 (sample variance calculation)

    set ddof=1 to calculate population variance
    """

    # number of observations
    num = len(data)
    mean = sum(data) / num

    # square the deviations
    deviations = [(x - mean) ** 2 for x in data]

    return sum(deviations) / (num - ddof)


def standard_deviation(data, ddof=0):
    """
    Calculate the standard deviation of the data

    param data: data values
    type: list

    param ddof: degree of freedom
    type: int

    default: 0 (sample standard deviation calculation)

    set ddof=1 to calculate population standard deviation
    """

    var = variance(data, ddof)

    return math.sqrt(var)

