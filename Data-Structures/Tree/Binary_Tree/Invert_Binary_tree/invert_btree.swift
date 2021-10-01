class TreeNode {
    var left: TreeNode?
    var right: TreeNode?
    var value: Int

    init(val: Int) {
        self.value = val
    }

}

class Tree{
    var root: TreeNode
    init(val: TreeNode){
        self.root = val
    }
    func invertTree(){
        invert(node: self.root)
    }
    func invert(node: TreeNode){
        if(node.left == nil&&node.right == nil){
            return
        }
        let temp = node.left
        node.left = node.right
        node.right = temp
        if(node.left != nil ){
            invert(node: node.left!)
        }
        if(node.right != nil){
            invert(node: node.right!)
        }
    }

}
var root = TreeNode(val: 1)
var o = TreeNode(val: 3)
var b = TreeNode(val: 7)
var h = TreeNode(val: 4)
var g = TreeNode(val: 2)

root.left = o
root.right = b
root.right?.right = h
root.right?.left = g
var myTree = Tree(val: root)

myTree.invertTree()
