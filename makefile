P=program1
S=prgm1_stack_exploit
H=prgm1_heap_exploit
CFLAGS= -g -Wall

all: $(P)

$(P): $(P).o
	g++ $(CFLAGS) $(P).o -o $(P)

$(P).o: $(P).cpp
	g++ $(CFLAGS) -c $(P).cpp -o $(P).o

clean:
	rm -rf $(P)
	rm -rf $(P).o