from socket import *
# serverName = '127.0.0.1'
serverName = '192.168.71.197'
serverPort = 12345
clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((serverName, serverPort))
while True:
    sentence = input('Input sentence:')
    if(sentence == 'q'):
        break
    clientSocket.send(sentence.encode())
    ans = clientSocket.recv(1024)
    print("From Server:",ans.decode())
clientSocket.close()
