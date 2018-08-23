#include <iostream>
#include <algorithm>
using namespace std;

struct Functor {
	Functor(const int& m) : n(m) {

	}

	void operator() (int& src) {
		src += n;
	}

private:
	int n;
};

int main() {
	int a[] = { 12, 23, 545, 98, 8 };

	cout << a[0] << ' ' << a[4] << endl;
	for_each(a, a + 5, Functor(12));
	cout << a[0] << ' ' << a[4] << endl;

	cout << a[0] << ' ' << a[4] << endl;
	for_each(a, a + 5, Functor(62));
	cout << a[0] << ' ' << a[4] << endl;
}
