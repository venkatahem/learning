from socket import *
serverPort = 12345
clientSocket = socket(AF_INET,SOCK_DGRAM)
while 1:
    print("Enter quit to exit (or) domain to get IP: ")
    message = input()
    if(message == "quit"):
        break
    clientSocket.sendto(message.encode(),('127.0.0.1', serverPort))
    msg, serverAddress = clientSocket.recvfrom(2048)
    print("IP for the requested domain: ",msg.decode())
clientSocket.close()
