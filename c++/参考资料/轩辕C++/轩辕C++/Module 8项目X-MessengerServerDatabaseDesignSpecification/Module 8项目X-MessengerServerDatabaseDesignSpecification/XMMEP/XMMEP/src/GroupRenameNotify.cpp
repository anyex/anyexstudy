/*
 * GroupRenameNotify.cpp
 *
 *  Created on: 2010-7-9 下午01:30:39
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <ostream>
#include <cstring>

#include "GroupRenameNotify.h"
#include "MessageUtils.h"

xmessenger::GroupRenameNotify::GroupRenameNotify() {

}

xmessenger::GroupRenameNotify::GroupRenameNotify(const std::string& _userName,
        const std::string& _groupName, const std::string& _newName) :
        userName(_userName), groupName(_groupName), newName(_newName) {
}

int xmessenger::GroupRenameNotify::code() const {
    return MSG_GROUP_RENAME_NOTIFY;
}

std::ostream& xmessenger::GroupRenameNotify::output(std::ostream& os) const {
    os << "GroupRenameNotify: userName[" << userName;
    os << "], groupName[" << groupName;
    os << "], newName[" << newName << "]";

    return os;
}

std::string xmessenger::GroupRenameNotify::getGroupName() const {
    return groupName;
}

std::string xmessenger::GroupRenameNotify::getUserName() const {
    return userName;
}

std::string xmessenger::GroupRenameNotify::getNewName() const {
    return newName;
}

void xmessenger::GroupRenameNotify::setGroupName(const std::string& group) {
    this->groupName = group;
}

void xmessenger::GroupRenameNotify::setUserName(const std::string& userName) {
    this->userName = userName;
}

void xmessenger::GroupRenameNotify::setNewName(const std::string& newName) {
    this->newName = newName;
}

size_t xmessenger::GroupRenameNotify::encodeBody(char* outputBuffer) const {
    char* cur = encodeStringField(outputBuffer, userName);
    *cur = FIELDS_DELIM;
    cur = encodeStringField(++cur, groupName);
    *cur = FIELDS_DELIM;
    cur = encodeStringField(++cur, newName);
    *cur = '\0';

    return std::strlen(outputBuffer);
}

const char* xmessenger::GroupRenameNotify::decodeBody(const char* inputBuffer) {
    const char* cur = decodeStringField(inputBuffer, userName);
    cur = decodeStringField(cur, groupName);
    cur = decodeStringField(cur, newName);

    return cur;
}
