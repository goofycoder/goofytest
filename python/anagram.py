'''
    test whether two strings are anagram
        'mary' and 'army' --> yes 
        'mary' and 'ram'  --> no
'''
def isAnagram(str1, str2):
    stat_1 = {}
    stat_2 = {}

    for c in str1:
        if c in stat_1:
            stat_1[c] = stat_1[c]+1
        else:
            stat_1[c]=1

    for d in str2:
        if d in stat_2:
            stat_2[d] = stat_2[d]+1
        else:
            stat_2[d]=1

    ''' #debug#
    for char, ctr in stat_1.items():
        print char+' : '+str(ctr)
    
    for char, ctr in stat_2.items():
        print char+' : '+str(ctr)
    '''    
    
    if stat_1 == stat_2:
        return True
    else:
        return False

##### test cases #####
# case1:
test1_a = 'mary'
test1_b = 'army'

if isAnagram(test1_a, test1_b):
    print test1_a + ' and ' + test1_b + ' are anagram'
else:
    print test1_a + ' and ' + test1_b + ' are NOT anagram'

# case2:
test2_a = 'mary'
test2_b = 'ram'

if isAnagram(test2_a, test2_b):
    print test2_a + ' and ' + test2_b + ' are anagram'
else:
    print test2_a + ' and ' + test2_b + ' are NOT anagram'
