#include <iostream>
using namespace std;

double d;
char* cp;

namespace ns1 {
	int n;		
}

int main() {
	int m;
	m = 8;
	static int p;
	cout << "double d: " << d << endl;
	cout << "char* cp: " << (cp == 0) << endl;
	cout << "ns1 n: " << ns1::n << endl;
	cout << "int m: " << m << endl;
	cout << "int p: " << p << endl;


	int i = 9;
	int j(9); 

	cout << i << " " << j << endl;
}
