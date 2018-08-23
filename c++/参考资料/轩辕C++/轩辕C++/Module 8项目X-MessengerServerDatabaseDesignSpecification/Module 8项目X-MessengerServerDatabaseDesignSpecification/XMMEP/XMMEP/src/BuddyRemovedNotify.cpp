/*
 * BuddyRemovedNotify.cpp
 *
 *  Created on: 2010-7-9 下午01:31:39
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <ostream>
#include <cstring>

#include "BuddyRemovedNotify.h"
#include "MessageUtils.h"

xmessenger::BuddyRemovedNotify::BuddyRemovedNotify() {

}

xmessenger::BuddyRemovedNotify::BuddyRemovedNotify(const std::string& _userName,
        const std::string& _group, const std::string& _buddyName,
        bool _roomMember) :
        userName(_userName), group(_group), buddyName(_buddyName), roomMember(
                _roomMember) {

}

int xmessenger::BuddyRemovedNotify::code() const {
    return MSG_BUDDY_REMOVED_NOTIFY;
}

std::ostream& xmessenger::BuddyRemovedNotify::output(std::ostream& os) const {
    os << "BuddyRemovedNotify: userName[" << userName;
    os << "], buddyName[" << buddyName << "], group[" << group << "]";

    return os;
}

std::string xmessenger::BuddyRemovedNotify::getGroup() const {
    return group;
}

std::string xmessenger::BuddyRemovedNotify::getBuddyName() const {
    return buddyName;
}

std::string xmessenger::BuddyRemovedNotify::getUserName() const {
    return userName;
}

bool xmessenger::BuddyRemovedNotify::isRoomMember() const {
    return roomMember;
}

void xmessenger::BuddyRemovedNotify::setGroup(const std::string& group) {
    this->group = group;
}

void xmessenger::BuddyRemovedNotify::setBuddyName(
        const std::string& buddyName) {
    this->buddyName = buddyName;
}

void xmessenger::BuddyRemovedNotify::setUserName(const std::string& userName) {
    this->userName = userName;
}

void xmessenger::BuddyRemovedNotify::setIsRoomMember(bool roomMember) {
    this->roomMember = roomMember;
}

size_t xmessenger::BuddyRemovedNotify::encodeBody(char* outputBuffer) const {
    char* cur = encodeStringField(outputBuffer, userName);
    *cur = FIELDS_DELIM;
    cur = encodeStringField(++cur, buddyName);
    *cur = FIELDS_DELIM;
    cur = encodeStringField(++cur, group);
    *cur = FIELDS_DELIM;
    cur = encodeBooleanField(++cur, roomMember);
    *cur = '\0';

    return std::strlen(outputBuffer);
}

const char* xmessenger::BuddyRemovedNotify::decodeBody(
        const char* inputBuffer) {
    const char* cur = decodeStringField(inputBuffer, userName);
    cur = decodeStringField(cur, buddyName);
    cur = decodeStringField(cur, group);
    cur = decodeBooleanField(cur, roomMember);

    return cur;
}
