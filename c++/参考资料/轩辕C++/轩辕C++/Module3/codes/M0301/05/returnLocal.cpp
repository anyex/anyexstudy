#include <iostream>
using namespace std;

int* f1() {
	int a = 12;
	return &a; // 危险！
}

int& f2() {
	int a = 12;
	return a; // 危险！
}

int main() {
	cout << f2() << endl;
}
