#include <iostream>
#include <limits>
using namespace std;

int main() {
	cout << "max value of char: "
		 << int(numeric_limits<char>::max()) << endl;		
	cout << "min value of char: "
		 << int(numeric_limits<char>::min()) << endl;		
	cout << "max value of float: "
		 << numeric_limits<float>::max() << endl;		
	cout << "min value of float: "
		 << numeric_limits<float>::min() << endl;		
	cout << "max value of int: "
		 << numeric_limits<int>::max() << endl;		
	cout << "min value of int: "
		 << numeric_limits<int>::min() << endl;		
	cout << numeric_limits<int>::max() + 1 << endl;		
	cout << numeric_limits<int>::min() - 1 << endl;		

	int n = -2;
	unsigned m = 12;
	unsigned m1 = m + n;

	for (unsigned i = 0; i > n; ++i)
	cout << m1 <<  endl;
}
