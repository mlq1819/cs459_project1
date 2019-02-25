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
		if(type.compare("hex")==0){
			cout << "Specify input hex or quit: " << endl;
			cin >> input;
			cout << hex << input << endl;
			cout << ((char) input) << endl;
		} else {
			cout << "Specify input char or quit: " << endl;
			cin >> input;
			cout << ((char) input) << endl;
			cout << hex << input << endl;
		}
		type = "";
		input=0;
	}
	return 0;
}