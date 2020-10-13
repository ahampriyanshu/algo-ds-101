class Node
    attr_reader :value
    attr_accessor :next
    def initialize(value)
        @value = value
        @next = nil
    end
end

class SinglyLinkedList
    def initialize
        @head = nil
        @size = 0
    end

    def insert(value)
        node = Node.new(value)
        current = @head
        while current && current.next do
            current = current.next
        end
        if current.nil?
            @head = node
        else
            current.next = node
        end
        @size += 1
    end

    def delete_kth_from_end(k)
        return if (k > @size || @size <= 0)
        if k == @size
            @head = @head.next
            return
        end
        prev_node_pos_from_start = @size - k - 1
        current = @head
        prev_node_pos_from_start.times do 
            current = current.next
        end
        current.next = current.next.next
        @size -= 1
    end

    def print_list
        current = @head
        loop do
            break if current.nil?
            print "#{current.value} "
            current = current.next
        end
        puts
    end

end

list = SinglyLinkedList.new
list.insert(1)
list.insert(2)
list.insert(3)
list.insert(4)
list.insert(5)
list.insert(6)
list.print_list # 1 2 3 4 5 6
list.delete_kth_from_end(3)
list.print_list # 1 2 3 5 6 
list.delete_kth_from_end(1)
list.print_list # 1 2 3 5
list.delete_kth_from_end(4)
list.print_list # 2 3 5
