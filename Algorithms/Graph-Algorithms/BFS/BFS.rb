def bfs(node)
  return nil if node.nil? || root.nil? # nothing to do if there is no node or root to begin the search
  queue = Queue.new
  queue.enq(root)
  result = nil
  while !queue.empty?
    value = queue.deq
    if value.title == node.title && value.rating == node.rating
      result = value
      break
    end

    # keep moving the levels in tree by pushing left and right nodes of tree in queue
    queue.enq(value.left) if value.left
    queue.enq(value.right) if value.right
  end

  result # returns node found in BST else default value nil
end
