def heap_sort(array)  
    size = array.length
    #Adding an empty element at beginning of array to be the root
    root_array = [nil] + array            
    
    i = size / 2 
    while i > 0 do
      heapify(root_array, i, size) 
      i -= 1 
    end  

    while size > 1  do
      root_array[1], root_array[size] = root_array[size], root_array[1]  
      size -= 1  
      heapify(root_array, 1, size)  
    end  
    root_array.shift #getting rid of the initial nil
    root_array                  
  end  
    
  def heapify(a, parent, limit)  
    root = a[parent]  

    while (child_node = 2 * parent) <= limit  do
        if child_node < limit and a[child_node] < a[child_node + 1]  
            child_node += 1 
        end 
        break  if root >= a[child_node]  
        a[parent] = a[child_node]  
        parent = child_node  
    end  
    a[parent] = root 
  end  
