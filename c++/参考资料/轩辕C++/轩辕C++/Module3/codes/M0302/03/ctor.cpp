#include <iostream>
using namespace std;

class A {
	int i;

public:
	A() : i() {
		cout << "A::A()\n";
	}

	~A() {
		cout << "~A::A()\n";
	}
};

class B: public A {
	int n;
public:
	B(const int& k) : n(k) {
		cout << "B::B()\n";
	}

	~B() {
		cout << "~B::B()\n";
	}
};

class C: public B {
	int m;
public:
	C() : B(0), m() {
		cout << "C::C()\n";
	}

	~C() {
		cout << "~C::C()\n";
	}
};

int main() {
//	B b;
	C c;
}
