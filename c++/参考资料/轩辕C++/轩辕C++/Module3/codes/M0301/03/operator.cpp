#include <iostream>
using namespace std;

int main() {
	int n = 9;
	cout << sizeof(int) << endl;
	cout << sizeof(n) << endl;

	int i = 0;
	cout << i++ << endl;
	cout << ++i << endl;

	char c = char(1);
	cout << int(~c) << endl;
	cout << int(char(254)) << endl;
	int m = 1;
	cout << ~m << endl;
	cout << (4294967294) << endl;
}
