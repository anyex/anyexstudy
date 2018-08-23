#include <iostream>
using namespace std;

void f(int a); 

void f2(long n) {
}

void f2(double n) {
}

int main() {
	void f(double);
	f(7);
	f2(1); // ambiguous
}

void f(int a) {
	cout << "f(int a)\n";
}

void f(double a) {
	cout << "f(double a)\n";
}
