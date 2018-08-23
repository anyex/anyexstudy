#include <iostream>
using namespace std;

void f1() {
	throw int(8);
}

void f2() {
	throw double(2);
}

int main() {
	try {
		f1();
		f2();
	} catch (double d) {
		cout << d << endl;
	}/* catch (...) {
		cout << "catch all\n";
	}*/
	cout << "---------------------\n";
}
