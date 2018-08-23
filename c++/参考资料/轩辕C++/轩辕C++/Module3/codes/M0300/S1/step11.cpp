#include <iostream>
using namespace std;

void forEach(int a[], const int& len) {
	for (int i = 0; i < len; ++i)
		a[i] += 5;
}

void print(int a[], const int& len) {
	for (int i = 0; i < len; ++i)
		cout << a[i] << ' ';
	cout << endl;
}

int main() {
	int a[] = {12, 6, 90, 8};

	print(a, 4);
	forEach(a, 4);
	print(a, 4);
}

