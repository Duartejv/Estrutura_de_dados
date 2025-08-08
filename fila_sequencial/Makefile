CC = gcc
CFLAGS = -Wall -Wextra -g
OBJ = main.o fila.o

all: fila

fila: $(OBJ)
	$(CC) $(CFLAGS) -o fila $(OBJ)

main.o: main.c fila.h
fila.o: fila.c fila.h

clean:
	rm -f *.o fila
