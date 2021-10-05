"""
Stooge Sort in Python

The stooge function takes three parameters:
- number_list: list to order
- first: Index of the first item to be ordered on the list. Default is zero.
- last: Index of the last item to be ordered on the list.

The stooge function returns the ordered list
"""
from typing import List
from math import ceil

def stooge(number_list: List[int], last: int, first: int = 0):
    length = last - first + 1

    # Swap first value with last value if first > last
    if number_list[first] > number_list[last]:
        n = number_list[first]
        number_list[first] = number_list[last]
        number_list[last] = n

    # If the length of the section of the list that's being ordered is > 3
    # perform stooge on the first 2/3 of the list, then the last 2/3 of the list 
    # and finally the first 2/3 of the list again 
    if last - first + 1 > 2:
        third = ceil((last - first + 1) / 3)
        
        stooge(number_list, last - third)
        stooge(number_list, last, first + third)
        stooge(number_list, last - third)
    
    return number_list


