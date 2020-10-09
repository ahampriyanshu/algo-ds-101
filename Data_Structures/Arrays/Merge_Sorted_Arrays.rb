def merge_sorted_arrays(arrays)
    return [] if arrays.length == 0
    return arrays[0] if arrays.length == 1
  
    # 1. Using built-in methods
    # arrays.flatten.sort!

    # 2. Not using built-in methods
    full_array = arrays.inject([], :+)
    sort(full_array)
end

def sort(num_arr)
    return num_arr if num_arr.size <= 1

    mid = num_arr.length / 2
    left = num_arr[0...mid]
    right = num_arr[mid...num_arr.size]

    merge(sort(left), sort(right))
end
  
def merge(left, right)
    sorted = []
    until left.empty? || right.empty?
        if left.first <= right.first
            sorted << left.shift
        else
            sorted << right.shift
        end
    end
    sorted.concat(left).concat(right)
end

# Test example
arrays = [
    [1, 4, 5],
    [1, 3, 220],
    [2, 6, 15, 1000],
    [4, 10, 33]
]

p merge_sorted_arrays(arrays)
