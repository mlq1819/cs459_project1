P=program1
CFLAGS= -g -Wall

all: $(P)

$(P): $(P).o
	g++ $(CFLAGS) $(P).o -o $(P)
	
$(P).o: $(P).cpp
	g++ $(CFLAGS) -c $(P).cpp -o $(P).o
	
run: $(P)
	./$(P)
	
no_flags: $(P).cpp
	g++ $(P).cpp -o $(P)
	
clear_run: $(P)
	clear; clear; make run
	
debug: $(P)
	gdb ./$(P)
	
clean:
	rm -rf $(P)
	rm -rf $(P).o