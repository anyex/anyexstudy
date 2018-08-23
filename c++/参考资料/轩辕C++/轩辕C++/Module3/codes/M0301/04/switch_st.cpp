#include <iostream>
using namespace std;

enum Month {
	Jan = 1, Feb, Mar, Apr, May, Jun,
	Jul, Aug, Sep, Oct, Nov, Dec
};

bool isLeap(const int& y) {
	// ...
	return false;
}

int getDays(const int& y, const Month& m) {
	int d = 0;
	switch(m) {
	case Jan:
	case Mar:
	case May:
	case Jul:
	case Aug:
	case Oct:
	case Dec: d = 31; break;
	case Apr:
	case Jun:
	case Sep:
	case Nov: d = 30; break;
	case Feb: d = 28 + isLeap(y); break;
//	default: d = 31; break;
	}
	return d;
}

int main() {
	/*
	double d = 9.;
	switch(d) {
	case 9.0: cout << d << endl; break;
	case 9.1: cout << d + 12. << endl; break;
	}
	*/

	cout << getDays(2009, Jun) << endl;
}
