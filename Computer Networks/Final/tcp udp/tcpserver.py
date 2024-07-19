from socket import *
serverPort = 12345
serverSocket = socket(AF_INET,SOCK_STREAM)
serverSocket.bind(('',serverPort))
serverSocket.listen(1)
print("server is ready to receive")
while True:
    connectionSocket, addr = serverSocket.accept()
    while 1:
        sentence = connectionSocket.recv(1024)
        sentence = sentence.decode()
        print("From client:",sentence)
        r = input()
        connectionSocket.send(r.encode())
connectionSocket.close()