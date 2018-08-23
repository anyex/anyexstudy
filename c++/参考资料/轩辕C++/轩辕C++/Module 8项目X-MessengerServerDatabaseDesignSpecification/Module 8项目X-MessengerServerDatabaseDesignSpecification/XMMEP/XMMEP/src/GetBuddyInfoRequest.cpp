/*
 * GetBuddyInfoRequest.cpp
 *
 *  Created on: 2010-7-9 下午01:36:22
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <ostream>
#include <cstring>

#include "GetBuddyInfoRequest.h"
#include "MessageUtils.h"

xmessenger::GetBuddyInfoRequest::GetBuddyInfoRequest() {

}

xmessenger::GetBuddyInfoRequest::GetBuddyInfoRequest(
        const std::string& _userName, const std::string& _buddyName) :
        userName(_userName), buddyName(_buddyName) {
}

int xmessenger::GetBuddyInfoRequest::code() const {
    return MSG_GET_BUDDY_INFO_REQ;
}

std::ostream& xmessenger::GetBuddyInfoRequest::output(std::ostream& os) const {
    os << "GetBuddyInfoRequest: userName[" << userName;
    os << "], buddyName[" << buddyName << "]";

    return os;
}

std::string xmessenger::GetBuddyInfoRequest::getBuddyName() const {
    return buddyName;
}

std::string xmessenger::GetBuddyInfoRequest::getUserName() const {
    return userName;
}

void xmessenger::GetBuddyInfoRequest::setBuddyName(
        const std::string& buddyName) {
    this->buddyName = buddyName;
}

void xmessenger::GetBuddyInfoRequest::setUserName(const std::string& userName) {
    this->userName = userName;
}

size_t xmessenger::GetBuddyInfoRequest::encodeBody(char* outputBuffer) const {
    char* cur = encodeStringField(outputBuffer, userName);
    *cur = FIELDS_DELIM;
    cur = encodeStringField(++cur, buddyName);
    *cur = '\0';

    return std::strlen(outputBuffer);
}

const char* xmessenger::GetBuddyInfoRequest::decodeBody(const char* inputBuffer) {
    const char* cur = decodeStringField(inputBuffer, userName);
    cur = decodeStringField(cur, buddyName);

    return cur;
}

