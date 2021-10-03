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

    # method to check for duplicates
    def self.duplicates?(tree, prev_vals = [])
        # base case, if null leaf reached this path had no duplicates
        if not tree then
            return true
        # otherwise, check if current value is a duplicate
        elsif prev_vals.include? tree.value then
            return false
        end
        # if curr value is unique, add it to prev values tracker
        prev_vals << tree.value
        # then recurse
        duplicates?(tree.left) && duplicates?(tree.right)
    end

    # simple bst print method for printing (unbalanced trees may look odd)
    def self.printTree(tree, level = 0)
        if not tree then
            return
        else
            if level == 0 then
                puts tree.value
            elsif level == 1 then
                print "#{tree.value} "
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
# then checks for duplicates
puts "Duplicates? ~"
puts BST.duplicates?(b.head)