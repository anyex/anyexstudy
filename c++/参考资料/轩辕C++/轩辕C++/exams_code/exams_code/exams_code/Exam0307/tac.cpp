#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

void tac(char* argv[]) {

	//partial implementation of replacement, \L, \U
	string line = "";
	vector<string> vec;

	//read fstream
	fstream file;
	file.open(argv[1], ios::in);

	if (file.is_open()) {
		while (!file.eof()) {
			getline(file, line);
			vec.push_back(line);
		}
	}

	file.close();
	for (int i = vec.size() - 1; i >= 0; --i)
		cout << vec[i] << endl;
}

int main(int argc, char* argv[]) {
	tac(argv);
}

