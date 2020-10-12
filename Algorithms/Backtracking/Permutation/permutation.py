def permutation(arr):
    if(len(arr) == 1):
        return [arr]
    
    result = []

    for i in arr:
        #Array excluding i element
        sub_arr = [j for j in arr if j != i]
        p = permutation(sub_arr)

        for k in p:
            temp = [i]+k
            result.append(temp)

    return result
