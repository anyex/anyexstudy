#include <iostream>
using namespace std;

class Integer {
public:
    enum Base { DEC, HEX, OCT, BIN };

    // Constructors and destructors
    Integer(const Base& b = DEC);
    Integer(const int& val, const Base& b = DEC);
    Integer(const Integer& other);
    Integer& operator=(const Integer& other);
    Integer& operator=(const int& other);
    ~Integer();

    // Getters and Setters
    void setValue(const int& val);
    int getValue() const;
    void setBase(const Base& b);
    Base getBase() const;

    // Arithmetic operations
    Integer add(const Integer& right);    // +
    Integer& added(const Integer& right); // +=
    // Other arithmetic operations or bitwise operations
    // such as: multiply, bitwise and ...
    
    // // Relational operators
    bool isLessThan(const Integer& right) const; // < 
    bool equals(const Integer& right) const;     // ==

    // Relational operators
    bool operator<(const Integer& right) const;
    bool operator==(const Integer& right) const;

    // Arithmetic operators
    Integer operator+(const Integer& right);
    Integer operator+(const int& right);
    Integer& operator+=(const Integer& right);
    Integer& operator+=(const int& right);

	// Incement operations
	Integer& operator++();
	Integer operator++(int);

private:
    int value;
    Base base;
};

    // Constructors and destructors
Integer::Integer(const Base& b): value(), base(b) {

}

Integer::Integer(const int& val, const Base& b): value(val), base(b) {

}

Integer::Integer(const Integer& that): value(that.value), base(that.base) {

}

Integer& Integer::operator=(const Integer& that) {
	if (this != &that) {
		value = that.value;
		base = that.base;
	}

	return *this;
}

Integer& Integer::operator=(const int& other) {
	value = other;
	base = DEC;

	return *this;
}

Integer::~Integer() {

}

void Integer::setValue(const int& val) {
	value = val;
}

int Integer::getValue() const {
	return value;
}

Integer Integer::add(const Integer& right) {
	Integer res(*this);
	res.value += right.value;

	return res;
}

Integer& Integer::added(const Integer& right) {
	value += right.value;

	return *this;
}

bool Integer::isLessThan(const Integer& right) const {
	return value < right.value;
}

bool Integer::equals(const Integer& right) const {
	return value == right.value;
}

Integer Integer::operator+(const Integer& right) {
	Integer res(*this);
	res.value += right.value;

	return res;
}

Integer& Integer::operator+=(const Integer& right) {
	value += right.value;

	return *this;
}

Integer Integer::operator+(const int& right) {
	Integer res(*this);
	res.value += right;

	return res;
}

Integer& Integer::operator+=(const int& right) {
	value += right;

	return *this;
}

bool Integer::operator<(const Integer& right) const {
	return value < right.value;
}

Integer& Integer::operator++() {
	++value;
	return *this;
}

Integer Integer::operator++(int) {
	Integer res(*this);
	++value;

	return res;
}

bool Integer::operator==(const Integer& right) const {
	return value == right.value;
}

int main() {
    Integer m(8);
    Integer n(6);
    
	++m;
    cout << m.getValue()  << endl;
}
