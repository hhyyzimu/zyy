CFLAGS+=-pthread -I../include/
LDFLAGS+=-pthread

all:server

server:server.o medialib.o thr_chan.o thr_list.o
	gcc -o $@ $^ $(CFLAGS) $(LDFLAGS)

clean:
	rm server *.o -rf
