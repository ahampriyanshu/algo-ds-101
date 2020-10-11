def bubble_sort(array)
  length = array.size
  return array if length <= 1 # for 0 or 1 items arrays

  loop do
    # we need to create a variable to avoid an infinite loop
    swapped = false

    # subtract one because it starts from index 0
    (length-1).times do |i|
      if array[i] > array[i+1]
        # swapping numbers
        array[i], array[i+1] = array[i+1], array[i] 
        swapped = true
      end
    end

    break if not swapped
  end

  array
end

test_array = [11,13,12,1,2,3]
p bubble_sort(test_array)

# output: [1, 2, 3, 11, 12, 13]
