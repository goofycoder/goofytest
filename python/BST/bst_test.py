from bst import *            # bst.py 

##### TEST #####
arr = [5,3,1,7,2,6,4,8]

'''
            5
          /   \
        3       7
       / \       \
      1   4       8
       \
        2

'''

t = BST(arr)

### Tree traversal
print "In-order traverse: "
t.inorderTraverse()
print ""

print "Pre-order traverse: "
t.preorderTraverse()
print ""

print "Post-order traverse: "
t.postorderTraverse()
print ""

h = t.getHeight()
print "\nHeight of BST: " + str(h)
