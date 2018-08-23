/*
 * RegisterResponse.cpp
 *
 *  Created on: 2010-3-31
 *      Author: kwarph
 */

#include <ostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

#include "RegisterResponse.h"
#include "MessageUtils.h"

xmessenger::RegisterResponse::RegisterResponse() {
}

xmessenger::RegisterResponse::RegisterResponse(const ResultCode& _result) :
        result(_result) {
}

int xmessenger::RegisterResponse::code() const {
    return MSG_REGISTER_RES;
}

std::ostream& xmessenger::RegisterResponse::output(std::ostream& os) const {
    os << "RegisterResponse: result[" << result << "]";

    return os;
}

xmessenger::ResultCode xmessenger::RegisterResponse::getResult() const {
    return result;
}

void xmessenger::RegisterResponse::setResult(const ResultCode& result) {
    this->result = result;
}

size_t xmessenger::RegisterResponse::encodeBody(char* outputBuffer) const {
    encodeIntField(outputBuffer, result);
    return std::strlen(outputBuffer);
}

const char* xmessenger::RegisterResponse::decodeBody(const char* inputBuffer) {
    int res;
    const char* cur = decodeIntField(inputBuffer, res);
    result = ResultCode(res);

    return cur;
}
