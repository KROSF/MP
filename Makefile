CC = gcc
CFLAGS  = -std=c99 -g
KROSF = carga.c carga.h guardar.c guardar.h tipos.h utilidades.c utilidades.h
JEDEX = menu.c menu.h acceso.c acceso.h
MIKE = usuarios.c usuarios.h
all: main.out

run: main.out
	./$<
	make clean

run_v: main.out
	valgrind ./$<

main.out: main.o carga.o guardar.o acceso.o utilidades.o menu.o
	$(CC) $(CFLAGS) $^ -o $@

main.o: main.c carga.h guardar.h acceso.h menu.h utilidades.h
	$(CC) -c $(CFLAGS) $< -o $@

carga.o: carga.c carga.h tipos.h
	$(CC) -c $(CFLAGS) $< -o $@

guardar.o: guardar.c guardar.h tipos.h
	$(CC) -c $(CFLAGS) $< -o $@

acceso.o: acceso.c acceso.h tipos.h utilidades.h
	$(CC) -c $(CFLAGS) $< -o $@

utilidades.o: utilidades.c utilidades.h
	$(CC) -c $(CFLAGS) $< -o $@

menu.o: menu.c menu.h tipos.h utilidades.h
	$(CC) -c $(CFLAGS) $< -o $@

jesus: delaHigueraCuestaJesus.tar.gz

rodrigo: SanabriaFloresCarlosRodrigo.tar.gz

project: esi-share.tar.gz

delaHigueraCuestaJesus.tar.gz: $(JEDEX)
	tar -cvf $@ $^

SanabriaFloresCarlosRodrigo.tar.gz: $(KROSF)
	tar -cvf $@ $^

esi-share.tar.gz: $(KROSF) $(JEDEX) main.c ficheros
	tar -cvf $@ $^

.PHONY: clean

clean:
	rm -f *.o *.out *.tar.gz
