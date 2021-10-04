
def depth_first_search(search_value, tree)
  stack = [tree]
  visited = [tree]

  while !stack.empty?
    current = stack.last
    left, right = current.left, current.right

    if current.value == search_value
      puts current
      exit
    elsif !left.nil? && !visited.include?(left)
      if left.value == search_value
        puts left
        exit
      else
        visited << left
        stack << left
      end
    elsif !right.nil? && !visited.include?(right)
      if right.value == search_value
        puts right
        exit
      else
        visited << right
        stack << right
      end
    else
      stack.pop
    end
  end
  puts "nil"
end
