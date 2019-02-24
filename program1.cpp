#if ndef DEBUG
#define DEBUG false
#endif
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define BUFSIZE 256

using namespace std;

void secret(void){
	cout << "SECRET TUNNEL" << endl;
	exit(0);
}

int main(int argc, char** argv){
	char buffer[BUFSIZE];
	strcpy(buffer, argv[1]);
}

