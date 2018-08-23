#include <iostream>
using namespace std;

int main() {
	int a[] = { 12, 98, 23, 7 };
	for (int i = 0; i < 4; ++i)
		cout << a[i] << ' ';
	cout << endl;

	for (int i = 0; i < 4; ++i)
		cout << *(a + i) << ' ';
	cout << endl;

	cout << *a << endl;
}

