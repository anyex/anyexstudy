#include <iostream>
using namespace std;

class A {

};

int main() {
	cout << sizeof(A) << endl;
	A a1, a2;

	cout << (&a1 == &a2) << endl;
}
