#include <iostream>
#include <set>
using namespace std;

struct Date {
	int y, m, d;
};

class Employee {
    string firstName;
    string homeName;
    char middleInitial;
    Date hiringDate;
    short department;
public:
	virtual void print() const;
};

void Employee::print() const {
	cout << "Employee::print()\n";
}

class Manager : public Employee {
    set<Employee*> group;
    short level;
public:
	virtual void print() const;
	void f0() {
		Employee::print();
	}
};

void Manager::print() const {
	cout << "Manager::print()\n";
}

void f1(Employee& e) {
	e.print();
}

int main() { 
	Employee e;
	Manager m;
	m.f0();

	cout << "--------------------\n";
	f1(e);
	f1(m);
}
