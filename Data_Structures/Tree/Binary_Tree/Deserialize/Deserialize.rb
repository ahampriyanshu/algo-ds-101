# created : 13/10/2020
# author  : baniksudipto

class TreeNode
    attr_accessor :value, :left, :right

    def initialize(value = nil)
        @value = value
        @left = nil
        @right = nil
    end
end

class Codec
    def initialize(empty_leaf_marker, separator)
      @index = 0
      @marker = empty_leaf_marker
      @separator = separator
    end
  
    def serialize(root)
      # Encodes a tree to a single string.
      if root
        [root.value , serialize(root.left), serialize(root.right)].join(@separator)
      else
        @marker.to_s
      end
    end
  
    def deserialize(data)
        # Decodes a string to a tree
        @index = 0
        data = data.split(@separator)
        build_tree(data)
    end
  
    private
  
    def build_tree(data)
      value = data[@index]
      @index += 1
      if value.nil? or value == @marker
        nil
      else
        node = TreeNode.new(value)
        node.left = build_tree(data)
        node.right = build_tree(data)
        node
      end
    end
  end

# test 
serialized_string = "1,2,4,#,#,5,#,#,3,6,#,#,7,#,#"

#       1
#    2     3
#  4  5   6  7

codec = Codec.new('#',',')

raise "This is not working" unless codec.serialize(codec.deserialize(serialized_string)) == serialized_string
