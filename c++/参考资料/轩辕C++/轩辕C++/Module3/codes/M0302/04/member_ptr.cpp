#include <iostream>
using namespace std;

class Rectangle {
    int lb, rt;
public:
    void move() {
		cout << "Rectagle::move()\n";
	}

    void rotate() {
		cout << "Rectagle::move()\n";
	}

    void mirror() {
		cout << "Rectagle::move()\n";
	}

    typedef void (Rectangle::*Op)();
    void repeat(Op op, const int&);
};

void Rectangle::repeat(Op op, const int& times) {
    for (int i = 0; i < times; ++i) {
        (this->*op)();  // 不要忘记(this->*op)前后的括号！
    }
}

int main() {
    Rectangle r;
    r.repeat(&Rectangle::move, 3);
}
