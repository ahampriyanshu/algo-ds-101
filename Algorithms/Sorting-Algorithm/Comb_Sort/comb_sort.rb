# The gap starts with a large value and shrinks by a factor of 1.3 in every iteration until it reaches the value 1.
def comb_sort(arr)
    gap = arr.length
   
    while gap > 1
        i = 0
        gap /= 1.3
        gap = gap.to_i
        while arr[i + gap]
            if arr[i] > arr[i + gap]
                temp = arr[i]
                arr[i] = arr[i + gap]
                arr[i + gap] = temp
            end
            i += 1
        end
    end
    arr
end
