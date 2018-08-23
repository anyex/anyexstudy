#include <iostream>
using namespace std;

class B {
public:
	virtual void f1() = 0;
	virtual void f2() = 0;
};

class D : public B {
	int m;
public:
	virtual void f1();
	virtual void f2();
};

void D::f1() {

}

void D::f2() {

}

int main() {
	D d;
	d.f1();
}
