P=program1
CFLAGS= -g -Wall

all: $(P)

$(P): $(P).o
	g++ $(CFLAGS) $(P).o -o $(P)
	
$(P).o: $(P).cpp
	g++ $(CFLAGS) -c $(P).cpp -o $(P).o
	
run: $(P)
	./$(P)
	
clear_run: $(P)
	clear; clear; make run
	
debug: $(P)
	gdb ./$(P)
	
clean:
	rm -rf $(P)
	rm -rf $(P).o
	