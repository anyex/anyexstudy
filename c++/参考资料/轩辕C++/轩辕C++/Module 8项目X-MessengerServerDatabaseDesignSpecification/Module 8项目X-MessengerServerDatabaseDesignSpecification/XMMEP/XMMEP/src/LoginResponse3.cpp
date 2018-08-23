/*
 * LoginResponse3.cpp
 *
 *  Created on: 2010-6-4
 *      Author: teacher
 */

#include <ostream>
#include <cstring>

#include "LoginResponse3.h"
#include "MessageUtils.h"

xmessenger::LoginResponse3::LoginResponse3() :
        seqNumber() {

}

xmessenger::LoginResponse3::LoginResponse3(const short& _seqNumber) :
        seqNumber(_seqNumber) {

}

int xmessenger::LoginResponse3::code() const {
    return MSG_LOGIN_RES3;
}

std::ostream& xmessenger::LoginResponse3::output(std::ostream& os) const {
    os << "LoginResponse3: seqNumber[" << seqNumber << "], ";
    os << buddies.size() << " buddies";
    return os;
}

short xmessenger::LoginResponse3::getSeqNumber() const {
    return seqNumber;
}

void xmessenger::LoginResponse3::setSeqNumber(const short& seqNumber) {
    this->seqNumber = seqNumber;
}

const std::vector<xmessenger::Buddy>&
xmessenger::LoginResponse3::getBuddies() const {
    return buddies;
}

std::vector<xmessenger::Buddy>&
xmessenger::LoginResponse3::getBuddies() {
    return buddies;
}

size_t xmessenger::LoginResponse3::encodeBody(char* outputBuffer) const {
    char* cur = encodeShortField(outputBuffer, seqNumber);
    *cur = FIELDS_DELIM;

    const size_t count = buddies.size();
    cur = encodeIntField(++cur, count);
    *cur = FIELDS_DELIM;

    for (size_t i = 0; i < count; ++i) {
        cur = encodeBuddyField(++cur, buddies[i]);
        *cur = LIST_ELEMENTS_DELIM;
    }

    *cur = '\0'; // rewrite last LIST_ELEMENTS_DELIM to '\0'
    return std::strlen(outputBuffer);
}

const char* xmessenger::LoginResponse3::decodeBody(const char* inputBuffer) {
    const char* cur = decodeShortField(inputBuffer, seqNumber);

    int count = 0;
    cur = decodeIntField(cur, count);
    for (int i = 0; i < count; ++i) {
        Buddy b;
        cur = decodeBuddyField(cur, b);
        buddies.push_back(b);
    }

    return cur;
}
