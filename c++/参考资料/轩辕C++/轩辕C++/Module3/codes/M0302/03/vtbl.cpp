#include <iostream>
using namespace std;

class A {

public:
	virtual ~A() {}
	virtual void f();
};

class B : public A {
//	int k;
public:
	void f();
};

int main() {
	cout << "sizeof(A): " << sizeof(A) << endl;
	cout << "sizeof(B): " << sizeof(B) << endl;
}
