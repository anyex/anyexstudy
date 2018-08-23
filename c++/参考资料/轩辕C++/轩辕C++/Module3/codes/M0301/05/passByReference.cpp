#include <iostream>
using namespace std;

void swap1(int a, int b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void swap2(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int main() {
	int i = 8, j = 12;
	cout << "before swap: i == " << i << ", j == " << j << endl;
	swap2(i, j);
	cout << "after swap: i == " << i << ", j == " << j << endl;
	
}
