#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){
	unsigned int input = 0;
	string type = "";
	while(type.compare("quit")!=0){
		while(type.compare("quit")!=0){
			cout << "Specify type: [hex, char; quit]" << endl;
			getline(cin, type);
			if(type.compare("hex") * type.compare("char")==0)
				break;
		}
		if(type.compare("quit")==0)
			break;
		cout << "Specify input or quit: " << endl;
		cin >> input;
		if(type.compare("hex")==0){
			cout << hex << input << endl;
			cout << ((char) input) << endl;
		} else {
			cout << ((char) input) << endl;
			cout << hex << input << endl;
		}
	}
	return 0;
}