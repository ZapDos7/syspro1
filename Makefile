CC=g++  -std=c++11
CFLAGS=-c -Wpedantic -Ofast
LDFLAGS=
SOURCES=diseaseMonitor.cpp date.cpp record.cpp ht.cpp bht.cpp tree.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=diseaseMonitor


all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

run:
	./$(EXECUTABLE) -p small.csv -h1 2 -h2 3 -b 1024

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
