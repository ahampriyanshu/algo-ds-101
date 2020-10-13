public class YoungestCommonAncestor {

    static Integer[] treeNodes = new Integer[]{1, 4, 5, 6, 7, null, null, 8, 9, 10, 11, null, null, null, null,
            null, null, 13};

    static int sizeOfTree = treeNodes.length;

    static NodeWrap youngestCommonAncestorNode = null;

    public static void main(String[] args) {

        /**
         *              1
         *          4       5
         *      6     7
         *    8   9  10 11
         *      13
         */
        TreeNode root = insert(0);
        findYoungestCommon(root, 8, 13);
        if (youngestCommonAncestorNode != null) {
            System.out.println(youngestCommonAncestorNode.treeNode.val);
        }
    }

    static boolean findYoungestCommon(TreeNode node, int val1, int val2) {
        if (node == null) {
            return false;
        }

        if (node.val == val1 || node.val == val2) {
            youngestCommonAncestorNode = new NodeWrap(node);
            return true;
        }
        boolean left = findYoungestCommon(node.left, val1, val2);
        boolean right = findYoungestCommon(node.right, val1, val2);
        if (left && right) {
            youngestCommonAncestorNode = new NodeWrap(node);
        }
        return left || right;
    }

    static TreeNode insert(int index) {
        if (index < sizeOfTree) {
            if (treeNodes[index] == null) {
                return null;
            }
            TreeNode node = new TreeNode(treeNodes[index]);
            node.left = insert(2 * index + 1);
            node.right = insert(2 * index + 2);
            return node;
        }
        return null;
    }

    static void inOrder(TreeNode root) {

        if (root == null) {
            return;
        }

        inOrder(root.left);
        System.out.print(root.val + " ");
        inOrder(root.right);
    }

    static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        public TreeNode(int val) {
            this.val = val;
        }
    }

    static class NodeWrap {
        TreeNode treeNode;

        public NodeWrap(TreeNode treeNode) {
            this.treeNode = treeNode;
        }
    }
}