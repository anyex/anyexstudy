#include <iostream>
using namespace std;

int main() {
	const int cn; // 错误，必须同时初始化
	cn = 0; // 错误，必须同时初始化
	const int m = 0;
	m = 9; // 错误，m不可更改
	const char* cp = "Tiger"; // 注意不是const 指针
	// char const* cp = "Tiger"; // 同上效果
	cp[2] = 'm'; // 错误，cp指向的对象不可更改
	++cp; // 可以，指针本身不是const变量
	int k = 0;
	int* const kp = &k;
	const int* const ckp = &k; // 指针和其指向的对象均不可通过ckp更改
	++kp; // 错误，const 指针不能改变
	const int& kr = k;
	++kr; // 错误，不能通过const 引用去改变k的值
	++k; // 没问题
	int& jr = 1; // 错误，非const引用不能引用文字常量
	const int& jr2 = 1; // 或int const& jr2 = 1; // OK
	int& const jr3 = 1; // 没有对 T＆类型的const修饰
}

