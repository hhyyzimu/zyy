CFLAGS+=-pthread
LDFLAGS+=-pthread
all:client

client:client.o
	gcc -o $@ $^ $(CFLAGS) $(LDFLAGS)

clean:
	rm client *.o -rf
