#include <iostream>
using namespace std;

class A {
public:
	virtual void f() {}
};

class X : public A {

};

class Y : public X {

};

class B : public A {
public:
	void func() {
		cout << "B::func()\n";
	}
};


void func(A* a) {
	B* b = dynamic_cast<B*>(a);
	if (b == 0)
		cout << "cast failed.\n";
	else
		cout << "cast success.\n";
}

void func(A& a) {
	B& b = dynamic_cast<B&>(a);
	b.func();
}


int main() {
	Y a;
	B b;

	func(a);
	func(b);

}
