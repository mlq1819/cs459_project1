P=program1
S=prgm1_stack_exploit
H=prgm1_heap_exploit
CFLAGS= -g -Wall

all: $(P) $(S) 

$(S): $(S).o $(P).o
	g++ $(CFLAGS) $(S).o -o $(S)
	
$(P).o: $(P).cpp $(P).h
	g++ $(CFLAGS) -c $(P).cpp -o $(P).o

$(S).o: $(S).cpp $(P).h
	g++ $(CFLAGS) -c $(S).cpp -o $(S).o
	
run_stack: $(P) $(S)
	./$(S) stack test
	
clean:
	rm -rf $(S)
	rm -rf $(S).o
	rm -rf $(P).o
	