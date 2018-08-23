#include <iostream>
using namespace std;

struct S1 {
	int a;
	double d;
	bool b;
	bool g;
};

void S1() {
}

int main() {
	struct S1 s = { 12, 2.09, true };
	cout << s.a << ' ' << s.d << ' ' << s.b << endl;

	struct S1* sp = new struct S1;
	sp->a = 38;
	cout << sp->a << ' ' << sp->d << ' ' << sp->b << endl;
	delete sp;

	cout << sizeof(s) << endl;
}

