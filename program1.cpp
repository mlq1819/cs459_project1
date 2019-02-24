#ifndef DEBUG
#define DEBUG false
#endif
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#define BUFSIZE 256

using namespace std;

void secret(void){
	cout << "SECRET TUNNEL" << endl;
	exit(0);
}

int main(int argc, char** argv){
	if("stack".equals(argv[1])){
		if(argc>=3)
			return stack_problem(argv[2]);
		else
			return stack_problem("");
	} else if ("heap".equals(argv[1])){
		return heap_problem();
	}
	return 0;
}

int stack_problem(char* arg){
	char buffer[BUFSIZE];
	strcpy(buffer, argv[1]);
	
	return 0;
}

int heap_problem(){
	
	return 0;
}