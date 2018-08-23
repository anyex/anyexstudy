#include <iostream>
using namespace std;

void varTest() {
	int n = 0;
	static int m = 0;

	cout <<	"++n == " << ++n << endl;;
	cout <<	"++m == " << ++m << endl;;
}

int main() {
	varTest();	
	varTest();	
	varTest();	
	varTest();	
}
