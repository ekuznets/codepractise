#!/usr/bin/python
from __future__ import print_function
import sys, os

class node():

	__slots__ = ["data", "next"]
	
	def __init__(self, data=0, next=None):

		self.data = data
		self.next = next

	def __str__(self):
		return str(self.data)

	def printAll(self):
		tmp = self
		while(tmp):
			print ( str(tmp.data) + "->", end='' )
			tmp = tmp.next
		print ("end")


def main():

  print ( os.path.getsize("write.txt") )
'''
	tail = node(0)
	head = None
	tmp = None

	print("Create link list of size: " + sys.argv[1])
	for i in xrange(int(sys.argv[1])):
		if(i==0):
			tmp = node(i+1,tail)
		else:
			tmp = node(i+1,tmp)
		head = tmp

	tail.printAll()
	head.printAll()'''

if __name__ == "__main__":
	main()