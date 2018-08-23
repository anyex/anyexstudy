#include <iostream>
using namespace std;

void add5(int& src) {
	src += 5;
}

void subtract5(int& src) {
	src -= 5;
}

void multiply5(int& src) {
	src *= 5;
}

void doSomeThing(int& src) {
	src -= 3;
	cout << "after src - 3 + 5: " << (src += 5) << endl;
}

typedef void (*action) (int& src);

void forEach(int a[], const int& len, action func) {
	for (int i = 0; i < len; ++i)
		func(a[i]);
}

void print(int a[], const int& len) {
	for (int i = 0; i < len; ++i)
		cout << a[i] << ' ';
	cout << endl;
}

int main() {
	int a[] = {12, 6, 90, 8};

	print(a, 4);
	forEach(a, 4, add5);
	print(a, 4);
	forEach(a, 4, multiply5);
	print(a, 4);
	cout << "------------------------" << endl;
	forEach(a, 4, doSomeThing);
}

