/*
 * GroupAddedNotify.cpp
 *
 *  Created on: 2010-7-9 下午01:29:11
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <ostream>
#include <cstring>

#include "GroupAddedNotify.h"
#include "MessageUtils.h"

xmessenger::GroupAddedNotify::GroupAddedNotify() {

}

xmessenger::GroupAddedNotify::GroupAddedNotify(const std::string& _userName,
        const std::string& _groupName) :
        userName(_userName), groupName(_groupName) {
}

int xmessenger::GroupAddedNotify::code() const {
    return MSG_GROUP_ADDED_NOTIFY;
}

std::ostream& xmessenger::GroupAddedNotify::output(std::ostream& os) const {
    os << "GroupAddedNotify: userName[" << userName;
    os << "], groupName[" << groupName << "]";

    return os;
}

std::string xmessenger::GroupAddedNotify::getGroupName() const {
    return groupName;
}

std::string xmessenger::GroupAddedNotify::getUserName() const {
    return userName;
}

void xmessenger::GroupAddedNotify::setGroupName(const std::string& group) {
    this->groupName = group;
}

void xmessenger::GroupAddedNotify::setUserName(const std::string& userName) {
    this->userName = userName;
}

size_t xmessenger::GroupAddedNotify::encodeBody(char* outputBuffer) const {
    char* cur = encodeStringField(outputBuffer, userName);
    *cur = FIELDS_DELIM;
    cur = encodeStringField(++cur, groupName);
    *cur = '\0';

    return std::strlen(outputBuffer);
}

const char* xmessenger::GroupAddedNotify::decodeBody(const char* inputBuffer) {
    const char* cur = decodeStringField(inputBuffer, userName);
    cur = decodeStringField(cur, groupName);

    return cur;
}

