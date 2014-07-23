'''
    use collections.deque as queue in Python

    queue = deque(...)

    # insert to the end of queue
    queue.append()
    
    # pop from the front of queue
    head = queue.popleft()
'''
from collections import deque

queue = deque(['Eric', 'John', 'Mike'])

# insert to the end of queue
queue.append('Terry')

print 'Original queue: '
print queue

item = queue.popleft()
print 'Poping ' + item      # 'Eric'

#display the queue
print queue

item = queue.popleft()
print item      # 'John'

item = queue.popleft()
print item      # 'Mike'

item = queue.popleft()
print item      # 'Terry'

if queue:
    print 'deque is NOT empty'
else:
    print 'deque is empty'
