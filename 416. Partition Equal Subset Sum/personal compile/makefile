CC=g++	#使用的編譯器
LDFLAGS=-std=c++17 -O3 -march=native
SOURCES= *.cpp
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE= ./Partition_Equal_Subset_Sum
INCLUDES= *.h

all: $(SOURCES) ./$(EXECUTABLE)

./$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o:  %.c  ${INCLUDES}
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o ./$(EXECUTABLE)
