#include <iostream>
#include <algorithm>
using namespace std;

// Add 更好的方案，甚至不需要成员变量n
template<int n>
class Add {
public:
	void operator()(int& src) {
		src += n;
	}
};

void print(int a[], const int& len) {
	for (int i = 0; i < len; ++i)
		cout << a[i] << ' ';
	cout << endl;
}

int main() {
	int a[] = {12, 6, 90, 8};

	print(a, 4);
//	forEach(a, 4, add5);
	for_each(a, a + 5, Add<12>());
	print(a, 4);
	for_each(a, a + 5, Add<55555>());
	print(a, 4);
}

