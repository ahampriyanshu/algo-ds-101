
def merge_sort(unsorted_array) 
    # if array only has one element or fewer there is nothing to do
    if unsorted_array.length <=1 
        return unsorted_array
    else 
        # dividing and then merge-sorting the halves
        mid = unsorted_array.length/2
        first_half = merge_sort(unsorted_array.slice(0...mid))
        second_half = merge_sort(unsorted_array.slice(mid...unsorted_array.length))
        merge(first_half, second_half)
    end 
end

def merge(left_array, right_array)
    sorted_array = []
    # If either array is empty we don't need to compare them
    while !left_array.empty? && !right_array.empty? do
        # we are shifting out the compared/used values so we don't repeat
        if left_array[0] < right_array[0]
            sorted_array.push(left_array.shift)
        else   
            sorted_array.push(right_array.shift)
        end
    end 
    #concat appends elements of another array to an array
    return sorted_array.concat(left_array).concat(right_array)
end
