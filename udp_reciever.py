import socket

UDP_IP = "127.0.0.1"
UDP_PORT = 3031

sock = socket.socket(socket.AF_INET, # Internet
                     socket.SOCK_DGRAM) # UDP
sock.bind((UDP_IP, UDP_PORT))

fileData = ""

dataNotRecived = True

while dataNotRecived:
    data, addr = sock.recvfrom(4096) # buffer size is 1024 bytes
    print "received message:", data[0:6]
    fileData = fileData + data[6:]
    if(len(data)!=4096):
   	  dataNotRecived = False

print('Creating new text file')
fileName = "UDP.pdf"

file = open(fileName,'w')
file.write(fileData)   # Trying to create a new file or open one
file.close()