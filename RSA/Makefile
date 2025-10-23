CFLAGS = -O
CC = g++

list: rsa.o driver.o
	$(CC) $(CFLAGS) -o list rsa.o driver.o

rsa.o: rsa.cpp
	$(CC) $(CFLAGS) -c rsa.cpp

driver.o: driver.cpp
	$(CC) $(CFLAGS) -c driver.cpp

clean:
	rm -f core *.o
