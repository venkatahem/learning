import os, sys,socket,struct

#ip = input("Enter ip:")
ip = "192.168.117.136"
#port = int(input("Enter port number:"))
port = 1456
buffersize = 1024
csocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
try:
    csocket.connect((ip, port))
    print("Connection was successful......")
except:
    print("Couldn't connect sorry.")

while True:
    fn = input("Enter filename to download: ")
    csocket.send("DWLD".encode())
    csocket.recv(buffersize)
    csocket.send(struct.pack("h",sys.getsizeof(fn)))
    csocket.send(fn.encode())
    fs = struct.unpack("i", csocket.recv(4))[0]
    if fs == -1:
        print("file not found..")
        break
    csocket.send("1".encode())
    fname = input("Enter file name for the new file: ")
    opfile = open(fname, "wb")
    bytesrecieved = 0
    print("downloading!.....")
    while bytesrecieved < fs:
        content = csocket.recv(buffersize)
        opfile.write(content)
        bytesrecieved += buffersize
    opfile.close()
    print("successful")
    csocket.send("1".encode())
    break
csocket.close()