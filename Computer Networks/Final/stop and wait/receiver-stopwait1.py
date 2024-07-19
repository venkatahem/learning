from base64 import decode
from socket import *

CliSock = socket(AF_INET,SOCK_STREAM)
CliSock.connect(("127.0.0.1",6969))

while True:
    msg = CliSock.recv(1024)
    msg = msg.decode()
    print(msg)
    ACK = input("Acknowledge ? (True): ")
    CliSock.send(ACK.encode())