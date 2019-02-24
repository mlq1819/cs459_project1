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

void generate(char * str, unsigned int len){
	for(unsigned int i=0; i<len; i++){
		str[i]='s';
	}
}

int main(int argc, char** argv){
	char * arg;
	if(argc>=3)
		arg=argv[2];
	else{
		arg = (char *) malloc(sizeof(char) * (BUFSIZE+1));
		generate(arg, BUFSIZE+1);
	}
	
	cout << "In stack_problem: arg=" << argv[3] << endl;
	
	char buffer[BUFSIZE];
	strcpy(buffer, argv[3]);
	
	if(argc<3){
		free arg;
		arg=NULL;
	}
	return 0;
}