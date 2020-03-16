CC=g++  -std=c++11
CFLAGS=-c -Wpedantic -Ofast
LDFLAGS=
SOURCES=diseaseMonitor.cpp date.cpp record.cpp ht.cpp countryht.cpp diseaseht.cpp tree.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=diseaseMonitor


all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

run:
	./$(EXECUTABLE) -p small.csv -h1 40 -h2 40 -b 1024

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
