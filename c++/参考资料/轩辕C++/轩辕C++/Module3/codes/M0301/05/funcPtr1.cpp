#include <iostream>
using namespace std;

int add(int a, int b) { return a + b; }

int subtract(int a, int b) { return a - b; }
int f1(int a, int b) { return a * a + b * a; }

int (*fp)(int, int); // 函数指针的定义

int  main() {
	int i = 8, j = 3;
	fp = &f1; // 函数指针的赋值，取址符 & 可省略
	cout << fp(i, j) << endl; // 函数指针的使用
	fp = subtract; // 函数指针的赋值
	cout << fp(i, j) << endl; // 函数指针的使用
}
