/*
 * UserLoginNotifyResRes.cpp
 *
 *  Created on: Oct 1, 2011
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 */

#include <ostream>
#include <cstring>

#include "LoginResponse6.h"
#include "MessageUtils.h"

xmessenger::LoginResponse6::LoginResponse6() {

}

xmessenger::LoginResponse6::LoginResponse6(const short& _seqNumber) :
        seqNumber(_seqNumber) {

}

int xmessenger::LoginResponse6::code() const {
    return MSG_LOGIN_RES6;
}

std::ostream& xmessenger::LoginResponse6::output(std::ostream& os) const {
    os << "LoginResponse6: seqNumber[" << seqNumber << "], ";
    os << "buddies[" << buddies.size() << " buddies]";
    return os;
}

const std::vector<xmessenger::OnlineBuddy>&
xmessenger::LoginResponse6::getUsers() const {
    return buddies;
}

std::vector<xmessenger::OnlineBuddy>&
xmessenger::LoginResponse6::getUsers() {
    return buddies;
}

short xmessenger::LoginResponse6::getSeqNumber() const {
    return seqNumber;
}

void xmessenger::LoginResponse6::setSeqNumber(const short& seqNumber) {
    this->seqNumber = seqNumber;
}

size_t xmessenger::LoginResponse6::encodeBody(char* outputBuffer) const {
    char* cur = encodeShortField(outputBuffer, seqNumber);
    *cur = FIELDS_DELIM;

    size_t count = buddies.size();
    cur = encodeUIntField(++cur, count);
    if (count > 0) {
        *cur = FIELDS_DELIM;

        for (size_t i = 0; i < count; ++i) {
            cur = encodeOnlineBuddyField(++cur, buddies[i]);
            *cur = LIST_ELEMENTS_DELIM;
        }
    }
    *cur = '\0'; // rewrite last LIST_ELEMENTS_DELIM to '\0'
    return std::strlen(outputBuffer);
}

const char* xmessenger::LoginResponse6::decodeBody(
        const char* inputBuffer) {
    const char* cur = decodeShortField(inputBuffer, seqNumber);

    size_t count = 0;
    cur = decodeUIntField(cur, count);

    for (size_t i = 0; i < count; ++i) {
        xmessenger::OnlineBuddy b;
        cur = decodeOnlineBuddyField(cur, b);
        buddies.push_back(b);
    }

    return cur;
}

