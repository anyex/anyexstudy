/*
 * KeepAlive.cpp
 *
 *  Created on: 2010-7-9 下午01:37:13
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <ostream>
#include <cstring>

#include "KeepAlive.h"
#include "MessageUtils.h"

xmessenger::KeepAlive::KeepAlive() {

}

xmessenger::KeepAlive::KeepAlive(const std::string& _userName) :
        userName(_userName) {
}

int xmessenger::KeepAlive::code() const {
    return MSG_KEEP_ALIVE;
}

std::ostream& xmessenger::KeepAlive::output(std::ostream& os) const {
    os << "KeepAlive: userName[" << userName << "]";

    return os;
}

std::string xmessenger::KeepAlive::getUserName() const {
    return userName;
}

void xmessenger::KeepAlive::setUserName(const std::string& userName) {
    this->userName = userName;
}

size_t xmessenger::KeepAlive::encodeBody(char* outputBuffer) const {
    char* cur = encodeStringField(outputBuffer, userName);
    *cur = '\0';

    return std::strlen(outputBuffer);
}

const char* xmessenger::KeepAlive::decodeBody(const char* inputBuffer) {
    return decodeStringField(inputBuffer, userName);
}
