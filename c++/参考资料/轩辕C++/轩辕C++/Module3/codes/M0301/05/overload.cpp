#include <iostream>
using namespace std;

void f(int a) {
}

void f(int a, int b = 0) {
}

int main() {
	f(8);	// ambiguous
}
