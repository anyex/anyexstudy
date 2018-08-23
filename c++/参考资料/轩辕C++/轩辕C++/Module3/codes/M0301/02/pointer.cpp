#include <iostream>
using namespace std;

int main() {
	int i = 0;
	int* p = &i;
	*p += 8;
	cout << "i: " << i << endl;
	cout << p << " " << &i << endl;

	p += 4;
	cout << p << " " << &i << endl;
	cout << *p << endl;
	*p += 120;
	cout << *p << endl;

	int* np = new int;
	cout << *np << endl;
	delete np;

	int arr[4] = { 12, 4, 9, 8 };
	int* ap = arr;
	int len = 4;
	while(len-- > 0) 
		cout << *ap++ << ' ';
	cout << endl;

	char ca[] = {'a', 't', 'p', 'i', '\0'};
	char* cp = ca;
	cout << cp << endl;
}

