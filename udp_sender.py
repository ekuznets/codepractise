import socket
import time
import os

UDP_IP = "142.58.164.127"
UDP_PORT = 22
fileName = "/home/ekuznets/Desktop/communication-systems-4th-edition-simon-haykin.pdf"

size = os.path.getsize(fileName)
print "FileName: " + fileName
print "Size: " + str(os.path.getsize(fileName))

print "UDP target IP:", UDP_IP
print "UDP target port:", UDP_PORT

block = "000000"
idData = 0

sock = socket.socket(socket.AF_INET, # Internet
                     socket.SOCK_DGRAM) # UDP

dataNotSent = True

while(dataNotSent):
  with open(fileName, mode='rb') as file: # b is important -> binary
    file.seek(idData*4090)
    fileContent = file.read(4090)
    # print len(fileContent)
  if(len(fileContent)!=4090):
   	dataNotSent = False
  dataBlock = str(block + str(idData))
  dataBlock = dataBlock[-6:]
  fileContent = dataBlock + fileContent
  sock.sendto(fileContent, (UDP_IP, UDP_PORT))
  idData+=1
  print "Sent Block: " + dataBlock

file.close()
print "Finished!"
