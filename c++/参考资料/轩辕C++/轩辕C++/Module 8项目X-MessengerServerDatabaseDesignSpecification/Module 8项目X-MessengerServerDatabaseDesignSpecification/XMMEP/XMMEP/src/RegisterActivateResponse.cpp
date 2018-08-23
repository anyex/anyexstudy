/*
 * RegisterActivateResponse.cpp
 *
 *  Created on: 2010-3-31
 *      Author: kwarph
 */

#include <ostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

#include "RegisterActivateResponse.h"
#include "MessageUtils.h"

xmessenger::RegisterActivateResponse::RegisterActivateResponse() {
}

xmessenger::RegisterActivateResponse::RegisterActivateResponse(
        const ResultCode& _result) :
        result(_result) {
}

int xmessenger::RegisterActivateResponse::code() const {
    return MSG_REGISTER_ACTIVATE_RES;
}

std::ostream& xmessenger::RegisterActivateResponse::output(
        std::ostream& os) const {
    return os << "RegisterActivateResponse: result[" << result << "]";
}

xmessenger::ResultCode xmessenger::RegisterActivateResponse::getResult() const {
    return result;
}

void xmessenger::RegisterActivateResponse::setResult(const ResultCode& result) {
    this->result = result;
}

size_t xmessenger::RegisterActivateResponse::encodeBody(
        char* outputBuffer) const {
    char* cur = encodeIntField(outputBuffer, result);
    *cur = '\0';
    return std::strlen(outputBuffer);
}

const char* xmessenger::RegisterActivateResponse::decodeBody(
        const char* inputBuffer) {
    int res;
    const char* cur = decodeIntField(inputBuffer, res);
    result = xmessenger::ResultCode(res);

    return cur;
}
