#include <iostream>
using namespace std;

int main() {
	int* p1 = new int;
//	void* pp = operator new(sizeof(int));
//	int* p1 = new (pp) int;
	int* p2 = new int(9);
	cout << *p1 << ' ' << *p2 << endl;

	void* chunko = operator new(2 * sizeof(int));
	int* chunk = static_cast<int*>(chunko);
	int* p3 = new(chunk) int;
	int* p4 = new(chunk + 1) int(8);
	cout << *p3 << ' ' << *p4 << endl;
	
	delete p1;
	delete p2;

	operator delete(chunk);

	int* q = new int[8];
	cout << *q << endl;
	delete[] q;
}
