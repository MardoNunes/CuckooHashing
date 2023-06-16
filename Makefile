CFLAGS = -Wall 
LDFLAGS = -lm

obj = myht.o libHash.o

all: myht

myht: ${obj}
	gcc ${CFLAGS} -o myht ${obj} ${LDFLAGS}

myht.o: myht.c libHash.h
	gcc ${CFLAGS} -c myht.c

libHash.o: libHash.c libHash.h
	gcc ${CFLAGS} -c libHash.c

clean:
	rm -f myht ${obj} *~

purge:
	rm -f myht ${obj} *~ *.o
