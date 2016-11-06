
a = [1,2,[[22,33,[55]],66],3,4,5]

def func(a):
	for i in a:
		if type(i) is type([]):
			func(i)
		else:
			print i

if __name__ == '__main__':
	func(a)
