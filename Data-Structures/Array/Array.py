#  Kadanes algorithm
#  BY this algorithm we find the maximum sum that can come from an array
ls = [-2, 1, 0, 5, -3]
max_so_far = 0
max_till_here = 0
for i in range(len(ls)):
    max_so_far = ls[i]
    if max_so_far <= 0:
        max_so_far = 0
    max_till_here += max_so_far

print(max_till_here)
