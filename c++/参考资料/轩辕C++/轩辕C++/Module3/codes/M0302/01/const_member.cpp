#include <iostream>
using namespace std;

typedef char byte;
typedef unsigned short uShort;
typedef unsigned int uInt;

class Message {  
private: 
	static uShort msgVersion;
    uShort length;
    uInt sequenceNum;
    std::string content;

public: 
    Message(const uInt& seqNum, const std::string& contnt);

	static uShort getVersion();
	
	uShort getLength() const;
	
    void marshal(byte* result);
    void demarshal(const byte* result);
};

uShort Message::msgVersion = 3;

uShort Message::getVersion() {
	return msgVersion;
}

uShort Message::getLength() const {
	return length;
}

Message::Message(const uInt& seqNum, const std::string& contnt) {
	sequenceNum = seqNum;
    content = contnt;
    length = 3 + 5 + 3 + content.length() ;
    if (msgVersion > 3) {
        length += 1;
    }
}

void Message::marshal(byte* result) {

}

void Message::demarshal(const byte* result) {

}

int main() {
	Message m1(1200, "hello, Knuth!");
	cout << m1.getLength() << endl;

	const Message m2(m1);
	cout << m2.getLength() << endl;
	byte ba[m2.getLength()];
	m2.marshal(ba);
	cout << Message::getVersion() << endl;
}
