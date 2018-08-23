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
	void print() const;
};

void Employee::print() const {
	cout << "Employee::print()\n";
}

class Manager : public Employee {
    set<Employee*> group;
    short level;
public:
	void print() const;
};

void Manager::print() const {
	Employee::print();
//	cout << "first name: " << firstName << endl;
	cout << "Manager::print()\n";
//	print();
}

int main() { 
	Manager m;
	m.print();	
}
