/*
 * LoginResponse1.cpp
 *
 *  Created on: 2010-6-4
 *      Author: teacher
 */

#include <ostream>
#include <cstring>

#include "LoginResponse1.h"
#include "MessageUtils.h"

xmessenger::LoginResponse1::LoginResponse1() {

}

xmessenger::LoginResponse1::LoginResponse1(const ResultCode& _result,
        const UserInfo& ui) :
        result(_result), userInfo(ui) {

}

int xmessenger::LoginResponse1::code() const {
    return MSG_LOGIN_RES1;
}

std::ostream& xmessenger::LoginResponse1::output(std::ostream& os) const {
    os << "LoginResponse1: result[" << result << "]";
    if (RESULT_SUCCESS == result) {
        os << ", userInfo[" << userInfo.userName << "]";
    }
    return os;
}

xmessenger::ResultCode xmessenger::LoginResponse1::getResult() const {
    return result;
}

const xmessenger::UserInfo& xmessenger::LoginResponse1::getUserInfo() const {
    return userInfo;
}

void xmessenger::LoginResponse1::setResult(const ResultCode& result) {
    this->result = result;
}

void xmessenger::LoginResponse1::setUserInfo(const UserInfo& userInfo) {
    this->userInfo = userInfo;
}

size_t xmessenger::LoginResponse1::encodeBody(char* outputBuffer) const {
    char* cur = encodeIntField(outputBuffer, result);
    if (xmessenger::RESULT_SUCCESS == result) {
        *cur = FIELDS_DELIM;
        // encode userInfo
        cur = encodeUserInfoField(++cur, userInfo);
    }

    *cur = '\0';
    return std::strlen(outputBuffer);
}

const char* xmessenger::LoginResponse1::decodeBody(const char* inputBuffer) {
    int res;
    const char* cur = decodeIntField(inputBuffer, res);
    result = xmessenger::ResultCode(res);
    if (xmessenger::RESULT_SUCCESS == result)
        cur = decodeUserInfoField(cur, userInfo);

    return cur;
}

