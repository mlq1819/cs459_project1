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

void public_function(string arg){
	char buffer[BUFSIZE];
	memset(buffer, 'B', BUFSIZE);
	strcpy(buffer, arg.c_str());
}

void secret(void){
	cout << "SECRET TUNNEL" << endl;
	exit(0);
}

int main(int argc, char** argv){
#if DEBUG
cout << "BUFSIZE: " << BUFSIZE << endl;
#endif
	string arg;
	cout << "Input \"password\" or \'AUTO\' for automatically generated input:" << endl;
	getline(cin, arg);
	if(arg.compare("AUTO")==0){
		cout << "Auto-generating..." << endl;
		arg = string(BUFSIZE+1, 's');
	}
	cout << "User input: \"" << arg << "\"\nInput.length: " << arg.length() << endl;
	
	public_function(arg);
	
	return 0;
}