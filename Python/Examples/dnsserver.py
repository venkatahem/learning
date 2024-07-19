from socket import *
serverPort = 12345
serverSocket = socket(AF_INET, SOCK_DGRAM)
serverSocket.bind(('', serverPort))
table = {"www.github.com":"3.25.37.64/26", "www.facebook.com":"12.324.56/86", "www.apple.com":"30.123.45/90","www.google.com":"192.32.76/12"}
print("The server is ready to receive requests")
while 1:
    message, clientAddress = serverSocket.recvfrom(2048)
    msg = message.decode()
    print("Requested domain:",msg)
    if msg in table.keys():
        r = table[msg]
    else:
        r = "not found"
    # r = input()
    serverSocket.sendto(r.encode(), clientAddress)
serverSocket.close()