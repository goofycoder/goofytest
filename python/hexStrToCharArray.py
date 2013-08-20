""" 
    Convert the hex string to char array
        input:  "hex.txt" file
        output: on terminal

    Algorithm:
        input str:  "414243"
        output char array:  char arr[] = {0x41, 0x42, 0x43,}
"""
def hexStrToCharArr(file):
    f_in = open(file, 'r')
    str = f_in.read()
    print "input string: " + str

    result = 'char arr[] = {'
    i = 0;

    while i<len(str)-1:
        char_str = '0x' + str[i] + str[i+1] + ','
        result += char_str
        i += 2

    result += '};'
    print 'conversion is finished.'
    print 'result: \n', result


if __name__ == "__main__":
    file = 'hex.txt'
    hexStrToCharArr(file)
