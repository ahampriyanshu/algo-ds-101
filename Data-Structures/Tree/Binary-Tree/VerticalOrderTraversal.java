/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
 
class Solution {
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        TreeMap<Integer,TreeMap<Integer,TreeSet<Integer>>> xCoord = new TreeMap();
        view(root, 0, 0, xCoord);
        List<List<Integer>> list = new ArrayList<List<Integer>>();
        for(Integer i: xCoord.keySet()){
            TreeMap<Integer, TreeSet<Integer>> yCoord = xCoord.get(i);
            List<Integer> arr = new ArrayList<Integer>();
            for(Integer j: yCoord.keySet()){
                TreeSet<Integer> keys = yCoord.get(j);
                for(Integer k: keys)
                    arr.add(k);
            }
            list.add(arr);
        }
        return list;
    }
    public void view(TreeNode root, int x, int y, TreeMap<Integer,TreeMap<Integer,TreeSet<Integer>>> xCoord){
        if(root==null) return;
        
        TreeMap<Integer,TreeSet<Integer>> yCoord = xCoord.getOrDefault(x, new TreeMap<Integer,TreeSet<Integer>>());
        TreeSet<Integer> keys = yCoord.getOrDefault(y, new TreeSet<Integer>());
        keys.add(root.val);
        yCoord.put(y, keys);
        xCoord.put(x, yCoord);
        view(root.left, x-1, y+1, xCoord);
        view(root.right, x+1, y+1, xCoord);
    }
}
