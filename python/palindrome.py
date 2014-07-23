import reverse_int

def isPalindrome(num):
    r = reverse_int.reverse_int(num) 

    if r == num:
        return True
    else:
        return False

##### test cases #####
in_1 = 121
if isPalindrome(in_1):
    print str(in_1) + ' is Palindrome'
else:
    print str(in_1) + ' is NOT Palindrome'

in_2 = 1331
if isPalindrome(in_2):
    print str(in_2) + ' is Palindrome'
else:
    print str(in_2) + ' is NOT Palindrome'

in_3 = 5
if isPalindrome(in_3):
    print str(in_3) + ' is Palindrome'
else:
    print str(in_3) + ' is NOT Palindrome'

in_4 = 1231
if isPalindrome(in_4):
    print str(in_4) + ' is Palindrome'
else:
    print str(in_4) + ' is NOT Palindrome'
