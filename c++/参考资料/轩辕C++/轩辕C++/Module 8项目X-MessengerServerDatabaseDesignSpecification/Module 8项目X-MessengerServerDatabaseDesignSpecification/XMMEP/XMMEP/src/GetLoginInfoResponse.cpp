/*
 * GetLoginInfoResponse.cpp
 *
 *  Created on: 2010-3-31
 *      Author: kwarph
 */

#include <ostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

#include "GetLoginInfoResponse.h"
#include "MessageUtils.h"

xmessenger::GetLoginInfoResponse::GetLoginInfoResponse() {
}

xmessenger::GetLoginInfoResponse::GetLoginInfoResponse(
        const ResultCode& _result, const std::string& _serverIp,
        const short& _serverPort) :
        result(_result), serverIp(_serverIp), serverPort(_serverPort) {
}

int xmessenger::GetLoginInfoResponse::code() const {
    return MSG_GET_LOGIN_INFO_RES;
}

std::ostream& xmessenger::GetLoginInfoResponse::output(std::ostream& os) const {
    os << "GetLoginInfoResponse: result[" << result;
    os << "], serverIp[" << serverIp << "], serverPort[";
    os << serverPort << "]";

    return os;
}

xmessenger::ResultCode xmessenger::GetLoginInfoResponse::getResult() const {
    return result;
}

std::string xmessenger::GetLoginInfoResponse::getServerIp() const {
    return serverIp;
}

short xmessenger::GetLoginInfoResponse::getServerPort() const {
    return serverPort;
}

void xmessenger::GetLoginInfoResponse::setResult(const ResultCode& result) {
    this->result = result;
}

void xmessenger::GetLoginInfoResponse::setServerIp(
        const std::string& serverIp) {
    this->serverIp = serverIp;
}

void xmessenger::GetLoginInfoResponse::setServerPort(const short& serverPort) {
    this->serverPort = serverPort;
}

size_t xmessenger::GetLoginInfoResponse::encodeBody(char* outputBuffer) const {
    char* cur = encodeIntField(outputBuffer, result);
    if (result == xmessenger::RESULT_SUCCESS) {
        *cur = FIELDS_DELIM;
        cur = encodeStringField(++cur, serverIp);
        *cur = FIELDS_DELIM;
        cur = encodeShortField(++cur, serverPort);
    }

    *cur = '\0';
    return std::strlen(outputBuffer);
}

const char* xmessenger::GetLoginInfoResponse::decodeBody(
        const char* inputBuffer) {
    int res;
    const char* cur = decodeIntField(inputBuffer, res);
    result = ResultCode(res);
    if (result == xmessenger::RESULT_SUCCESS) {
        cur = decodeStringField(cur, serverIp);
        serverPort = std::atoi(cur);
    }

    return cur;
}
