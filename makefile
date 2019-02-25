P=program1
S=test
CFLAGS= -g -Wall

all: $(P)

$(P): $(P).o
	g++ $(CFLAGS) $(P).o -o $(P)
	
$(P).o: $(P).cpp
	g++ $(CFLAGS) -c $(P).cpp -o $(P).o
	
$(S): $(S).o
	g++ $(CFLAGS) $(S).o -o $(S)
	
$(S).o: $(S).cpp
	g++ $(CFLAGS) -c $(S).cpp -o $(S).o
	
run: $(P)
	./$(P)
	
clear_run: $(P)
	clear; clear; make run
	
debug: $(P)
	gdb ./$(P)
	
clean:
	rm -rf $(P)
	rm -rf $(P).o
	rm -rf $(S)
	rm -rf $(S).o