/*
 * ClientReady.cpp
 *
 *  Created on: 2010-7-19 下午12:28:58
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include "ClientReady.h"
#include <ostream>
#include <cstring>

#include "MessageUtils.h"

xmessenger::ClientReady::ClientReady() {

}

xmessenger::ClientReady::ClientReady(const std::string& _userName) :
        userName(_userName) {
}

int xmessenger::ClientReady::code() const {
    return MSG_CLIENT_READY;
}

std::ostream& xmessenger::ClientReady::output(std::ostream& os) const {
    os << "ClientReady: userName[" << userName << "]";

    return os;
}

std::string xmessenger::ClientReady::getUserName() const {
    return userName;
}

void xmessenger::ClientReady::setUserName(const std::string& userName) {
    this->userName = userName;
}

size_t xmessenger::ClientReady::encodeBody(char* outputBuffer) const {
    char* cur = encodeStringField(outputBuffer, userName);
    *cur = '\0';

    return std::strlen(outputBuffer);
}

const char* xmessenger::ClientReady::decodeBody(const char* inputBuffer) {
    const char* cur = decodeStringField(inputBuffer, userName);
    return cur;
}
