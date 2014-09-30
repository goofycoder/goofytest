###
#	Given a list of integers and an integer to find, return the index 
#   of the found integer in the list
###
def binary_basic(list, d):
	if d in list:
		return list.index(d)
	else:
		return -1
		
def main():
	x = [1,2,4,6,7,8,9,10]
	d = 4
	idx = binary_basic(x,d)
	print idx
	
if __name__ == '__main__':
	main()