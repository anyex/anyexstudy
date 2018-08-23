#include <iostream>
using namespace std;

class X {
public:
	void f() {
		cout << "f()\n";
	}
};

class A : public virtual X {
public:
};

class B : public virtual X {
public:
};

class D : public A, public B {
public:
};

void func(A* a, B* b) {
	a->f();
	b->f();
}

int main() {
	D d;
	func(&d, &d);
	d.f();
}
