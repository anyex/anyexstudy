#include <iostream>
#include <memory>

using namespace std;

class A {
public:
	A() {
		cout << "A::A()\n";
	}

	~A() {
		cout << "A::~A()\n";
	}
	
	void f() {
		cout << "A::f()\n";
	}
};

int main() {
	auto_ptr<A> p1(new A());

	auto_ptr<A> p2(p1);
	p2->f();	
	p1->f();
	cout << "---------------------\n";
}
