#include <iostream>
using namespace std;

int main() {
	const int LEN = 8;
	int a[LEN];
/*
	int n = 0;
	for (; n < LEN; ++n)
		a[n] = n * 12;
*/
	for (int n = 0; n < LEN; ++n) {
		if (5 == n)
			continue;
		a[n] = n * 12;
	}

	for (int n = 0; n < LEN; ++n)
		cout << a[n] << ' ';
	cout << endl;
}
