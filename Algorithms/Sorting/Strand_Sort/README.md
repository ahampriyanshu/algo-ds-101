## Strand Sort

First, begin a sublist by moving the first item from the original list to the sublist. For each subsequent item in the original list, if it is greater than the last item of the sublist, remove it from the original list and append it to the sublist. Merge the sublist into a final, sorted list. Repeatedly extract and merge sublists until all items are sorted. Handle two or fewer items as special cases.

For Example :
Input : ip[] = {10, 5, 30, 40, 2, 4, 9}
Output : op[] = {2, 4, 5, 9, 10, 30, 40}
