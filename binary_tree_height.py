class Node:
    # Constructor to create node
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
 
def depth(node):
    if node is None:
        return 0
    else:
        # Compute the depth of left and right subtree
        left_depth = depth(node.left)
        right_depth = depth(node.right)
        return max(left_depth, right_depth)+1
 
root = Node(1)
root.left = Node(3)
root.right = Node(8)
root.left.left = Node(4)
root.left.right = Node(9)
root.left.left.right = Node(8)
 
print("Height of the tree is", (depth(root)))