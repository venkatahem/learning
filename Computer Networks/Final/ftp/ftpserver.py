import sys,os,struct
import socket
import sys
import time
import os
import struct

ip = "192.168.117.65"
port = 1456
bufferSize = 1024
serverSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serverSocket.bind((ip, port))
serverSocket.listen()
print("FTP server up and running")

while True:
    clientConnection, clientAddress = serverSocket.accept()
    data = clientConnection.recv(bufferSize)
    if data.decode() == "DWLD":
        clientConnection.send("1".encode())
        fileNameLength = struct.unpack("h", clientConnection.recv(2))[0]
        print(fileNameLength)
        fileName = clientConnection.recv(fileNameLength).decode()
        print(fileName)
        if os.path.isfile(fileName):
            clientConnection.send(struct.pack("i", os.path.getsize(fileName)))
        else:
            print("File name not valid")
            clientConnection.send(struct.pack("i", -1))
            break
        clientConnection.recv(bufferSize)
        start_time = time.time()
        print("Sending file...")
        file = open(fileName, "rb")
        content = file.read(bufferSize)
        while content:
            clientConnection.send(content)
            content = file.read(bufferSize)

        clientConnection.recv(bufferSize)
        clientConnection.send(struct.pack("f", time.time() - start_time))
        clientConnection.close()
        break
serverSocket.close()