#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
	ifstream in(argv[1], ios::in | ios::binary);
	ofstream out(argv[2]);

	if (!in) {
		cout << "Open file failed.\n";
		return 1;
	}

	char ch;
	long i;

	// go to end of file
	in.seekg(0, ios::end);
	// num of bytes in file
	i = (long) in.tellg();
	// remove eof
	i -= 2;

	for (; i >= 0; --i) {
		in.seekg(i, ios::beg);
		in.get(ch);
		cout << ch;
		out << ch;
	}
	in.close();
	out.close();
}//
