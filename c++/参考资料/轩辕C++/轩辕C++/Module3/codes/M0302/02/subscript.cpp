#include <iostream>
using namespace std;

class Array {
	int _size;
	int* array;

public:
	Array(const int& len) : _size(len) {
		array = new int[_size];
	}

	int operator[](const int& index) const {
		return array[index];
	}

	int& operator[](const int& index) {
		return array[index];
	}
};

int main() {
	Array ar(5);
	int a1 = ar[1];
	ar[0] += 100;

	cout << a1 << endl;
	cout << ar[0] << endl;
}
