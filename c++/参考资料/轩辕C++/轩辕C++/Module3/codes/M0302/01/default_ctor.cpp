#include <iostream>
using namespace std;

class A {
	int k;
//public:
	A() {
	}

	A(int n) {
	}
};

class B {
	int m;
	A a;

public:
	B() : m() {
	}

	void f() {
		cout << m << endl;
	}
};


int main() {
	A a;
}
