#include <iostream>
using namespace std;

int& leftVal(int& n) { return n; }
int rightVal() { return 12; }

int main() {
	int ar[8];
	ar; // 左值
	ar[0] = 12; // 左值
//	&ar[0] += 1; // 右值
	int* p = ar; 
	*p = 8; // p左值
	"Tiger"; 12; 'k'; // 文字常量为右值
	const int n = 0; 
//	n = 9; // 常量n为右值
//	int(9) = 2; // 右值
	int a = 8;
//	rightVal() += 3; // 右值
	cout << (leftVal(a) += 5) << endl; // 左值
	++a; // 左值
	a++; // 右值
	ar[1] = ++a; // 左值可以隐式转为右值
}

