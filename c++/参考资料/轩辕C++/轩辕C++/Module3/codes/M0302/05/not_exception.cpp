#include <iostream>
using namespace std;

void f() {
	int a[3][3];
	a[0][2] = 120;

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			if (120 == a[i][j])
				throw pair<int,int>(i, j);
}

int main() {
	try {
		f();
	} catch(pair<int,int> p) {
		cout << p.first << ' ' << p.second << endl;
	}
}
