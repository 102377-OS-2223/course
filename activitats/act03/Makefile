CC=gcc
CFLAGS=-c -Wall -O3 -Wstrict-prototypes -Wmissing-prototypes -Wshadow -Wconversion
SOURCES=main.c helpers.c log.c
OBJECTS=$(SOURCES:.c=.o)
EXE=ossh

all: $(SOURCES) $(EXE)

$(EXE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

execute: $(EXE)
	 ./$(EXE)

clean:
	/bin/rm -rf *.o
	/bin/rm -rf $(EXE)