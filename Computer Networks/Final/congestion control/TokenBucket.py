import time

pkt = int(input("Enter no of packets : "))
size = int(input("Enter Buffer Size : "))
tokenduration = int(input("Enter the token generation freqeuncy :"))

buffer = [0, ]
lost = []
print("Buffer : ", *buffer)

class TokenBucket:

    def __init__(self, tokens, time_unit, forward_callback):
        self.tokens = tokens
        self.time_unit = time_unit
        self.forward_callback = forward_callback
        self.bucket = tokens
        self.last_check = time.time()

    def handle(self, packet):
        current = time.time()
        time_passed = current - self.last_check
        self.last_check = current

        self.bucket = self.bucket + \
            time_passed * (self.tokens / self.time_unit)

        if (self.bucket > self.tokens):
            self.bucket = self.tokens

        if (self.bucket < 1):
            print("waiting for token..")
            return 0
        else:
            self.bucket = self.bucket - 1
            self.forward_callback(packet)
            return 1


def forward(packet):
    print("Packet Forwarded: " + str(packet))
    del buffer[0]


throttle = TokenBucket(1, tokenduration, forward)

packet = 0
flag = 0
while True:
    time.sleep(1)
    a = throttle.handle(buffer[0])
    if packet<pkt:
        packet += 1
    else:
        flag = 1
    if len(buffer)<size and flag ==0 :
        buffer.append(packet)
    elif packet<pkt:
        print("\n>>Bucket overflow<<\n\nPacket lost : ", packet)
        lost.append(packet)
    print("Buffer : ", *buffer)
    if len(buffer)==0:
        print("All packets sent")
        break

print("\n>>Packets Lost<<\n",*lost)