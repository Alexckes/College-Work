# Echo server program
import socket
import random

with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as conn:
    host = ''
    port = int(input('port: '))
    conn.bind((host, port))
    print("[server] : ready to accept data...\n")
    r = '1 2 3 4 5 6 7 8 9 10'.split()
    random.shuffle(r)

    i = 0
    while i < 10:
        recv, addr = conn.recvfrom(2048)
        recv = recv.decode()
        if(recv == "PING"):
            print("[client] : PING\n")
            if(r[i] != '10' and r[i] != '9' and r[i] != '8'):
                conn.sendto("PONG".encode(), addr )
            else:
                print("[server] : packet dropped\n")
        i+=1
    conn.close()