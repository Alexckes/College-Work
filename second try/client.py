import socket

conn = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
host = input('host: ')
port = int(input('port: '))
conn.connect((host, port))
conn.settimeout(1)
i = 1
while i < 11:
    conn.sendto("PING".encode(), (host,port))
    print("%d. Sent PING ... ",i)
    try:
        recv = conn.recvfrom(2048)
        print("Received b'PONG'\n")
    except socket.timeout:
        print("Timed Out\n")
    i+=1
conn.close()
