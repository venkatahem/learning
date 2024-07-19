from socket import *
import sys 
serverSocket = socket(AF_INET, SOCK_STREAM)
serverSocket.bind(('',1235))
serverSocket.listen(1)
print("server running")
while True:
#Establish the connection
    print('Ready to serve...')
    connectionSocket, addr = serverSocket.accept()
    try:
        message = connectionSocket.recv(1024)
        print(message)
        filename = message.split()[1]
        f = open(filename[1:],"r")
        outputdata = f.read()
        f.close()
        connectionSocket.send('HTTP/1.0 200 OK\r\n\r\n'.encode())
        for i in range(0, len(outputdata)):
            connectionSocket.send(outputdata[i].encode())
            #connectionSocket.send("\r".encode())
        connectionSocket.close()
    except IOError:
        # message = "file not found"
        connectionSocket.send('HTTP/1.0 404 NOT FOUND\n\n File Not Found'.encode())
        # connectionSocket.send(message.encode())
        serverSocket.close()
        print("closing server")
        sys.exit()

#http://192.168.117.136:1234/hello.html