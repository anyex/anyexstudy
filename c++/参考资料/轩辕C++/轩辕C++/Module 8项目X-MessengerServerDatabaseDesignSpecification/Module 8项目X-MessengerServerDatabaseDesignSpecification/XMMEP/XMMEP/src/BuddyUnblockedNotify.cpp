/*
 * BuddyUnblockedNotify.cpp
 *
 *  Created on: 2010-7-9 下午01:35:28
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <ostream>
#include <cstring>

#include "BuddyUnblockedNotify.h"
#include "MessageUtils.h"

xmessenger::BuddyUnblockedNotify::BuddyUnblockedNotify() {

}

xmessenger::BuddyUnblockedNotify::BuddyUnblockedNotify(
        const std::string& _userName, const std::string& _buddyName,
        const std::string& _group) :
        userName(_userName), buddyName(_buddyName), group(_group) {
}

int xmessenger::BuddyUnblockedNotify::code() const {
    return MSG_BUDDY_UNBLOCKED_NOTIFY;
}

std::ostream& xmessenger::BuddyUnblockedNotify::output(
        std::ostream& os) const {
    os << "RemoveFromBlacklistNotify: userName[" << userName;
    os << "], buddyName[" << buddyName;
    os << "], group[" << group << "]";

    return os;
}

std::string xmessenger::BuddyUnblockedNotify::getBuddyName() const {
    return buddyName;
}

std::string xmessenger::BuddyUnblockedNotify::getUserName() const {
    return userName;
}

std::string xmessenger::BuddyUnblockedNotify::getGroup() const {
    return group;
}

void xmessenger::BuddyUnblockedNotify::setBuddyName(
        const std::string& buddyName) {
    this->buddyName = buddyName;
}

void xmessenger::BuddyUnblockedNotify::setUserName(
        const std::string& userName) {
    this->userName = userName;
}

void xmessenger::BuddyUnblockedNotify::setGroup(const std::string& group) {
    this->group = group;
}

size_t xmessenger::BuddyUnblockedNotify::encodeBody(
        char* outputBuffer) const {
    char* cur = encodeStringField(outputBuffer, userName);
    *cur = FIELDS_DELIM;
    cur = encodeStringField(++cur, buddyName);
    *cur = FIELDS_DELIM;
    cur = encodeStringField(++cur, group);
    *cur = '\0';

    return std::strlen(outputBuffer);
}

const char* xmessenger::BuddyUnblockedNotify::decodeBody(
        const char* inputBuffer) {
    const char* cur = decodeStringField(inputBuffer, userName);
    cur = decodeStringField(cur, buddyName);
    cur = decodeStringField(cur, group);

    return cur;
}

