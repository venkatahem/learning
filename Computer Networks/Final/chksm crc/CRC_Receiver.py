import socket
def xor(a, b):
	result = []
	for i in range(1, len(b)):
		if a[i] == b[i]:
			result.append('0')
		else:
			result.append('1')
	return ''.join(result)

def mod2div(divident, divisor):
	pick = len(divisor)
	tmp = divident[0: pick]
	while pick < len(divident):
		if tmp[0] == '1':
			tmp = xor(divisor, tmp) + divident[pick]
		else: 
			tmp = xor('0'*pick, tmp) + divident[pick]
		pick += 1
	if tmp[0] == '1':
		tmp = xor(divisor, tmp)
	else:
		tmp = xor('0'*pick, tmp)
	checkword = tmp
	return checkword

def decodeData(data, key):
	l_key = len(key)
	appended_data = data.decode() + '0'*(l_key-1)
	remainder = mod2div(appended_data, key)
	return remainder

s = socket.socket()
print("Socket successfully created")
port = 64000
s.bind(('', port))
print("socket binded to %s" % (port))
s.listen(5)
print("socket is listening")
flag=0
while True and flag != 1:
	c, addr = s.accept()
	print('Got connection from', addr)
	data = c.recv(1024)
	print('Received encoded data in binary format :', data.decode())
	if not data:
		break
	key = "1001"
	ans = decodeData(data, key)
	print('Remainder after decoding is->'+ans)
	temp = "0" * (len(key) - 1)
	if ans == temp:
		flag=1 
	else:
		c.sendto(("Error in data").encode(), ('127.0.0.1', 12345))
c.sendto(("Thank you\nData ->"+data.decode() + " Received\nNo error FOUND").encode(), ('127.0.0.1', 12345))
c.close()