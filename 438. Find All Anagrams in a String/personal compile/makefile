CC=g++	#使用的編譯器
LDFLAGS=-std=c++11 -O3 -march=native
SOURCES= *.cpp
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE= ./Find_All_Anagrams_in_a_String
INCLUDES= *.h

all: $(SOURCES) ./$(EXECUTABLE)

./$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o:  %.c  ${INCLUDES}
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o ./$(EXECUTABLE)
