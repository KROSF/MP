CC = gcc
CFLAGS  = -std=c99 -g
SRC = main.c acceso.c cargar.c menu.c utilidades.c incidencias.c usuarios.c vehiculos.c viajes.c
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

.PHONY: clean

clean:
	rm -f *.o $(EXE)
