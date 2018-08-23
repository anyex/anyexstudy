/*
 * RegisterActivateRequest.cpp
 *
 *  Created on: 2010-3-31
 *      Author: kwarph
 */

#include <ostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

#include "RegisterActivateRequest.h"
#include "MessageUtils.h"

xmessenger::RegisterActivateRequest::RegisterActivateRequest() {

}

xmessenger::RegisterActivateRequest::RegisterActivateRequest(
        const std::string& _userName, const std::string& _activateCode) :
        userName(_userName), activateCode(_activateCode) {
}

int xmessenger::RegisterActivateRequest::code() const {
    return MSG_REGISTER_ACTIVATE_REQ;
}

std::ostream& xmessenger::RegisterActivateRequest::output(
        std::ostream& os) const {
    os << "RegisterActivateRequest: userName[" << userName;
    os << "], activateCode[" << activateCode << "]";

    return os;
}

std::string xmessenger::RegisterActivateRequest::getUserName() const {
    return userName;
}

std::string xmessenger::RegisterActivateRequest::getActivateCode() const {
    return activateCode;
}

void xmessenger::RegisterActivateRequest::setUserName(
        const std::string& userName) {
    this->userName = userName;
}

void xmessenger::RegisterActivateRequest::setActivateCode(
        const std::string& activateCode) {
    this->activateCode = activateCode;
}

size_t xmessenger::RegisterActivateRequest::encodeBody(
        char* outputBuffer) const {
    char* cur = encodeStringField(outputBuffer, userName);
    *cur = FIELDS_DELIM;
    cur = encodeStringField(++cur, activateCode);
    *cur = '\0';
    return std::strlen(outputBuffer);
}

const char* xmessenger::RegisterActivateRequest::decodeBody(const char* inputBuffer) {
    const char* cur = decodeStringField(inputBuffer, userName);
    cur = decodeStringField(cur, activateCode);

    return cur;
}
