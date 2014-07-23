'''
    Given a dictionary string, print all the permutations of specified length using only the chars in the dictionary
    
    Example:
        dict_str = 'abc1'
        len = 3

        def foo(dict_str,len):

    Output: (24 different permutations)
        abc
        ab1
        ac1
        ...
'''
import itertools

def str_perm(dict_str, lenOfPermutation):
    for p in itertools.permutations(dict_str, lenOfPermutation):
        print ''.join(p)

##### Test cases #####
dict_str = 'abc1'
lenOfPermutation = 3

str_perm(dict_str, lenOfPermutation)
