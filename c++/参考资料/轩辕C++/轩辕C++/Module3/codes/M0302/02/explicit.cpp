#include <iostream>
using namespace std;

class A {
    int n;
    int k;
public:
    explicit A(const int& m) :
        n(m), k() {
    }

    void print() const {
        cout << n << endl;
    }
};

void f(const A& a) {
    a.print();
}

int main() {
    f(A(8));

    A b(12);
    b.print();
}

