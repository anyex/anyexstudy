class X {
public:
    void f1() {}
    // ...
};
class Y1: public X { };
class Y2: protected X { };

class Y3 : private X { void f(Y1* py1, Y2* py2, Y3* py3); };

void f(Y1* py1, Y2* py2, Y3* py3) {
    X* px = py1; // OK, X是Y1的public基类
    py1->f1(); // OK

     px = py2; // Error, X是Y2的protected基类
    py2->f1(); // Error

    X* px = py3; // Error, X是Y3的private基类
    py3->f1(); // Error
}

class Z2 : public Y2 { void f(Y1* py1, Y2* py2, Y3* py3); };

void Z2::f(Y1* py1, Y2* py2, Y3* py3) {
    X* px = py1; // OK, X是Y1的public基类
    py1->f1(); // OK

    px = py2; // OK, X是Y2的protected基类且Z2是Y2的派生类
    py2->f1(); // OK ??

    px = py3; // Error, X是Y3的private基类
    py3->f1(); // Error
}

void Y3::f(Y1* py1, Y2* py2, Y3* py3) {
    X* px = py1; // OK, X是Y1的public基类
    py1->f1(); // OK

    px = py2; // Error, X是Y2的protected基类
    py2->f1(); // Error

    px = py3; // OK, X是Y3的private基类但Y3::f()是Y3的成员
    py3->f1(); // OK
}


int main() {
	Y1 y1;
	Y2 y2;
	Y3 y3;

	f(&y1, &y2, &y3);
}
