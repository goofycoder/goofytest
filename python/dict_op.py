'''
    dictionary basic operation:
        dict.items()
        dict.copy()
'''

### merge 2 dicts and generate new dict to store the result
dict_1 = {'a':1, 'b':2}
dict_2 = {'c':3}

dict_3 = dict(dict_1.items() + dict_2.items())
print dict_3
# dict_3 = {'a':1, 'c':3, 'b':2}

### merge dict B into dict A
dict_1.update(dict_2)
print dict_1
# dict_1 = {'a':1, 'c':3, 'b':2}

### copy the dict
dict_4 = dict_1.copy()
print dict_4
# dict_4 = {'a':1, 'c':3, 'b':2}
