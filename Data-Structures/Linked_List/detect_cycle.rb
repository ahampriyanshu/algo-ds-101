# Definition for singly-linked list.
class ListNode
    attr_accessor :val, :next
    def initialize(val)
        @val = val
        @next = nil
    end
end

# function to test if loop is there
# @param {ListNode} head
# @return {Boolean}
def detect_cycle(head)
    slow = head
    fast = head
    while slow && fast && fast.next
        slow = slow.next
        fast = fast.next.next
        if slow && slow == fast 
           return true 
        end
    end
    false
end

# script to test the above
tail = ListNode.new(5)
head = tail
loop_node = nil
(2...9).each do |p|
  n = ListNode.new(5*p)
  tail.next = n
  tail = n
  if p == 7
    loop_node = tail
  end
end

tail.next = loop_node

puts("Loop detected ? = #{detect_cycle(head)}")
