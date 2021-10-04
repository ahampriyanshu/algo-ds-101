/**
 * Definition for binary tree node.
 * class TreeNode {
 *     public $val = null;
 *     public $left = null;
 *     public $right = null;
 *     function __construct($val = 0, $left = null, $right = null) {
 *         $this->val = $val;
 *         $this->left = $left;
 *         $this->right = $right;
 *     }
 * }
 */

class Solution {//Recursive solution for level order traversal

    /**
     * @param TreeNode $root
     * @return Integer[][]
     */
    function levelOrder($root) {
        $res = [];
        $level = 0;
        $this->helper($root, $res, $level);
        return $res;
    }
    
    function helper($node, &$mainList, $level) {
        if (is_null($node)) return;
        $size = count($mainList);
        if ($level > $size) {
            $cur = array($node->val);
            $mainList[$level] = $cur;
        } else {
            $mainList[$level][] = $node->val;
        }

        $this->helper($node->left, $mainList, $level+1);
        $this->helper($node->right, $mainList, $level+1);
        
    }
}
