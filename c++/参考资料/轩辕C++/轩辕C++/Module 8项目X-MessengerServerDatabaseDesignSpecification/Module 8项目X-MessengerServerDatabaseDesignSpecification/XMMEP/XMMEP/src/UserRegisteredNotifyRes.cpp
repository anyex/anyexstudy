/*
 * UserRegisteredNotifyRes.cpp
 *
 *  Created on: Sep 15, 2011
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 */

#include <ostream>
#include <cstring>

#include "UserRegisteredNotifyRes.h"
#include "MessageUtils.h"

xmessenger::UserRegisteredNotifyRes::UserRegisteredNotifyRes() {

}

xmessenger::UserRegisteredNotifyRes::UserRegisteredNotifyRes(
        const std::string& _userName) :
        userName(_userName) {
}

int xmessenger::UserRegisteredNotifyRes::code() const {
    return MSG_USER_REGISTERED_NOTIFY_RES;
}

std::ostream& xmessenger::UserRegisteredNotifyRes::output(
        std::ostream& os) const {
    os << "UserRegisteredNotifyRes: userName[" << userName << "]";

    return os;
}

std::string xmessenger::UserRegisteredNotifyRes::getUserName() const {
    return userName;
}

void xmessenger::UserRegisteredNotifyRes::setUserName(
        const std::string& userName) {
    this->userName = userName;
}

size_t xmessenger::UserRegisteredNotifyRes::encodeBody(
        char* outputBuffer) const {
    char* cur = encodeStringField(outputBuffer, userName);
    *cur = '\0';

    return std::strlen(outputBuffer);
}

const char* xmessenger::UserRegisteredNotifyRes::decodeBody(
        const char* inputBuffer) {
    return decodeStringField(inputBuffer, userName);
}
