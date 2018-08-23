#include <iostream>
using namespace std;

int main() {
	const int LEN = 8;
	int a[LEN];

	int n = 0;
	do {
		a[n] = n * 12;
		++n;
	} while (n < LEN);

	n = 0;
	while(n < LEN) {
		cout << a[n] << ' ';
		++n;
	}
	cout << endl;
}
