from socket import *
serverName = 'hostname'
serverPort = 12345
clientSocket = socket(AF_INET,SOCK_DGRAM)
while 1:
    message = input()
    clientSocket.sendto(message.encode(),('192.168.117.98', serverPort))
    msg, serverAddress = clientSocket.recvfrom(2048)
    print("From Server:",msg.decode())
clientSocket.close()
