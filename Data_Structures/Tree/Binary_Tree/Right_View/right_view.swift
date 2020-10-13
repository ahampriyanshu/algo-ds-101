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
    func rightView()-> [TreeNode]{

        var rightView = [TreeNode]()
        var curretNode: TreeNode?
        curretNode = self.root
        while(curretNode?.right != nil){
            rightView.append(curretNode!)
            curretNode = curretNode!.right
        }
        rightView.append(curretNode!)
        return rightView
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

for node in myTree.rightView() {
    print(node.value, " ")
}
