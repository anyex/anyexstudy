#include <iostream>
using namespace std;

void ref(int& n) {
	n += 8;
}

int main() {
	int i = 9;
	ref(i);
//	ref(5);
//	const int k = 6;
//	ref(k);
	short s = 8;
	ref(s);
}
