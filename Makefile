CC = gcc

all: main.out

run: main.out
	./$<

main.out: main.o carga.o guardar.o
	$(CC) $^ -o $@

main.o: main.c carga.h guardar.h
	$(CC) -c $< -o $@

carga.o: carga.c carga.h tipos.h
	$(CC) -c $< -o $@

guardar.o: guardar.c guardar.h tipos.h
	$(CC) -c $< -o $@

.PHONY: clean

clean:
	rm -f *.o *.out
