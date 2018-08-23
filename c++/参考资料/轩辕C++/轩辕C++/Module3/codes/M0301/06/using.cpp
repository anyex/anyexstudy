#include <iostream>

namespace ns1 {
	const int SIZE = 64;
	void f();
}

void ns1::f() {
}

namespace ns2 {
	const int SIZE = 512;
	void f();
}

void ns2::f() {
}


int main() {
	int m = ns2::SIZE;
	ns1::f();
}
