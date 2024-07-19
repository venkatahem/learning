from socket import *

clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect(("localhost",2345))

while True:
	msg = clientSocket.recv(1024).decode()
	print("Received : ", msg)
	clientSocket.send("1".encode())