all:server client
foo=127.0.0.1 1100
server:
	gcc ssl_server.c -o server -lssl -lcrypt
	./server &
client:
	gcc ssl_client.c -o client -lssl -lcrypt
	./client $(foo)
clean:
	-rm -rf server client *.o .*.c.swp

.PH0NY:
	clean default
