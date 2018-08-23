#include <iostream>
using namespace std;

void passByValue(int n) {
	n += 100;
	cout << "n in func: " << n << endl;
}

int main() {
	int k = 3;
	passByValue(k);
	cout << k << endl;
}
