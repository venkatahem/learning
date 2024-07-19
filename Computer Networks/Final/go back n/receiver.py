import socket, sys
import random
from time import sleep

s = socket.socket()
shost = socket.gethostname()
ip = socket.gethostbyname(shost)
print(shost, "(", ip, ")\n")
host = input(str("Enter server address: "))
name = input(str("\nEnter your name: "))
port = 1234
print("\nTrying to connect to ", host, "(", port, ")\n")
s.connect((host, port))
print("Connected...\n")

s.send(name.encode())
s_name = s.recv(1024)
s_name = s_name.decode()
print(s_name, "has joined the server\nEnter exit to exit server\n")

while True:

    m=s.recv(1024)
    m=m.decode()
    k=s.recv(1024)
    k=k.decode()
    k=int(k)
    i=0
    a=""
    b=""
    message=""
    while i!=k:
       f=random.choice([0,0,1,1,1,1,1,1])
       ss=random.choice([0,1,2])
       if(f==0):
          b="ACK Lost"
          message = s.recv(1024)
          message = message.decode()
          sleep(ss)
          s.send(b.encode())
         
       elif(f==1):
          b="ACK "+str(i)
          message = s.recv(1024)
          message = message.decode()
          sleep(ss)
          s.send(b.encode())
          a=a+message
          i=i+1
          
       
    
    print("The message received is :", m)