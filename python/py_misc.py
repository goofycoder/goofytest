'''
    Permutation (order matters):
    Combination (order does NOT matter)
    Cartesian product
'''
import itertools

#Permutation (order matters):
print list(itertools.permutations([1,2,3,4], 2))
#[(1, 2), (1, 3), (1, 4),
#(2, 1), (2, 3), (2, 4),
#(3, 1), (3, 2), (3, 4),
#(4, 1), (4, 2), (4, 3)]


# Combination (order does NOT matter):
print list(itertools.combinations('123', 2))
# [('1', '2'), ('1', '3'), ('2', '3')]

# Cartesian product (with several iterables):
print list(itertools.product([1,2,3], [4,5,6]))
#[(1, 4), (1, 5), (1, 6),
#(2, 4), (2, 5), (2, 6),
#(3, 4), (3, 5), (3, 6)]

# Cartesian product (with one iterable and itself):
print list(itertools.product([1,2], repeat=3))
#[(1, 1, 1), (1, 1, 2), (1, 2, 1), (1, 2, 2),
#(2, 1, 1), (2, 1, 2), (2, 2, 1), (2, 2, 2)]


# *: unpacks the sequence/collection into positional arguments, so you can do this:
# **: does the same, but only for a dictionary, fetch the value in (key:value) in the dict item
def sum(a, b):
    return a + b

values = (1, 2)

s = sum(*values)
print s

args = {'a':3, 'b':4}

c = sum(*args)
print c             # c is 'ab' ('a'+'b')

d = sum(**args)
print d             # d is 7 (3+4)
