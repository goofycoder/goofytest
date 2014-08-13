'''
    string basic operations

    str.join(): put delimiter in between every two chars in string
'''

# string join(): 
# put delimiter in between every two chars in string

delimiter = '...'   
# if delimter = '', it is same as concatenate, better than '+' operation

str_1 = delimiter.join(['a', 'b', 'c'])

print str_1             # str_1: a...b...c
