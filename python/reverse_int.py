'''
    reverse integer:  123 --> 321
'''
def reverse_int(num):
    res = 0

    while(num!=0):
        res = res*10 + num%10 
        num = num/10

    return res

##### test cases #####
in_1 = 123
print 'reverse ' + str(in_1) + ': ' + str(reverse_int(in_1))

in_2 = 1234
print 'reverse ' + str(in_2) + ': ' + str(reverse_int(in_2))

in_3 = 3
print 'reverse ' + str(in_3) + ': ' + str(reverse_int(in_3))

