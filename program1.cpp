#ifndef DEBUG
#define DEBUG true
#endif
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <string>
#define BUFSIZE 256

using namespace std;

void secret(void){
	cout << "SECRET TUNNEL" << endl;
	exit(0);
}

int stack_problem(char* arg){
	cout << "In stack_problem: arg=" << arg << endl;
	char buffer[BUFSIZE];
	strcpy(buffer, arg);
	
	return 0;
}

int heap_problem(){
	
	return 0;
}

int main(int argc, char** argv){
#if DEBUG
cout << "In program1:\n[";
for(int i=0; i<argc; i++){
	if(i>0)
		cout << ", ";
	cout << argv[i];
}
cout << "]" << endl;
#endif	
	if(string(argv[1]).compare("stack")==0){
		if(argc>=3)
			return stack_problem(argv[2]);
		else {
			char emtstr = '\0';
			return stack_problem(&emtstr);
		}
	} else if (string(argv[1]).compare("heap")==0){
		return heap_problem();
	}
	return 0;
}