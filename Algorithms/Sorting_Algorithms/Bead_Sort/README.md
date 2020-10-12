## BEAD SORTING:

Bead Sort is also known as Gravity Sort.

This algorithm was inspired from natural phenomenons and was designed keeping in beads of abacus in mind falling under the influence of gravity.

**For Example:**
1. Imagine a abacus sorted in a pattern of 7,2,1,4,2. Now, imagine that this is the position of the beads at time t = 0 and with every passing second the beads will fall down by one level provided there is no bead already present below them. In such a case, they just rest upon the bead below them.

2. Now, at time t = 1 the bottom 2 beads in the first two rods from the left stay at their positions while the second bead from the top from the second rod comes down by one level to rest upon the bead below it. The beads in the 3rd and 4th rod at level 2 come down to level 1. Simultaneously, the beads in the rods 3 to 7 come down by one level. Now, the numbers from top to bottom become: 2, 6, 2, 2, 4.

3. This goes on till time t = 4 where we get the sorted sequence of numbers from top to bottom which is: 1, 2, 2, 4, 7.

So, INPUT: 7,2,1,4,2.
OUTPUT: 2,6,2,2,4.
