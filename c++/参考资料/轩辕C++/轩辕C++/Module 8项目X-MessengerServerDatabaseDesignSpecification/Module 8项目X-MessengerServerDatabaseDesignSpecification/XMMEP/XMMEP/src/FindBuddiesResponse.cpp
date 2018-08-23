/*
 * FindBuddiesResponse.cpp
 *
 *  Created on: 2010-7-9 下午03:52:53
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <ostream>
#include <cstring>

#include "FindBuddiesResponse.h"
#include "MessageUtils.h"

xmessenger::FindBuddiesResponse::FindBuddiesResponse() {
}

xmessenger::FindBuddiesResponse::FindBuddiesResponse(const short& _seqNumber) :
        seqNumber(_seqNumber) {

}

int xmessenger::FindBuddiesResponse::code() const {
    return MSG_FIND_BUDDIES_RES;
}

std::ostream& xmessenger::FindBuddiesResponse::output(std::ostream& os) const {
    os << "FindBuddiesResponse: seqNumber[" << seqNumber << "], ";
    os << "users[" << users.size() << " users]";
    return os;
}

const std::vector<xmessenger::UserInfo>& xmessenger::FindBuddiesResponse::getUsers() const {
    return users;
}

std::vector<xmessenger::UserInfo>& xmessenger::FindBuddiesResponse::getUsers() {
    return users;
}

short xmessenger::FindBuddiesResponse::getSeqNumber() const {
    return seqNumber;
}

void xmessenger::FindBuddiesResponse::setSeqNumber(const short& seqNumber) {
    this->seqNumber = seqNumber;
}

size_t xmessenger::FindBuddiesResponse::encodeBody(char* outputBuffer) const {
    char* cur = encodeShortField(outputBuffer, seqNumber);
    *cur = FIELDS_DELIM;

    size_t count = users.size();
    cur = encodeUIntField(++cur, count);
    if (count > 0) {
        *cur = FIELDS_DELIM;

        for (size_t i = 0; i < count; ++i) {
            cur = encodeUserInfoField(++cur, users[i]);
            *cur = LIST_ELEMENTS_DELIM;
        }
    }
    *cur = '\0'; // rewrite last LIST_ELEMENTS_DELIM to '\0'
    return std::strlen(outputBuffer);
}

const char* xmessenger::FindBuddiesResponse::decodeBody(
        const char* inputBuffer) {
    const char* cur = decodeShortField(inputBuffer, seqNumber);

    size_t count = 0;
    cur = decodeUIntField(cur, count);

    for (size_t i = 0; i < count; ++i) {
        xmessenger::UserInfo b;
        cur = decodeUserInfoField(cur, b);
        users.push_back(b);
    }

    return cur;
}

