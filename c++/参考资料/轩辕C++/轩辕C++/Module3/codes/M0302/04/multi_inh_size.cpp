#include <iostream>
using namespace std;

class A {
//	int k;
//	double d;
public:
	void f() {
		cout << "A::f()\n";
	}
};

class B : public  virtual  A {

};

class C : public  virtual  A {

};

struct D : B, C {

};

int main() {
	D d;
	d.f();
	cout << sizeof(D) << endl;
}
