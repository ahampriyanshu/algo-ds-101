array = Array[4,456,45,657,34,8,987,1,78,50]

size = array.size

min = 0

for i in 0..size
    for j in (i+1)..size
        if array[j-1] < array[i-1]
            min = array[j-1]
            array[j-1] = array[i-1]
            array[i-1] = min
        end
    end
end

puts array
