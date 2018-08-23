/*
 * GetLoginInfoRequest.cpp
 *
 *  Created on: 2010-3-31
 *      Author: kwarph
 */

#include <ostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

#include "GetLoginInfoRequest.h"
#include "MessageUtils.h"

xmessenger::GetLoginInfoRequest::GetLoginInfoRequest() {
}

xmessenger::GetLoginInfoRequest::GetLoginInfoRequest(
        const std::string& _userName) :
        userName(_userName) {
}

int xmessenger::GetLoginInfoRequest::code() const {
    return MSG_GET_LOGIN_INFO_REQ;
}

std::ostream& xmessenger::GetLoginInfoRequest::output(std::ostream& os) const {
    os << "GetLoginInfoRequest: userName[" << userName << "]";

    return os;
}

std::string xmessenger::GetLoginInfoRequest::getUserName() const {
    return userName;
}

void xmessenger::GetLoginInfoRequest::setUserName(const std::string& userName) {
    this->userName = userName;
}

size_t xmessenger::GetLoginInfoRequest::encodeBody(char* outputBuffer) const {
    char* cur = encodeStringField(outputBuffer, userName);
    *cur = '\0';
    return std::strlen(outputBuffer);
}

const char* xmessenger::GetLoginInfoRequest::decodeBody(const char* inputBuffer) {
    return decodeStringField(inputBuffer, userName);
}
