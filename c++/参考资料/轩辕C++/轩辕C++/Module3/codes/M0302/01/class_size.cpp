#include <iostream>
using namespace std;

class A {
	int a;
	bool b;
public:
	void print();
};

class B {
	int n;
	int m;
	static int k;
};

struct C {
	int x : 1;
	bool b : 1;
	double d: 4;
};

int main() {
	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;
	B b;
	cout << sizeof(b) << endl;
	cout << sizeof(C) << endl;
	C c;
	const int& ir = c.x;
}
