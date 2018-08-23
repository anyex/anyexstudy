#include <iostream>
using namespace std;

int main() {
	int a = 9;
	int& r = a;

	cout << &a << ' ' << &r << endl;
	r += 7;
	cout << a << endl;

	int& r2;
	r2 = a;
}

