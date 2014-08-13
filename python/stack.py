"""
    use list as stack in Python

    stack = []

    push():   
        stack.append(2)
    
    pop():
        top = stack.pop()
"""

stack = []

stack.append(2)
stack.append(3)
stack.append(7)

top = stack.pop()
print top           # 7

top = stack.pop()
print top           # 3

top = stack.pop()
print top           # 2

if not stack:
    print "stack is empty"
else:
    print "stack is NOT empty"
