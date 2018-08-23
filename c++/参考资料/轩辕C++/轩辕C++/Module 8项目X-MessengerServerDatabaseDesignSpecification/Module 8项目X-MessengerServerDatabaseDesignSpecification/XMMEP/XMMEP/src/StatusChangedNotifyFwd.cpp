/*
 * StatusChangedNotifyFwd.cpp
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

#include "StatusChangedNotifyFwd.h"
#include "MessageUtils.h"

xmessenger::StatusChangedNotifyFwd::StatusChangedNotifyFwd() :
        status(xmessenger::ONLINE) {
}

xmessenger::StatusChangedNotifyFwd::StatusChangedNotifyFwd(
        const std::string& _observer, const std::string& _userName,
        const Presence& _status) :
        observer(_observer), userName(_userName), status(_status) {
}

int xmessenger::StatusChangedNotifyFwd::code() const {
    return MSG_STATUS_CHANGED_NOTIFY_FWD;
}

std::ostream& xmessenger::StatusChangedNotifyFwd::output(
        std::ostream& os) const {
    os << "StatusChangedNotifyFwd: observer[" << observer;
    os << "], userName[" << userName;
    os << "], status[" << status << "]";

    return os;
}

xmessenger::Presence xmessenger::StatusChangedNotifyFwd::getStatus() const {
    return status;
}

std::string xmessenger::StatusChangedNotifyFwd::getObserver() const {
    return observer;
}

std::string xmessenger::StatusChangedNotifyFwd::getUserName() const {
    return userName;
}

void xmessenger::StatusChangedNotifyFwd::setStatus(const Presence& status) {
    this->status = status;
}

void xmessenger::StatusChangedNotifyFwd::setUserName(
        const std::string& userName) {
    this->userName = userName;
}

void xmessenger::StatusChangedNotifyFwd::setObserver(
        const std::string& observer) {
    this->observer = observer;
}

size_t xmessenger::StatusChangedNotifyFwd::encodeBody(
        char* outputBuffer) const {
    char* cur = encodeStringField(outputBuffer, observer);
    *cur = FIELDS_DELIM;
    cur = encodeStringField(++cur, userName);
    *cur = FIELDS_DELIM;
    std::sprintf(++cur, "%1d", status);

    return std::strlen(outputBuffer);
}

const char* xmessenger::StatusChangedNotifyFwd::decodeBody(
        const char* inputBuffer) {
    const char* cur = decodeStringField(inputBuffer, observer);
    cur = decodeStringField(cur, userName);
    int p;
    cur = decodeIntField(cur, p);
    status = Presence(p);

    return cur;
}
