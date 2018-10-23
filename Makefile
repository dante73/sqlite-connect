CC=		g++
LIBS=	-lsqlite3
STD=	_GNU_SOURCE
OBJS=	DbAdmin.o conecta.o

.c.o:
	$(CC) -c -Wall $(CFLAGS) -D$(STD) $<

all:	conecta

conecta: $(OBJS)
	$(CC) $(LIBS) $(OBJS) -o conecta

clean:
	rm -f *.o core

clobber: clean
	rm -f conecta

# End Makefile
