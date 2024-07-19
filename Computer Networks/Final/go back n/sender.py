import socket, sys,time,random

def decimalToBinary(n):  
    return n.replace("0b", "")

def binarycode(s):
    a_byte_array = bytearray(s, "utf8")

    byte_list = []

    for byte in a_byte_array:
        binary_representation = bin(byte)
        byte_list.append(decimalToBinary(binary_representation))

    a=""
    for i in byte_list:
        a=a+i
    return a

s = socket.socket()
host = socket.gethostname()
ip = socket.gethostbyname(host)
port = 1234
s.bind((host, port))
print(host, "(", ip, ")\n")
name = input(str("Enter your name: "))
           
s.listen(1)
print("\nWaiting for incoming connections...\n")
conn, addr = s.accept()
print("Received connection from ", addr[0], "(", addr[1], ")\n")

s_name = conn.recv(1024)
s_name = s_name.decode()
print(s_name, "has connected to the chat room\nEnter 'exit' to exit chat room\n")
conn.send(name.encode())

while True:
    message = input(str("server: "))
    conn.send(message.encode())
    if message == "exit":
        message = "Left chat room!"
        conn.send(message.encode())
        print("\n")
        break
    message=binarycode(message)
    f=str(len(message))
    conn.send(f.encode())
   
    i=0
    j=int(input("Enter the window size -> "))
    b=""
    j=j-1
    f=int(f)
    k=j
    while i!=f:
        
        while(i!=(f-j)):
            start_time = time.time()
            conn.send(message[i].encode())
            b=conn.recv(1024)
            cuur_time=time.time()
            if((start_time-time.time())<2):
                    b=b.decode()
                    print(b)
                    if(b!="ACK Lost"):
                        print("\nAcknowledgement Received!\n\nThe sliding window is in the range "+(str(i+1))+" to "+str(k+1)+"\nNow sending the next packet")
                        i=i+1
                        k=k+1
                    else:
                        t=random.choice([0,1])
                        if(t!=1):
                            print("\nAcknowledgement of the data bit is LOST!\n\nThe sliding window remains in the range "+(str(i+1))+" to "+str(k+1)+"\nNow Resending the same packet")
                        else:
                            time.sleep(2)
                            print("\nTime Limited Exceeded\n\nThe sliding window remains in the range "+(str(i+1))+" to "+str(k+1)+"\nNow Resending the same packet")
                


        while(i!=f):
            start_time = time.time()
            conn.send(message[i].encode())
            b=conn.recv(1024)
            cuur_time=time.time()
            if((start_time-time.time())<2):
                    b=b.decode()
                    print(b)
                    if(b!="ACK Lost"):
                        print("\nAcknowledgement Received!\n\nThe sliding window is in the range "+(str(i+1))+" to "+str(k)+"\nNow sending the next packet")
                        i=i+1
                    else:
                        t=random.choice([0,1])
                        if(t!=1):
                            print("\nAcknowledgement of the data bit is LOST!\n\nThe sliding window remains in the range "+(str(i+1))+" to "+str(k+1)+"\nNow Resending the same packet")
                        else:
                            time.sleep(2)
                            print("\nTime Limited Exceeded\nThe sliding window remains in the range "+(str(i+1))+" to "+str(k+1)+"\nNow Resending the same packet")            
               

