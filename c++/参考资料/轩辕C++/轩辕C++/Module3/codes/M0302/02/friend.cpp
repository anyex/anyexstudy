#include <iostream>
using namespace std;

class A;

//void fg(A a);

class B {
	int m;
public:
	void fb() {
		cout << "B::fb()\n";
	}

	friend class A;
};

class A {
	friend void fg(A a);
	int n;
public:
	void fa(B b) {
		cout << "B::m==" << b.m << endl;
		cout << "A::fa()\n";
	}
};

void fg(A a) {
	cout << "A::n==" << a.n << endl;
	cout << "fg()\n";
}

int main() {
	B b;
	A a;
	a.fa(b);

	fg(a);
}
