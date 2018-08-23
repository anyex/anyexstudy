/*
 * BuddyLoginNotify.cpp
 *
 *  Created on: 2010-7-20 下午03:48:48
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <ostream>
#include <cstring>

#include "BuddyLoginNotify.h"
#include "MessageUtils.h"

xmessenger::BuddyLoginNotify::BuddyLoginNotify() {

}

xmessenger::BuddyLoginNotify::BuddyLoginNotify(const std::string& _receiver,
        const OnlineBuddy& _buddy) :
        receiver(_receiver), buddy(_buddy) {

}

int xmessenger::BuddyLoginNotify::code() const {
    return MSG_BUDDY_LOGIN_NOTIFY;
}

std::ostream& xmessenger::BuddyLoginNotify::output(std::ostream& os) const {
    os << "UserLoginNotify: observer[" << receiver;
    os << "], userName[" << buddy.buddyName;
    os << "]";
    return os;
}

std::string xmessenger::BuddyLoginNotify::getReceiver() const {
    return receiver;
}

const xmessenger::OnlineBuddy& xmessenger::BuddyLoginNotify::getBuddy() const {
    return buddy;
}

void xmessenger::BuddyLoginNotify::setBuddy(
        const xmessenger::OnlineBuddy& user) {
    this->buddy = user;
}

void xmessenger::BuddyLoginNotify::setReceiver(const std::string& receiver) {
    this->receiver = receiver;
}

size_t xmessenger::BuddyLoginNotify::encodeBody(char* outputBuffer) const {
    char* cur = encodeStringField(outputBuffer, receiver);
    *cur = FIELDS_DELIM;
    cur = encodeOnlineBuddyField(++cur, buddy);
    *cur = '\0';

    return std::strlen(outputBuffer);
}

const char* xmessenger::BuddyLoginNotify::decodeBody(const char* inputBuffer) {
    const char* cur = decodeStringField(inputBuffer, receiver);
    cur = decodeOnlineBuddyField(cur, buddy);

    return cur;
}

