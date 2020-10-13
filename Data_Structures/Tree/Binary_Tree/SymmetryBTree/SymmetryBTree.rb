# Question: 
# Given a binary tree, check whether it is a mirror of itself
#
# Solution: 

# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val = 0, left = nil, right = nil)
#         @val = val
#         @left = left
#         @right = right
#     end
# end
# @param {TreeNode} root
# @return {Boolean}
def is_symmetric(root)
    check_symmetry(root, root)
end


def check_symmetry(actual, mirror)
    if actual.nil? and mirror.nil? 
        return true
    end
    if actual.nil? or mirror.nil?
        return false
    end
    (actual.val == mirror.val) and check_symmetry(actual.left, mirror.right) and check_symmetry(actual.right, mirror.left)
end
