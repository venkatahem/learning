from socket import *
serverName = 'hostname'
serverPort = 12345
clientSocket = socket(AF_INET,SOCK_DGRAM)
while 1:
    message = input()
    if(message == "quit"):
        break
    clientSocket.sendto(message.encode(),('127.0.0.1', serverPort))
    msg, serverAddress = clientSocket.recvfrom(2048)
    print("From Server:",msg.decode())
clientSocket.close()
