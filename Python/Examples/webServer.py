from socket import *
import sys 
serverSocket = socket(AF_INET, SOCK_STREAM)
serverSocket.bind(('',6789))
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
        print(filename)
        outputdata = f.read()
        f.close()
        connectionSocket.send('HTTP/1.1 200 OK\r\n\r\n'.encode())
        for i in range(0, len(outputdata)):
            connectionSocket.send(outputdata[i].encode())
        connectionSocket.close()
    except IOError:
        message = 'HTTP/1.1 404 NOT FOUND\n\n File Not Found'
        connectionSocket.send(message.encode())
        serverSocket.close()
        print("closing server")
        sys.exit()

#http://192.168.180.197:6789/hello.html