#include <iostream>
using namespace std;

int main() {
	int i = 1;
	int a[6] = {12, 2, 5, 6, 89, 30};
	a[i] = i++;
	for (int j = 0; j < 6; ++j)
		cout << a[j] << ' ';
	cout << endl;

	int n = 1;
	int k;
	k = 0, ++n, n++;
	cout << k << ' ' << n << endl;
}
