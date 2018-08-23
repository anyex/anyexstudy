/*
 * BuddyBlockedNotify.cpp
 *
 *  Created on: 2010-7-9 下午01:34:30
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <ostream>
#include <cstring>

#include "BuddyBlockedNotify.h"
#include "MessageUtils.h"

xmessenger::BuddyBlockedNotify::BuddyBlockedNotify() {

}

xmessenger::BuddyBlockedNotify::BuddyBlockedNotify(
        const std::string& _userName, const std::string& _buddyName) :
        userName(_userName), buddyName(_buddyName) {
}

int xmessenger::BuddyBlockedNotify::code() const {
    return MSG_BUDDY_BLOCKED_NOTIFY;
}

std::ostream& xmessenger::BuddyBlockedNotify::output(
        std::ostream& os) const {
    os << "AddedToBlacklistNotify: userName[" << userName;
    os << "], buddyName[" << buddyName << "]";

    return os;
}

std::string xmessenger::BuddyBlockedNotify::getBuddyName() const {
    return buddyName;
}

std::string xmessenger::BuddyBlockedNotify::getUserName() const {
    return userName;
}

void xmessenger::BuddyBlockedNotify::setBuddyName(
        const std::string& buddyName) {
    this->buddyName = buddyName;
}

void xmessenger::BuddyBlockedNotify::setUserName(
        const std::string& userName) {
    this->userName = userName;
}

size_t xmessenger::BuddyBlockedNotify::encodeBody(
        char* outputBuffer) const {
    char* cur = encodeStringField(outputBuffer, userName);
    *cur = FIELDS_DELIM;
    cur = encodeStringField(++cur, buddyName);
    *cur = '\0';

    return std::strlen(outputBuffer);
}

const char* xmessenger::BuddyBlockedNotify::decodeBody(
        const char* inputBuffer) {
    const char* cur = decodeStringField(inputBuffer, userName);
    cur = decodeStringField(cur, buddyName);

    return cur;
}

