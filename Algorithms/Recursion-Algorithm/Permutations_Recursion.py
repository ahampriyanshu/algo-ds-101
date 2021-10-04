def convert(a):
    new_list = []
    for i in a:
        demo = "".join(i)
        new_list.append(demo)

    return new_list

def permutation(s):
    if len(s) == 1:
        return [s]

    perm_list = [] # resulting list
    for a in s:
        remaining_elements = [x for x in s if x != a]
        z = permutation(remaining_elements) # permutations of sublist using recursion

        for t in z:
            perm_list.append([a] + t)

    return perm_list


sample = input()
print(convert(permutation(sample)))
