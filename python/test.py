# -*- coding: cp936 -*-
#打印 Fabonacci 数列

fabs = [1,1]

number = int(raw_input("Please enter the length of the Fabonacci list:"))

for n in xrange(number-2):
	fabs.append(fabs[-1]+fabs[-2])

print fabs
	
