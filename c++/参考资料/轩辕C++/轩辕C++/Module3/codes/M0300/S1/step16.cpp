#include <iostream>
#include <algorithm>
using namespace std;

template<typename T>
class Add {
public:
	Add(const T& m) : n(m) {
	}

	void operator()(T& src) {
		src += n;
	}

private:
	T n;
};

template<typename T>
void print(T a[], const int& len) {
	for (int i = 0; i < len; ++i)
		cout << a[i] << ' ';
	cout << endl;
}

int main() {
	int a[] = {12, 6, 90, 8};
	print(a, 4);
//	forEach(a, 4, add5);
	for_each(a, a + 5, Add<int>(12));
	print(a, 4);
	for_each(a, a + 5, Add<int>(555555));
	print(a, 4);

	double d[] = {12.9, 6.23, 90.7, 8.09};
	print<double>(d, 4);
	for_each(d, d + 5, Add<double>(2.02));
	print(d, 4);
}

