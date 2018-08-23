#include <iostream>
using namespace std;

int main() {
	char ca[] = "xuanyuan";
	cout << "size of ca: " << sizeof(ca) << endl;
	ca[2] = 'y';
	cout << ca << endl;

	const char* cb = "xuanyuan";
	cout << "size of cb: " << sizeof(cb) << endl;
//	cb[2] = 'y';
	cout << &cb[2] << endl;
}

