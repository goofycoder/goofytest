class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BST:
    def __init__(self, data):
        self.root = None
        
        # use list of data to construct BST
        if data is not None:
            for i in data:
                self.insertNode(i)
    
    def insertNode(self, data):
        newNode = Node(data)

        p = self.root
        if p is None:
            self.root = newNode
            return

        # find the place to insert the node
        while p is not None:
            if p.data <= data:
                if p.right is None:
                    p.right = newNode
                    return
                else:
                    p = p.right
            else:
                if p.left is None:
                    p.left = newNode
                    return
                else:
                    p = p.left

    def inorderTraverse(self):
        inorderVisit(self.root)
    
    def preorderTraverse(self):
        preorderVisit(self.root)
    
    def postorderTraverse(self):
        postorderVisit(self.root)

    def getHeight(self):
        return _getHeight(self.root)

def inorderVisit(node):
    if node is None:
        return

    inorderVisit(node.left)
    print node.data,
    inorderVisit(node.right)

def preorderVisit(node):
    if node is None:
        return
    
    print node.data,
    preorderVisit(node.left)
    preorderVisit(node.right)

def postorderVisit(node):
    if node is None:
        return
    
    postorderVisit(node.left)
    postorderVisit(node.right)
    print node.data,

def _getHeight(node):
    if node is None:
        return 0

    leftH = _getHeight(node.left)
    rightH = _getHeight(node.right)

    if leftH > rightH:
        return (leftH + 1)
    else:
        return (rightH + 1)

