
class Node:
    def __init__(self, value):
        self.value = value
        self.prev = None
        self.next = None


class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def setHead(self, node):
        # O(1) T | O (1) S
		if self.head is None:
			self.head = node
			self.tail = node
			return
		self.insertBefore(self.head, node)

    def setTail(self, node):
        # O(1) T | O(1) S
		if self.tail is None:
			self.setHead(node)
		self.insertAfter(self.tail, node)

    def insertBefore(self, node, nodeToInsert):
        # O(1) T | O(1) S
		# First we gotta tackle case that what if n=there is no linked list therefore no node. In that case, we were asked to insert a node before something that does not exist and hence, we gotta return
		if (nodeToInsert == self.head and nodeToInsert == self.tail):
			return
		self.remove(nodeToInsert)
		nodeToInsert.prev = node.prev
		nodeToInsert.next = node
		if node.prev is None:
			self.head = nodeToInsert
		else:
			node.prev.next = nodeToInsert
		node.prev = nodeToInsert

    def insertAfter(self, node, nodeToInsert):
        # O(1) T | O(1) S
		if (nodeToInsert == self.head and nodeToInsert == self.tail):
			return
		self.remove(nodeToInsert)
		nodeToInsert.prev = node
		nodeToInsert.next = node.next
		if node.next is None:
			self.tail = nodeToInsert
		else:
			node.next.prev = nodeToInsert
		node.next = nodeToInsert

    def insertAtPosition(self, position, nodeToInsert):
        # O(P) T | O(1) S
		if position == 1:
			self.setHead(nodeToInsert)
			return
		currentPosition = 1
		node = self.head
		while node is not None and currentPosition != position:
			currentPosition += 1
			node = node.next
		if node is not None:
			self.insertBefore(node, nodeToInsert)
		else:
			self.setTail(nodeToInsert)

    def removeNodesWithValue(self, value):
        # O(N) T | O(1) S
		node = self.head
		while node is not None:
			nodeToRemove = node
			node = node.next
			if nodeToRemove.value == value:
				self.remove(nodeToRemove)

    def remove(self, node):
        # O(1) T | O(1) S
		if (node == self.head):
			self.head = self.head.next
		if(node == self.tail):
			self.tail = self.tail.prev
		self.removeNodeBindings(node)

	def removeNodeBindings(self,node):
		# O(1) T | O(1) S
		if node.prev is not None:
			node.prev.next=node.next
		if node.next is not None:
			node.next.prev = node.prev
		node.prev=None
		node.next=None

    def containsNodeWithValue(self, value):
        # O(N) T | O(1) S
		node = self.head
		while node is not None and node.value!=value:
			node=node.next
		return node is not None
