from socket import *
serverName = 'servername'
serverPort = 12345
clientSocket = socket(AF_INET, SOCK_STREAM)
#clientSocket.connect((serverName,serverPort))
#clientSocket.connect(('192.168.117.90', serverPort))
clientSocket.connect(('127.0.0.1', serverPort))
while True:
    sentence = input('Input sentence:').encode()
    if(sentence == 'q'):
        break
    clientSocket.send(sentence)
    ans = clientSocket.recv(1024)
    print("From Server:",ans.decode())
clientSocket.close()
