class Node:
    def __init__(self, key, left=None, right=None):
        self.key = key
        self.left = left
        self.right = right

    def __repr__(self):
        left = f" left={self.left}" if self.left is not None else ""
        right = f" right={self.right}" if self.right is not None else ""
        return f"<Node object key={self.key}{left+right}>"


def serialize(root):
    if root is None:
        return "-1"

    # for each branch, return the key, the left then the right node
    output = (str(root.key), serialize(root.left), serialize(root.right))
    return " ".join(output)


if __name__ == "__main__":
    #     1
    #    / \
    #   2   3
    #  / \ / \
    # 4 -1 6  7
    root = Node(1, Node(2, Node(4)), Node(3, Node(6), Node(7)))
    print(root)

    with open("tree.txt", "w") as fp:
        fp.write(serialize(root))