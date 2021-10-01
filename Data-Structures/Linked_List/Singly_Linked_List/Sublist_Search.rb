# simple linked list implementation
class LinkedList
    attr_accessor :head
    # simple node implementation, constructor takes value and next ref
    class Node
        attr_accessor :value
        attr_accessor :next

        def initialize(val, nextNode)
            @value = val
            @next = nextNode
        end
    end

    # paramterized list constructor
    def initialize(val)
        @head = Node.new(val, nil)
    end

    # simple linked list insertion method
    def self.insert(node, val) 
        # if given node is null, insert at given ref
        if not node then
            node = Node.new(val, nil)
        else
            # otherwise, iterate until end of list
            while node.next
                node = node.next
            end
            # then insert the new node
            node.next = Node.new(val, nil)
        end
    end

    # sublist search function implementation
    def self.search(listToFind, listBeingSearched)
        # declare result var
        res = false

        # base case - empty listToFind implies true [empty list always exists in a given list]
        if not listToFind then
            return true
        end

        # otherwise, see if lists match starting with first node of listToFind
        firstIteration = true
        while listBeingSearched do
            # update list2 to the corresponding node for this iteration
            if not firstIteration then
                # if list2 is eptied, return false
                if not listBeingSearched then
                    return false
                end
                listBeingSearched = listBeingSearched.next
            end

            # make ref to head of each list for iter. purposes
            lookingFor = listToFind
            searchingIn = listBeingSearched

            # then try to match current form of list2 with list1 
            while lookingFor do
                # if list being searched is nil and list being searched for is not, fail
                if not searchingIn then
                    return false
                # if a match fails, break and try from next list2 node
                elsif lookingFor.value != searchingIn.value then
                    break
                end
                # otherwise, continue checking nodes
                lookingFor = lookingFor.next
                searchingIn = searchingIn.next
            end

            # if a match was found...
            if not lookingFor then
                return true
            end
            # o.w., continue
            firstIteration = false
        end
    end

    # simple print function for demonstration purposes
    def self.prettyPrint(node)        
        while node
            print "#{node.value} -> "
            node = node.next
        end
        print "nil\n"
    end
end

# simple demonstration list setup via stdin
puts "Please enter three values to put in the list that will be looked for:"
list1 = LinkedList.new(gets.strip)
for i in 1..2
    LinkedList.insert(list1.head, gets.strip)
end
puts "Please enter five values to put in the list that will be searched:"
list2 = LinkedList.new(gets.strip)
for i in 1..4
    LinkedList.insert(list2.head, gets.strip)
end
# pretty print the inputs
puts "Seeking:"
LinkedList.prettyPrint(list1.head)
puts "Inside of:"
LinkedList.prettyPrint(list2.head)
# then demonstrate sublist search method
puts "Result: "
puts LinkedList.search(list1.head, list2.head)