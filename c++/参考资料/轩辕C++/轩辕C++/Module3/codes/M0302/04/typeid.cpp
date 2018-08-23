#include <iostream>
#include <typeinfo>
using namespace std;

class A {
public:
	virtual void f() {}
};

class B : public A {
	
};

class C : public B {

};

void f(A* a) {
	B* b = dynamic_cast<B*>(a);
	if (b != 0) {
		cout << "Type B\n";
	}

	cout << typeid(*a).name() << endl;
}

int main() {
	C c;
	f(&c);
}
