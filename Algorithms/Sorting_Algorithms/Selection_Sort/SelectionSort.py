def selection_sort(lst):
    for i in range(len(lst) - 1):
        k = min(range(i, len(lst)), key=lst.__getitem__)
        lst[i], lst[k] = lst[k], lst[i]
    return lst
         
lst = [8,3,6,2]
print(selection_sort(lst))
