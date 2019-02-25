#ifndef DEBUG
#define DEBUG true
#endif
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <sstream>
#define BUFSIZE 256

using namespace std;

void secret(void){
	cout << "SECRET TUNNEL" << endl;
	exit(0);
}

int main(int argc, char** argv){
#if DEBUG
cout << "Buffer Size = BUFSIZE" << endl;
#endif
	string arg;
	cout << "Input \"password\" or \'AUTO\' for automatically generated input:" << endl;
	getline(cin, arg);
	if(arg.compare("AUTO")==0){
		cout << "Auto-generating..." << endl;
		arg = string('s', ((size_t) BUFSIZE)+1);
		cout << arg;
	}
	cout << "User input: \"" << arg << "\"" << endl;
	
	char buffer[BUFSIZE];
	strcpy(buffer, arg.c_str());
	return 0;
}