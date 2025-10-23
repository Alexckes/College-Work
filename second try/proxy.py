import socket

conn1 = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
conn2 = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
conn3 = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
host1 = ''
port1 = int(input('client port: '))
host2 = (input('server 1 host: '))
port2 = int(input('server 1 port: '))
host3 = (input('server 2 host: '))
port3 = int(input('server 2 port: '))
conn1.bind((host1, port1))
conn2.connect((host2, port2))
conn3.connect((host3, port3))
conn2.settimeout(1)
conn3.settimeout(1)
print("[proxy] : ready to proxy data...\n")
i = 0
j = 1
while j < 11:
    recv, addr1 = conn1.recvfrom(2048)
    if(i == 0):
        conn2.sendto(recv, (host2,port2))
        i = 1
        try:
            recv, addr2 = conn2.recvfrom(2048)
            conn1.sendto(recv,addr1)
        except socket.timeout:
            i = i
    else:
        conn3.sendto(recv, (host3,port3))
        i = 0
        try:
            recv, addr3 = conn3.recvfrom(2048)
            conn1.sendto(recv,addr1)
        except socket.timeout:
            i = i
    j+=1
conn1.close()
conn2.close()
conn3.close()
