#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Employee {
public:
	Employee(string name, int age, string email) :
		Name(name), Age(age), Email(email) {
	}
	;

	void printName() const;
	void printAge() const;
	void printEmail() const;
	int getNameLength() const;
	int getEmailLength() const;

private:
	string Name;
	int Age;
	string Email;
};

void Employee::printName() const {
	cout << Name;
}
void Employee::printAge() const {
	cout << Age;
}
void Employee::printEmail() const {
	cout << Email;
}

int Employee::getNameLength() const {
	return Name.length();
}

//age length by default: 3

int Employee::getEmailLength() const {
	return Email.length();
}

int main() {

	//generate records
	Employee e1("test1 asd2", 32, "1asda@asd.com");
	Employee e2("test2 dcds", 33, "2asda@asd.com");
	Employee e3("test3 rdsa", 34, "3asda@asd.com");
	Employee e4("test4 bvds", 35, "4asda@asd.com");
	Employee e5("test5 cvbhhn", 36, "5asda@asd.com");

	vector<Employee> vec;
	vec.push_back(e1);
	vec.push_back(e2);
	vec.push_back(e3);
	vec.push_back(e4);
	vec.push_back(e5);

	int maxNameLen = 0;
	int maxEmailLen = 0;

	for (int i = vec.size() - 1; i >= 0; --i) {
		maxNameLen
				= vec[i].getNameLength() > maxNameLen ? vec[i].getNameLength()
						: maxNameLen;
		maxEmailLen
				= vec[i].getEmailLength() > maxEmailLen ? vec[i].getEmailLength()
						: maxEmailLen;
	}

	cout << maxNameLen << endl;
	cout << maxEmailLen << endl;

	cout << '+';
	cout.fill('-');
	cout.width(maxNameLen);
	cout << '+';

	cout.fill('-');
	cout.width(6);
	cout << '+';

	cout.fill('-');
	cout.width(maxEmailLen);
	cout << '+';

	cout << endl;
	//table head
	cout << "|Name";
	cout.fill(' ');
	cout.width(maxNameLen - 4);
	cout << '|';

	cout.width(5);
	cout.fill(' ');
	cout << "Age" << right;
	cout << '|';

	cout.fill(' ');
	cout.width(maxEmailLen);
	cout << "Email";
	cout << '|';

	cout << endl;

	cout << '+';
	cout.fill('-');
	cout.width(maxNameLen);
	cout << '+';

	cout.fill('-');
	cout.width(6);
	cout << '+';

	cout.fill('-');
	cout.width(maxEmailLen);
	cout << '+';

	cout << endl;

	//print employees
	for (int i = vec.size() - 1; i >= 0; --i) {
		cout.fill(' ');
		cout.width(maxNameLen);
		vec[i].printName();
		cout << '|';

		cout.width(5);
		cout.fill(' ');
		vec[i].printAge();
		cout << '|';

		cout.fill(' ');
		cout.width(maxEmailLen);
		vec[i].printEmail();
		cout << '|';

		cout << endl;
	}
}

