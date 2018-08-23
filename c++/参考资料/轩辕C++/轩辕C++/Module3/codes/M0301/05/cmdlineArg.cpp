#include <iostream>
using namespace std;

int main(int argc, const char* argv[]) {
	cout << argv[0] << ": ";
	for (int i = 1; i < argc; ++i)
		cout << argv[i] << ' ';
	cout << endl;
}
