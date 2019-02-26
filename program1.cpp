#ifndef DEBUG
#define DEBUG false
#endif
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <sstream>
#define BUFSIZE 16

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

string getSolution(int addr){
	string input;
	cout << "Input filler length";
	getline(cin, input);
	int filler = stoi(input, NULL, 10);
	cout << "Filler length = " << filler << "\nAddr = ";
	cout << hex << addr;
	cout << endl;
	char char_arr[filler+4];
	for(int i=0; i<filler; i++){
		char_arr[i] = 's';
	}
	for(int i=filler; i<filler+4; i++){
		char_arr[i] = *((char *) (&addr + sizeof(char) * (i-filler)));
	}
	cout << "Generated output string: " << char_arr << endl;
	return &(new string(char_arr));
}

int main(int argc, char** argv){
#if DEBUG
cout << "BUFSIZE: " << BUFSIZE << endl;
#endif
	int uid;
    uid = getuid();
	if(uid==0)
		secret();
	else{
		string arg;
		cout << "Input \"password\" or \"AUTO:(addr)\"" << endl;
		getline(cin, arg);
		if(arg.c_str()[0]=='A' && arg.c_str()[1]=='U' && arg.c_str()[2]=='T' && arg.c_str()[3]=='O' && arg.c_str()[4]==':'){
			int addr = stoi(arg.substr(5, string::npos), NULL, 16);
			cout << "User has input \"AUTO:";
			cout << hex << addr;
			cout << "\"" << endl;
			arg = getSolution(addr);
		}
		cout << "User input: \"" << arg << "\"\nInput.length: " << arg.length() << endl;
		public_function(arg);
	}
	return 0;
}