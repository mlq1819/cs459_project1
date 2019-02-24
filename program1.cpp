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
	char * arg[BUFSIZE];
	for(int i=0; i<BUFSIZE; i++)
		arg[i]='\0';
	cout << "Input \"password\" or \'AUTO\' for automatically generated input:" << endl;
	cin >> arg;
	bool autogen = false;
	if(strcmp(arg, "AUTO")==0){
		autogen = true;
		cout << "Auto-generating..." << endl;
		arg = (char *) malloc(sizeof(char) * (BUFSIZE + 1));
		generate(arg, BUFSIZE+1);
	}
	
	char buffer[BUFSIZE];
	strcpy(buffer, arg);
	
	if(autogen){
		free(arg);
		arg=NULL;
	}
	return 0;
}