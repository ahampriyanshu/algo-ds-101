
# arr array to be sorted
# n number of elements in array
# buckets instance of buckets
# m  elements in a are supposed between 0..m - 1
#
def bucket_sort(arr, n, buckets, m)
    for j in 0...m
      buckets[j] = 0
    end
    for i in 0...n
      buckets[arr[i]] += 1
    end
    i = 0
    for j in 0...m
      for k in 0...buckets[j]
        arr[i] = j
        i += 1
      end
    end
  end