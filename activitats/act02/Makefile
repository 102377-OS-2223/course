CC=gcc
CFLAGS=-c -Wall -O3 -Wstrict-prototypes -Wmissing-prototypes -Wshadow -Wconversion
TEST=test.c
OBJECTS_TEST=$(TEST:.c=.o)
TEST_EXECUTABLE=test

all: $(TEST) $(TEST_EXECUTABLE)

$(TEST_EXECUTABLE): $(OBJECTS_TEST)
	$(CC) $(OBJECTS_TEST) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

execute: $(TEST_EXECUTABLE)
	 ./$(TEST_EXECUTABLE)

clean:
	/bin/rm -rf *.o
	/bin/rm -rf $(TEST_EXECUTABLE)