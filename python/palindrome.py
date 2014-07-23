import reverse_int      # in reverse_int.py

def isPalindrome(num):
    rev = reverse_int.reverse_int(num)    # call reverse_int() defined in reverse_int.py module

    if rev == num:
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
