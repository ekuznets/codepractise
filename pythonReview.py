#!/usr/bin/python
import math

class imageHandler():
	image = None
	size = 0

	def __init__(self,data,size): # size N means data expected is N^2 to make matrix

		self.image = [[0 for x in xrange(size)] for x in xrange(size)]
		self.size = size

		for i in range(size):
			for j in range(size):
				self.image[i][j] = data[size*i+j]

	def printImage(self): # print image

		stringImage = ""
		for i in range(self.size):
			stringImage+="[ "
			for j in range(self.size):
				stringImage+=str(self.image[i][j])
				stringImage+= " "
			stringImage+="]\n"

		print stringImage


	def turn90DegRight(self):
		
		imagetemp = [[0 for x in xrange(self.size)] for x in xrange(self.size)]

		for j in xrange(self.size):
			for i in xrange(self.size):
				imagetemp[j][self.size-i-1] = self.image[i][j]
		self.image = imagetemp
				

data = ''
try:
	file = open("data.txt", 'r+')
	data = file.read()
except IOError,e:
	print e.args
file.close()
value = []
data = data.split(',')
for ch in data:
		value.append(int(ch))

'''
image = imageHandler(value,4)
image.printImage()
image.turn90DegRight()
image.turn90DegRight()
image.turn90DegRight()
image.turn90DegRight()
image.printImage()
'''

import random
def testCaseGUID(testcaseNum = 1): #10
	for x in xrange(testcaseNum):
		ids = random.randint(0,999) 
		yield "Testcase number # " + str(ids)

'''
id = testCaseGUID(3)

print id.next()
print id.next()
print id.next()
print id.next()
'''

ar = list([3,2,1,4,34,23,13])
ar.sort()
print ar


a = open("data.txt", "r")
print a.readline()
a.close()

b = open("write.txt", "w")
b.write(str(ar))
b.close()