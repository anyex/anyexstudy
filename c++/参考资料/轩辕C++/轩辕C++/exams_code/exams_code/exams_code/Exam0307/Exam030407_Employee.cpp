/*
 * Exam030407_Employee.cpp
 *
 *  Created on: 2010-2-17
 *      Author: kwarph
 */

#include <iostream>
#include <fstream>
#include <iomanip>

#include <vector>

#include <cstring>
#include <cstdlib>

#include <boost/lexical_cast.hpp>

using namespace std;

class Employee {
    string _name;
    string _email;
    int _age;

public:
    Employee() :
        _name(), _email(), _age() {
    }

    Employee(const string& name, const string& email, int const& age) :
        _name(name), _email(email), _age(age) {
    }

    string getName() const {
        return _name;
    }

    void setName(const string& name) {
        _name = name;
    }

    string getEmail() const {
        return _email;
    }

    void setEmail(const string& email) {
        _email = email;
    }

    int getAge() const {
        return _age;
    }

    void setAge(const int& age) {
        _age = age;
    }

    friend ostream& operator<<(ostream& os, const Employee& e);
    friend istream& operator>>(istream& is, Employee& e);
};

ostream& operator<<(ostream& os, const Employee& e) {
    os << e._name << ',';
    os << e._email << ',';
    os << e._age << endl;
    return os;
}

istream& operator>>(istream& is, Employee& e) {
    string line;
    getline(is, line);

    // TODO 以下语句不安全，没有对位置（string对象的下标）进行检查。

    size_t pos1 = line.find(',');
    e._name = line.substr(0, pos1);

    size_t pos2 = line.find(',', pos1 + 1);
    e._email = line.substr(pos1 + 1, pos2 - pos1 - 1);

    string ageStr = line.substr(pos2 + 1, string::npos);
    e._age = atoi(ageStr.c_str());

    return is;
}

void printSeparator(ostream& os, const vector<size_t>& maxLens) {
    if (maxLens.empty())
        return;

    const int n = maxLens.size();
    os << setfill('-') << right;
    for (int i = 0; i < n; ++i) {
        os << '+' << setw(maxLens[i] + 3);
    }
    os << '+' << endl;
}

void printHeader(ostream& os, const vector<size_t>& maxLens, const vector<
        string>& headers) {
    if (maxLens.empty() || headers.empty())
        return;

    const int n = headers.size();
    os << setfill(' ') << left;
    os << "| " << setw(maxLens[0]) << headers[0]; // first field
    for (int i = 1; i < n; ++i) {
        os << " | " << setw(maxLens[i]) << headers[i];
    }
    os << " |" << endl;
}

void printRecords(const vector<size_t>& maxLens,
        const vector<bool>& alignments, const vector<vector<string> >& records, ostream& os = cout) {
    if (maxLens.empty() || records.empty())
        return;

    const int recordNum = records.size();
    const int n = records[0].size();
    for (int k = 0; k < recordNum; ++k) {
        os << setfill(' ');
        os.setf((alignments[0] ? ios::left : ios::right), ios::adjustfield);
        os << "| " << setw(maxLens[0]) << records[k][0]; // first field
        for (int i = 1; i < n; ++i) {
            os.setf((alignments[i] ? ios::left : ios::right), ios::adjustfield);
            os << " | " << setw(maxLens[i]) << records[k][i];
        }
        os << " |" << endl;
    }
}

void readEmployees(const char* file) {
    ifstream fin(file);
    if (!fin) {
        cerr << "Open file " << file << " failed." << endl;
        return;
    }

    vector<vector<string> > empls;
    Employee e;
    vector<size_t> maxLens(3);
    while (fin >> e) {
        if (maxLens[0] < e.getName().size())
            maxLens[0] = e.getName().size();
        if (maxLens[2] < e.getEmail().size())
            maxLens[2] = e.getEmail().size();

        vector<string> record;
        record.push_back(e.getName());
        record.push_back(boost::lexical_cast<string>(e.getAge()));
        record.push_back(e.getEmail());

        empls.push_back(record);
    }
    maxLens[1] = 5; // Age Field width

    printSeparator(cout, maxLens);
    // print table header
    vector<string> headers;
    headers.push_back("Name");
    headers.push_back("Age");
    headers.push_back("Email");
    printHeader(cout, maxLens, headers);
    printSeparator(cout, maxLens);

    // prepare alignment vector
    vector<bool> alignments;
    alignments.push_back(true);
    alignments.push_back(false);
    alignments.push_back(true);

    printRecords(maxLens, alignments, empls);
    printSeparator(cout, maxLens);
}

int main() {
    ofstream fout("employees.dat", ios::app);

    fout << Employee("thefirstname", "xuanyuan-soft@gmail.com", 22);
    fout << Employee("secondlongname", "somebody@gmail.com", 21);
    fout << Employee("heddo wei", "hhe@gmail.com", 121);
    fout.close();

    readEmployees("employees.dat");
}
