import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;
public class BinarySearchTree {
    TreeNode root;
    public BinarySearchTree(){
        this.root = null;
    }
    public boolean isEmpty(){
        return root==null;
    }
    public void deleteByCopying(int deletevalue){
        TreeNode p = this.root,prev=null;
        while(p!=null && p.info != deletevalue){
            prev = p;
            if(deletevalue >= p.info){
                p = p.right;
            }
            else{
                p=p.left;
            }
        }
        TreeNode node = p;
        if(p!=null && p.info==deletevalue){
            if(node.right == null){
                node = node.left;
            }
            else if(node.left == null){
                node = node.right;
            }
            else{
                TreeNode tmp = node.left;
                TreeNode prev2 = node;
                while(tmp.right!=null){
                    prev2 = tmp;
                    tmp = tmp.right;
                }
                node.info = tmp.info;
                if(prev2==node){
                    prev2.left = tmp.left;
                }
                else{
                    prev2.right = tmp.left;
                }
            }
        }
    }
    public void deleteByMerging(int deleteValue){
        TreeNode p=this.root,prev=null;
        while(p!=null && p.info!=deleteValue){ // Search for delete node
            prev=  p;
            if(deleteValue >= p.info){
                p = p.right;
            }
            else{
                p = p.left;
            }
        }
        TreeNode nodeForPrevToPointTo = p;
        if(p!=null && p.info == deleteValue){
            if(p.right ==null){
                nodeForPrevToPointTo = p.left;
            }
            else if(p.left == null){
                nodeForPrevToPointTo = p.right;
            }
            else{
                TreeNode temp = nodeForPrevToPointTo.left;
                while(temp.right!=null){
                    temp = temp.right;
                }
                temp.right = p.right;
                nodeForPrevToPointTo = p.left;
                if(p == root){
                    root = nodeForPrevToPointTo;
                }
                else if(prev.left == p){
                    prev.left = nodeForPrevToPointTo;
                }
                else{
                    prev.right = nodeForPrevToPointTo;
                }
            }
        }
        else if(root!=null){
            System.out.println("Key " + deleteValue + "is not in the tree");
        }
        else{
            System.out.println("The tree is empty");
        }
    }
    public void preorderTravelsal(){
        TreeNode p = root;
        Stack stack = new Stack();
        if(p!=null){
            stack.push(p);
            while(!stack.isEmpty()){
                p= (TreeNode)stack.pop();
                System.out.print(p.info+" ");
                if(p.right!=null){
                    stack.push(p.right);
                }
                if(p.left!=null){
                    stack.push(p.left);
                }
            }
        }
    }
    public void breadthFirstTraversal(){
        TreeNode p  = root;
        Queue<TreeNode> q = new LinkedList<>();
        if(p!=null){
            q.add(p);
            while(!q.isEmpty()){
                p = q.remove();
                System.out.print(p.info + " ");
                if(p.left !=null){
                    q.add(p.left);
                }
                if(p.right!=null){
                    q.add(p.right);
                }
            }
        }
    }
    public void inorderTraversalRecursion(TreeNode p){
        if(p!=null){
            inorderTraversalRecursion(p.left);
            System.out.print(p.info + " "); //visit node p
            inorderTraversalRecursion(p.right);
        }
    }
    public void preorderTraversalRecursion(TreeNode p){
        if(p!=null){
            System.out.print(p.info + " "); //visit node p
            preorderTraversalRecursion(p.left);
            preorderTraversalRecursion(p.right);
        }
    }
    public void postorderTraversalRecursion(TreeNode p){
        if(p!=null){
            postorderTraversalRecursion(p.left);
            postorderTraversalRecursion(p.right);
            System.out.print(p.info + " "); //visit node p
        }
    }
    public void insert(int newInfo){
        if(isEmpty()){
            this.root = new TreeNode(newInfo);
        }
        else{
            TreeNode p = root;
            while(p!=null){
                if(newInfo<p.info){
                    if(p.left != null){
                        p = p.left;
                    }
                    else{
                        p.left = new TreeNode(newInfo);
                        break;
                    }
                }
                else{
                    if(p.right != null){
                        p = p.right;
                    }
                    else{
                        p.right = new TreeNode(newInfo);
                        break;
                    }
                }
            }
        }
    }
    public TreeNode search(int info){
        if(isEmpty()){
            System.out.println("Cannot find : "+info);
            return null;
        }
        else{
            TreeNode p = root;
            while(p!=null){
                if(p.info == info){
                    System.out.println("Found : "+info);
                    return p;
                }
                else if(info < p.info){
                    p = p.left;
                }
                else{
                    p = p.right;
                }
            }
            System.out.println("Cannot find : "+info);
            return null;
        }
    }  
    public int countNode(TreeNode t){
        if(t !=null){
            return 1+countNode(t.left)+countNode(t.right);
        }
        else{
            return 0;
        }
    }
    public int countLeaves(TreeNode t){
        if(t==null){
            return 0;
        }
        else if(t.left ==null && t.right == null){
            return 1;
        }
        else{
            return countLeaves(t.left)+countLeaves(t.right);
        }
    }
    public int countRightChildren(TreeNode t){
        if(t.right !=null){
            if(t.left!=null){
                return 1 + countRightChildren(t.left) + countRightChildren(t.right);
            }
            else{
                return 1 + countRightChildren(t.right);
            }
        }
        else{
            if(t.left!=null){
                return countRightChildren(t.left);
            }
            return 0;
        }
    }
    public int getHeight(TreeNode t){
        if(t != null){
            return 1 + Math.max(getHeight(t.left),getHeight(t.right));
        }
        else{
            return 0;
        }

    }
    public void deleteLeaves(TreeNode t){
        if(t==null){ return; }
        else if(t.left!=null || t.right != null){
            if(t.left!=null && t.right != null){
                if(t.left.left==null&&t.left.right==null){
                    t.left = null;
                }
                if(t.right.left==null&&t.right.right==null){
                    t.right = null;
                }
            }
            else if(t.left!=null){
                if(t.left.left==null&&t.left.right==null){
                    t.left = null;
                }
            }
            else{
                if(t.right.left==null&&t.right.right==null){
                    t.right = null;
                }
            }
        }
        deleteLeaves(t.left);       deleteLeaves(t.right);
    }
    public void breadthFirst(){
        TreeNode p  = root;
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        if(p!=null){
            queue.add(p);
            while(!queue.isEmpty()){
                p = queue.poll();
                System.out.print(p.info + " ");
                if(p.left !=null){
                    queue.add(p.left);
                }
                if(p.right!=null){
                    queue.add(p.right);
                }
            }
        }
    }
    public void preorder(TreeNode p){
        if(p!=null){
            System.out.print(p.info + " ");
            preorder(p.left);
            preorder(p.right);
        }
    }
    public void inorder(TreeNode p){
        if(p!=null){
            inorder(p.left);
            System.out.print(p.info + " ");
            inorder(p.right);
        }
    }
    public void postorder(TreeNode p){
        if(p!=null){
            postorder(p.left);
            postorder(p.right);
            System.out.print(p.info+ " ");
        }
    }
    public void iterativePreorder(){
        TreeNode p = root;
        Stack travStack = new Stack();
        if(p!=null){
            travStack.push(p);
            while(!travStack.isEmpty()){
                p= (TreeNode)travStack.pop();
                System.out.print(p.info+" ");
                if(p.right!=null){
                    travStack.push(p.right);
                }
                if(p.left!=null){
                    travStack.push(p.left);
                }
            }
        }
    }
    public void iterativeInorder(){
        TreeNode p = root;
        Stack travStack = new Stack();
        while(p!=null){
            while(p!=null){
            if(p.right!=null){
                travStack.push(p.right);
            }
            travStack.push(p);
            p = p.left;
            }
            p = (TreeNode) travStack.pop();
            while(!travStack.isEmpty() && p.right == null){
                System.out.print(p.info+" ");
                p = (TreeNode) travStack.pop();
            }
            System.out.print(p.info+" ");
            if(!travStack.isEmpty()){
                p= (TreeNode) travStack.pop();
            }
            else{
                p = null;
            }
        }
    }
    public void iterativeLastorder(){
        TreeNode p = root,q=root;
        Stack travStack = new Stack();
        while(p!=null){
            for(;p.left!=null;p=p.left){
                travStack.push(p);
            }
            while(p!=null && (p.right==null||p.right==q)){
                System.out.print(p.info+" ");
                q = p;
                if(travStack.isEmpty())return;
                p = (TreeNode) travStack.pop();
            }
            travStack.push(p);
            p=p.right;
        }
    }
}
class TreeNode {
    int info;
    TreeNode left,right;
    public TreeNode(int info){
        this(info,null,null);
    }
    public TreeNode(int info,TreeNode left,TreeNode right){
        this.info = info;
        this.left = left;
        this.right = right;
    }
}