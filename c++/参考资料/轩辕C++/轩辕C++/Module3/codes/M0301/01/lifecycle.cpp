#include <iostream>
using namespace std;

struct B {
	B(const int& id) : _id(id) {
		cout << "Constructor of B with id: " << _id << endl;
	}	

	~B() {
		cout << "Destructor of B with id: " << _id << endl;
	}	

private:
	int _id;
};

int op = 12;

int main() {
	cout << "begin-------------" << endl;
	B* b0;
	{
		B b1(1);
		B* b2 = new B(2);
		b0 = b2;
	}
	
	delete b0;
	cout << "end-------------" << endl;

	cout << op << endl;
}
