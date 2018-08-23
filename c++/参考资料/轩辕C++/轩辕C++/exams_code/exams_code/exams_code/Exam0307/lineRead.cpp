#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void lineRead(char* argv[]) {

	//partial implementation of replacement, \L, \U
	string line = "";
	int lineNum = 0;
	int lineDest = atoi(argv[2]);
	//read fstream
	fstream file;
	file.open(argv[1], ios::in);
	if (file.is_open()) {
		while (!file.eof()) {
			getline(file, line);
			++lineNum;
			if(lineNum == lineDest) {
				cout << line << endl;
				break;
			}
		}
	}

	file.close();
}


#include <boost/bind.hpp>
int f(int){
    return 0;
}

int main()
{
    boost::bind(f, "incompatible");      // OK so far, no call
    boost::bind(f, "incompatible");    // error, "incompatible" is not an int
    boost::bind(f, _1);                  // OK
    boost::bind(f, _1)(43);  // error, "incompatible" is not an int
}

//
////usage:lineRead filename lineNumber
//int main(int argc, char* argv[]) {
//	lineRead(argv);
//}

