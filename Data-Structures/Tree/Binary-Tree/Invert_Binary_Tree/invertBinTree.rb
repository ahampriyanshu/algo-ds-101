# simple bst implementation
class BST
    attr_accessor :head
    # simple bst node implementation
    class Node
       attr_accessor :left
       attr_accessor :right
       attr_accessor :value
       
       def initialize(val)
            @value = val
       end
    end

    # bst constructor
    def initialize(val)
        @head = Node.new(val)
    end

    # method for inserting new values into a given bst
    def self.insert(val, tree)
        if not tree then
            return Node.new(val)
        else
            if val > tree.value then
                tree.right = insert(val, tree.right)
            else 
                tree.left = insert(val, tree.left)
            end
        end
        tree
    end

    # tree inversion method
    def self.invert(tree)
        # base case, null leaf reached
        if not tree then
            return
        end
        # otherwise, recurse and swap left and right nodes of tree
        temp = tree.right
        tree.right = invert(tree.left)
        tree.left = invert(temp)
        # return inverted result
        tree
    end

    # simple bst print method for printing
    def self.printTree(tree, level = 0)
        if not tree then
            return
        else
            if level == 0 then
                puts tree.value
            elsif level == 1 then
                print tree.value
            else
                puts " #{tree.value}"
            end
            printTree(tree.left, 1)
            printTree(tree.right, 2)
        end
    end
end

# simple integer input example, takes three int inputs
puts "Please input three integers for an example."
b = BST.new((gets).to_i)
BST.insert((gets).to_i, b.head)
BST.insert((gets).to_i, b.head)
puts "Example tree~"
BST.printTree(b.head)
# then inverts tree
puts "Inverted result~"
BST.invert(b.head)
BST.printTree(b.head)