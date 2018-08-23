/*
 * BuddyModifiedNotify.cpp
 *
 *  Created on: 2010-7-9 下午01:32:50
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <ostream>
#include <cstring>

#include "BuddyModifiedNotify.h"
#include "MessageUtils.h"

xmessenger::BuddyModifiedNotify::BuddyModifiedNotify() {

}

xmessenger::BuddyModifiedNotify::BuddyModifiedNotify(
        const std::string& _userName, const std::string& _buddyName,
        const std::string& _displayName, const std::string& _groupName,
        const std::string& _newGroup) :
        userName(_userName), buddyName(_buddyName), displayName(_displayName), groupName(
                _groupName), newGroup(_newGroup) {
}

int xmessenger::BuddyModifiedNotify::code() const {
    return MSG_BUDDY_MODIFIED_NOTIFY;
}

std::ostream& xmessenger::BuddyModifiedNotify::output(std::ostream& os) const {
    os << "BuddyMovedToNotify: userName[" << userName;
    os << "], buddyName[" << buddyName;
    os << "], buddyName[" << displayName;
    os << "], groupName[" << groupName;
    os << "], newGroup[" << newGroup << "]";

    return os;
}

std::string xmessenger::BuddyModifiedNotify::getGroupName() const {
    return groupName;
}

std::string xmessenger::BuddyModifiedNotify::getUserName() const {
    return userName;
}

std::string xmessenger::BuddyModifiedNotify::getNewGroup() const {
    return newGroup;
}

std::string xmessenger::BuddyModifiedNotify::getBuddyName() const {
    return buddyName;
}

std::string xmessenger::BuddyModifiedNotify::getDisplayName() const {
    return displayName;
}

void xmessenger::BuddyModifiedNotify::setGroupName(const std::string& group) {
    this->groupName = group;
}

void xmessenger::BuddyModifiedNotify::setUserName(const std::string& userName) {
    this->userName = userName;
}

void xmessenger::BuddyModifiedNotify::setNewGroup(const std::string& newGroup) {
    this->newGroup = newGroup;
}

void xmessenger::BuddyModifiedNotify::setBuddyName(
        const std::string& buddyName) {
    this->buddyName = buddyName;
}

void xmessenger::BuddyModifiedNotify::setDisplayName(
        const std::string& displayName) {
    this->displayName = displayName;
}

size_t xmessenger::BuddyModifiedNotify::encodeBody(char* outputBuffer) const {
    char* cur = encodeStringField(outputBuffer, userName);
    *cur = FIELDS_DELIM;
    cur = encodeStringField(++cur, buddyName);
    *cur = FIELDS_DELIM;
    cur = encodeStringField(++cur, displayName);
    *cur = FIELDS_DELIM;
    cur = encodeStringField(++cur, groupName);
    *cur = FIELDS_DELIM;
    cur = encodeStringField(++cur, newGroup);
    *cur = '\0';

    return std::strlen(outputBuffer);
}

const char* xmessenger::BuddyModifiedNotify::decodeBody(
        const char* inputBuffer) {
    const char* cur = decodeStringField(inputBuffer, userName);
    cur = decodeStringField(cur, buddyName);
    cur = decodeStringField(cur, displayName);
    cur = decodeStringField(cur, groupName);
    cur = decodeStringField(cur, newGroup);

    return cur;
}

