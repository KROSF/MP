CC = gcc
CFLAGS  = -std=c99 -g
SRC = main.c acceso.c carga.c guardar.c menu.c utilidades.c
OBJS := $(SRC:.c=.o)
EXE = esi-share

all: $(EXE)

run: $(EXE)
	./$<

run_v: $(EXE)
	valgrind ./$<

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJS): $(SRC)

newmain: newmain.o usuarios.o cargar.o
	$(CC) $(CFLAGS) $^ -o $@

newmain.o usuarios.o cargar.o: newmain.c usuarios.c cargar.c

.PHONY: clean

clean:
	rm -f $(OBJS) $(EXE)
