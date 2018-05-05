CC = gcc
CFLAGS  = -std=c11 -g -Wall
SRC = $(addprefix src/, main.c acceso.c cargar.c menu.c utilidades.c incidencias.c usuarios.c vehiculos.c viajes.c)
OBJS := $(SRC:.c=.o)
EXE = esi-share

all: $(EXE)

run: $(EXE)
	./$<

run_v: $(EXE)
	valgrind ./$<

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
	@rm -f $(OBJS)

$(OBJS): $(SRC)

.PHONY: clean

clean:
	rm -f $(EXE)
	cd docs/ && rm *.log *.out *.synctex.gz *.toc
