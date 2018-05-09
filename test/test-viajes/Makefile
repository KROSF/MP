CC = gcc
CFLAGS  = -std=c11 -g -Wall
SRC = test-viajes.c utilidades.c viajes.c
OBJS := $(SRC:.c=.o)
EXE = test-viajes

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
