/*
 * LoginResponseN.cpp
 *
 *  Created on: Sep 29, 2011
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 */

#include <ostream>
#include <cstring>

#include "LoginResponseN.h"
#include "MessageUtils.h"

xmessenger::LoginResponseN::LoginResponseN() :
        seqNumber() {

}

xmessenger::LoginResponseN::LoginResponseN(const short& _seqNumber) :
        seqNumber(_seqNumber) {

}

xmessenger::LoginResponseN::~LoginResponseN() {

}

std::ostream& xmessenger::LoginResponseN::partialOutput(std::ostream& os,
        const std::string& msgName, const std::string& itemName) const {
    os << msgName << ": seqNumber[" << seqNumber << "], ";
    os << items.size() << " " << itemName;
    return os;
}

short xmessenger::LoginResponseN::getSeqNumber() const {
    return seqNumber;
}

void xmessenger::LoginResponseN::setSeqNumber(const short& seqNumber) {
    this->seqNumber = seqNumber;
}

const std::vector<std::string>& xmessenger::LoginResponseN::getItems() const {
    return items;
}

std::vector<std::string>& xmessenger::LoginResponseN::getItems() {
    return items;
}

size_t xmessenger::LoginResponseN::encodeBody(char* outputBuffer) const {
    char* cur = encodeShortField(outputBuffer, seqNumber);
    *cur = FIELDS_DELIM;

    const size_t count = items.size();
    cur = encodeIntField(++cur, count);
    *cur = FIELDS_DELIM;

    for (size_t i = 0; i < count; ++i) {
        cur = encodeStringField(++cur, items[i]);
        *cur = LIST_ELEMENTS_DELIM;
    }

    *cur = '\0'; // rewrite last LIST_ELEMENTS_DELIM to '\0'
    return std::strlen(outputBuffer);
}

const char* xmessenger::LoginResponseN::decodeBody(const char* inputBuffer) {
    const char* cur = decodeShortField(inputBuffer, seqNumber);

    int count = 0;
    cur = decodeIntField(cur, count);
    for (int i = 0; i < count; ++i) {
        std::string u;
        cur = decodeStringField(cur, u);
        items.push_back(u);
    }

    return cur;
}
