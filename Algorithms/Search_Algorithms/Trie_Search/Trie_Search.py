# Program for Trie Insert and Search

# Trie node
class TrieNode:
	def __init__(self):
		self.children = [None]*26
		self.isEndOfWord = False

# Trie Class
class Trie:
	def __init__(self):
		self.root = self.getNode()

	def getNode(self):
		return TrieNode()

	def toIndex(self, ch):
		return ord(ch)-ord('a')

	# Function to Insert into Trie
	def insert(self, key):
		node = self.root
		length = len(key)

		for i in range(length):
			idx = self.toIndex(key[i])
			if not node.children[idx]:
				node.children[idx] = self.getNode()
			node = node.children[idx]
		node.isEndOfWord = True

	# Function for Trie Search
	def search(self, key):
		node = self.root
		length = len(key)

		for i in range(length):
			idx = self.toIndex(key[i])
			if not node.children[idx]:
				return False
			node = node.children[idx]
		return node!=None and node.isEndOfWord


# Main function 
# To test code, please edit keys list and print statements for search
def main():
	keys = ["the","apple","there","hello","world", "by","python"]
	output = ["Not present in trie", "Present in trie"]

	# Construct Trie
	trie = Trie()

	for key in keys:
		trie.insert(key)


	# Search in trie
	print("{} => {}".format("the", output[trie.search("the")]))
	print("{} => {}".format("hi", output[trie.search("hi")]))
	print("{} => {}".format("apple", output[trie.search("apple")]))
	print("{} => {}".format("man", output[trie.search("man")]))

if __name__ == '__main__':
	main()

## Sample Output ##
# the => Present in trie
# hi => Not present in trie
# apple => Present in trie
# man => Not present in trie