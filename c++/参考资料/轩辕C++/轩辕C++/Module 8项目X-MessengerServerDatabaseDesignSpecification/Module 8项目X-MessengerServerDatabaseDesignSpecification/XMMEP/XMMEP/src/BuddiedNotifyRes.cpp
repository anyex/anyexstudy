/*
 * BuddiedNotifyRes.cpp
 *
 *  Created on: 2010-7-21 下午05:45:51
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <ostream>
#include <cstring>

#include "BuddiedNotifyRes.h"
#include "MessageUtils.h"

xmessenger::BuddiedNotifyRes::BuddiedNotifyRes() {

}

xmessenger::BuddiedNotifyRes::BuddiedNotifyRes(const std::string& _userName,
        const OnlineBuddy& _buddy, bool _add) :
        userName(_userName), buddy(_buddy), add(_add) {
}

int xmessenger::BuddiedNotifyRes::code() const {
    return MSG_BUDDIED_NOTIFY_RES;
}

std::ostream& xmessenger::BuddiedNotifyRes::output(std::ostream& os) const {
    os << "BuddiedNotifyRes: userName[" << userName;
    os << "], buddy[" << buddy.buddyName << "]";

    return os;
}

std::string xmessenger::BuddiedNotifyRes::getUserName() const {
    return userName;
}

xmessenger::OnlineBuddy xmessenger::BuddiedNotifyRes::getBuddy() const {
    return buddy;
}

bool xmessenger::BuddiedNotifyRes::isAdd() const {
    return add;
}

void xmessenger::BuddiedNotifyRes::setUserName(const std::string& userName) {
    this->userName = userName;
}

void xmessenger::BuddiedNotifyRes::setBuddy(const OnlineBuddy& buddy) {
    this->buddy = buddy;
}

void xmessenger::BuddiedNotifyRes::setAdd(bool add) {
    this->add = add;
}

size_t xmessenger::BuddiedNotifyRes::encodeBody(char* outputBuffer) const {
    char* cur = encodeStringField(outputBuffer, userName);
    *cur = FIELDS_DELIM;
    cur = encodeOnlineBuddyField(++cur, buddy);
    *cur = FIELDS_DELIM;
    cur = encodeBooleanField(++cur, add);
    *cur = '\0';

    return std::strlen(outputBuffer);
}

const char* xmessenger::BuddiedNotifyRes::decodeBody(const char* inputBuffer) {
    const char* cur = decodeStringField(inputBuffer, userName);
    cur = decodeOnlineBuddyField(cur, buddy);
    cur = decodeBooleanField(cur, add);
    return cur;
}
