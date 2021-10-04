// Lowest Common Ancestor of a Binary Tree

/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {TreeNode}
 */

var lowestCommonAncestor = function (root, p, q) {
  if (!root || root === p || root === q) return root;
  var left = LCA(root.left, p, q); // left traversal
  var right = LCA(root.right, p, q); // right traversal
  return left && right ? root : left || right;
};
