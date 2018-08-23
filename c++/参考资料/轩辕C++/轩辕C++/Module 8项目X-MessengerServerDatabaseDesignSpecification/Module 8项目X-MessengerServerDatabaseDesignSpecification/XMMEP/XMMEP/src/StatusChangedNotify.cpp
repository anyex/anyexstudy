/*
 * StatusChangedNotify.cpp
 *
 *  Created on: 2010-7-6 下午04:22:36
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <ostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

#include "StatusChangedNotify.h"
#include "MessageUtils.h"

xmessenger::StatusChangedNotify::StatusChangedNotify() :
        status(xmessenger::ONLINE) {
}

xmessenger::StatusChangedNotify::StatusChangedNotify(
        const std::string& _userName, const Presence& _status) :
        userName(_userName), status(_status) {
}

int xmessenger::StatusChangedNotify::code() const {
    return MSG_STATUS_CHANGED_NOTIFY;
}

std::ostream& xmessenger::StatusChangedNotify::output(std::ostream& os) const {
    os << "StatusChangedNotify: userName[" << userName;
    os << "], status[" << status << "]";

    return os;
}

xmessenger::Presence xmessenger::StatusChangedNotify::getStatus() const {
    return status;
}

std::string xmessenger::StatusChangedNotify::getUserName() const {
    return userName;
}

void xmessenger::StatusChangedNotify::setStatus(const Presence& status) {
    this->status = status;
}

void xmessenger::StatusChangedNotify::setUserName(const std::string& userName) {
    this->userName = userName;
}

size_t xmessenger::StatusChangedNotify::encodeBody(char* outputBuffer) const {
    char* cur = encodeStringField(outputBuffer, userName);
    *cur = FIELDS_DELIM;
    std::sprintf(++cur, "%1d", status);

    return std::strlen(outputBuffer);
}

const char* xmessenger::StatusChangedNotify::decodeBody(
        const char* inputBuffer) {
    const char* cur = decodeStringField(inputBuffer, userName);
    int p;
    cur = decodeIntField(cur, p);
    status = Presence(p);

    return cur;
}
