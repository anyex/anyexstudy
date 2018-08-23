#include <iostream>
using namespace std;

enum { A, B };
enum E2 { OK, CANCEL };

int main() {
	cout << A << endl;
//	cout << sizeof(A) << endl;

	E2 e = E2(3);
	E2 e2 = OK;
	cout << e2 << endl;
}
