CC=g++  -std=c++11
CFLAGS=-c -Wpedantic -Ofast -Wall
LDFLAGS=
SOURCES=diseaseMonitor.cpp date.cpp record.cpp ht.cpp aht.cpp bb.cpp tree.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=diseaseMonitor
FILE=-p small.txt
ARGS=-h1 40 -h2 40 -b 1024
VAL=valgrind --leak-check=full
GDB=gdb


all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

run:
	./$(EXECUTABLE) $(FILE) $(ARGS)

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

val:
	$(VAL) ./$(EXECUTABLE) $(FILE) $(ARGS)

gdb:
	$(GDB) $(EXECUTABLE)