# Question: 
# Given a binary tree, check whether it is a mirror of itself
#
# Solution: 
# 
# structure of TreeNode

class TreeNode
  attr_accessor :val, :left, :right

  def initialize(val = 0, left = nil, right = nil)
    @val = val
    @left = left
    @right = right
  end
end

# method to check if Tree is symmetric
def symmetric?(root)
  check_symmetry(root, root)
end

# utility method of symmetric?
def check_symmetry(actual, mirror)
  return true if actual.nil? && mirror.nil?
  return false if actual.nil? || mirror.nil?

  (actual.val == mirror.val) && check_symmetry(actual.left, mirror.right) &&
    check_symmetry(actual.right, mirror.left)
end



#  ===============  Test Cases ============


# sample tree 1   ==> symmetric? => true
#      5
#   4     4
# 1         1


symmetric_tree = TreeNode.new(5)
symmetric_tree.left = TreeNode.new(4)
symmetric_tree.left.left = TreeNode.new(1)
symmetric_tree.right = TreeNode.new(4)
symmetric_tree.right.right = TreeNode.new(1)

symmetric?(symmetric_tree) ? puts('working as expected') : puts('not working as expected')

# sample tree 2   ==> symmetric? => false
#      5
#   3     3
# 2     2


asymmetric_tree = TreeNode.new(5)
asymmetric_tree.left = TreeNode.new(3)
asymmetric_tree.right = TreeNode.new(3)
asymmetric_tree.left.left = TreeNode.new(2)
asymmetric_tree.right.left = TreeNode.new(2)

!symmetric?(asymmetric_tree) ? puts('working as expected') : puts('not working as expected')


# sample tree 3   ==> symmetric? => false
#      5
#   3     4
# 2         1


asymmetric_tree = TreeNode.new(5)
asymmetric_tree.left = TreeNode.new(3)
asymmetric_tree.right = TreeNode.new(4)
asymmetric_tree.left.left = TreeNode.new(2)
asymmetric_tree.right.right = TreeNode.new(1)

!symmetric?(asymmetric_tree) ? puts('working as expected') : puts('not working as expected')





