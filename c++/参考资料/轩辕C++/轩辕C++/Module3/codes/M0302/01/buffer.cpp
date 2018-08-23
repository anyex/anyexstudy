#include <iostream>
using namespace std;

class Buffer {
	int _size;
	mutable int gOffset;
	int pOffset;
	char* array;

public:
	enum {
		BUF_SIZE = 512
	};

	Buffer(const int& len = BUF_SIZE);
	Buffer(const Buffer& that);
	Buffer& operator=(const Buffer& that);
	~Buffer();

	int size() const;
	char get() const;
	Buffer& put(char c);
};

Buffer::Buffer(const int& len): _size(len), gOffset(), pOffset() {
//	_size = len;
//	gOffset = 0;
//	pOffset = 0;
	
	array = new char[_size];
}

Buffer::Buffer(const Buffer& that) : _size(that._size), gOffset(that.gOffset), pOffset(that.pOffset) {
//	_size = that._size;
//	gOffset = that.gOffset;
//	pOffset = that.pOffset;
	
	array = new char[_size];
	for (int i = 0; i < _size; ++i)
		array[i] = that.array[i];
}

Buffer& Buffer::operator=(const Buffer& that) {
	if (this != &that) {
		_size = that._size;
		gOffset = that.gOffset;
		pOffset = that.pOffset;
		
		delete[] array;
	
		array = new char[_size];
		for (int i = 0; i < _size; ++i)
			array[i] = that.array[i];
	}

	return *this;
}

Buffer::~Buffer() {
	cout << "Storage clean.\n";
	delete[] array;
}

int Buffer::size() const {
	return this->_size;
}

inline char Buffer::get() const {
	return array[gOffset++];
}

Buffer& Buffer::put(char c) {
	array[pOffset++] = c;

	return *this;
}

int main() {
	Buffer buf;
	buf.put('a');
	buf.put('a');
	buf.put('a');
	buf.put('a');
	buf.put('a');

	buf.put('o').put('d');

	Buffer buf2;
	buf2.put('o');
	cout << buf2.size() << endl;
	cout << buf.get() << endl;
	cout << buf.get() << endl;
	cout << buf.get() << endl;
	cout << "-------------------------" << endl;
}
