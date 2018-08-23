/*
 * GroupRemovedNotify.cpp
 *
 *  Created on: 2010-7-9 下午01:30:00
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <ostream>
#include <cstring>

#include "GroupRemovedNotify.h"
#include "MessageUtils.h"

xmessenger::GroupRemovedNotify::GroupRemovedNotify() {

}

xmessenger::GroupRemovedNotify::GroupRemovedNotify(const std::string& _userName,
        const std::string& _groupName) :
        userName(_userName), groupName(_groupName) {
}

int xmessenger::GroupRemovedNotify::code() const {
    return MSG_GROUP_REMOVED_NOTIFY;
}

std::ostream& xmessenger::GroupRemovedNotify::output(std::ostream& os) const {
    os << "GroupRemovedNotify: userName[" << userName;
    os << "], groupName[" << groupName << "]";

    return os;
}

std::string xmessenger::GroupRemovedNotify::getGroupName() const {
    return groupName;
}

std::string xmessenger::GroupRemovedNotify::getUserName() const {
    return userName;
}

void xmessenger::GroupRemovedNotify::setGroupName(const std::string& group) {
    this->groupName = group;
}

void xmessenger::GroupRemovedNotify::setUserName(const std::string& userName) {
    this->userName = userName;
}

size_t xmessenger::GroupRemovedNotify::encodeBody(char* outputBuffer) const {
    char* cur = encodeStringField(outputBuffer, userName);
    *cur = FIELDS_DELIM;
    cur = encodeStringField(++cur, groupName);
    *cur = '\0';

    return std::strlen(outputBuffer);
}

const char* xmessenger::GroupRemovedNotify::decodeBody(
        const char* inputBuffer) {
    const char* cur = decodeStringField(inputBuffer, userName);
    cur = decodeStringField(cur, groupName);

    return cur;
}
