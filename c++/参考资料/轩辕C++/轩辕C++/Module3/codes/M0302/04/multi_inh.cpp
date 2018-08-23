#include <iostream>
using namespace std;

class A {
public:
	void f() {
		cout << "A::f()\n";
	}
};

class B {
public:
	void f() {
		cout << "B::f()\n";
	}
};

class D : public A, public B {
public:
	using B::f;

	void f2() {
		f();
	}

};

void func(A* a, B* b) {
	a->f();
	b->f();
}

int main() {
	D d;
	func(&d, &d);
	
	d.A::f();
	d.f();
	d.f2();
}
