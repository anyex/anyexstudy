#include <iostream>
using namespace std;

struct A {
	A() {
		cout << "A::A()\n";
//		throw int(1);
	}

	~A() {
		cout << "A::~A()\n";
	}
};


int main() {
	try {
		A a;
		throw int(0);
		cout << "1------------------\n";
	} catch (int a) {

	}
	cout << "2------------------\n";
}
