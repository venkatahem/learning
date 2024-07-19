from base64 import decode
from socket import *

SockServ =  socket(AF_INET,SOCK_STREAM)
SockServ.bind(("127.0.0.1",6969))
msg = ["Packet1","Packet2","Packet3","packet4"]
SockServ.listen(1)
ACK = "True"
SockCli,addr = SockServ.accept()
i=-1
while i<4:
    if ACK=="True":
        i=i+1
        SockCli.send(msg[i].encode())
        print(msg[i]+" sent")
    else :
        SockCli.send(msg[i].encode())
        print("negative ack for"+msg[i])
        SockCli.send(msg[i].encode())
        print(msg[i]+" sent")
    ACK = SockCli.recv(1024)
    ACK = ACK.decode()
    if i==3:
        if ACK == "True":
            break