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
	if (Jan == m || Mar == m || May == m || Jul == m ||
		Aug == m || Oct == m || Dec == m)
		return 31;
	else if (Apr == m || Jun == m || Sep == m || Nov == m)
		return 30;
	else
		return 28 + isLeap(y);
}

void f(int m) {
	int i = 7;
	if (m = i)
		cout << "m == i" << endl;
	else
		cout << "m != i" << endl;
}

int main() {
	f(9);
}
