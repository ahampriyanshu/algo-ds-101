## QUICK SORT

Quick sorting is almost similar like merge sorting but in quick sorting the element named pivot is chose which can be any element of the array. There are many different versions of quicksort that pick pivot in different ways. After choosing pivot all the elements are compared with the pivot element and if it satisfies the condition the two adjacent get swapped otherwise it remain as it is.

	a. Always pick first element as pivot.
	b. Always pick last element as pivot (implemented below)
	c. Pick a random element as pivot.
	d. Pick median as pivot.
       
**For example:**
[3 5 9 7] in this lets 7 be the pivot. Condition is (pivot < number) then swap.
7 is greater than 3: No change [3 5 9 7].
7 > 5: No change [3 5 9 7].
9 > 7: Swap [3 5 7 9]
Output: [3 5 7 9]

