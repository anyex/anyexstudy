/*
 * GetBuddyInfoResponse.cpp
 *
 *  Created on: 2010-7-9 下午01:36:34
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <ostream>
#include <cstring>

#include "GetBuddyInfoResponse.h"
#include "MessageUtils.h"

xmessenger::GetBuddyInfoResponse::GetBuddyInfoResponse() {

}

xmessenger::GetBuddyInfoResponse::GetBuddyInfoResponse(
        const std::string& _userName, const ResultCode& _result,
        const UserInfo& ui) :
        userName(_userName), result(_result), buddyInfo(ui) {

}

int xmessenger::GetBuddyInfoResponse::code() const {
    return MSG_GET_BUDDY_INFO_RES;
}

std::ostream& xmessenger::GetBuddyInfoResponse::output(std::ostream& os) const {
    os << "GetBuddyInfoResponse: userName[" << userName;
    os << "], result[" << result << "]";
    if (RESULT_SUCCESS == result) {
        os << ", buddyInfo[" << buddyInfo.userName << "]";
    }
    return os;
}

std::string xmessenger::GetBuddyInfoResponse::getUserName() const {
    return userName;
}

xmessenger::ResultCode xmessenger::GetBuddyInfoResponse::getResult() const {
    return result;
}

xmessenger::UserInfo xmessenger::GetBuddyInfoResponse::getBuddyInfo() const {
    return buddyInfo;
}

void xmessenger::GetBuddyInfoResponse::setUserName(
        const std::string& userName) {
    this->userName = userName;
}

void xmessenger::GetBuddyInfoResponse::setResult(const ResultCode& result) {
    this->result = result;
}

void xmessenger::GetBuddyInfoResponse::setBuddyInfo(const UserInfo& userInfo) {
    this->buddyInfo = userInfo;
}

size_t xmessenger::GetBuddyInfoResponse::encodeBody(char* outputBuffer) const {
    char* cur = encodeStringField(outputBuffer, userName);
    *cur = FIELDS_DELIM;
    cur = encodeIntField(++cur, result);
    if (xmessenger::RESULT_SUCCESS == result) {
        *cur = FIELDS_DELIM;
        cur = encodeUserInfoField(++cur, buddyInfo);
    }

    *cur = '\0';
    return std::strlen(outputBuffer);
}

const char* xmessenger::GetBuddyInfoResponse::decodeBody(
        const char* inputBuffer) {
    int res;
    const char* cur = decodeStringField(inputBuffer, userName);
    cur = decodeIntField(cur, res);
    result = xmessenger::ResultCode(res);
    if (xmessenger::RESULT_SUCCESS == result)
        cur = decodeUserInfoField(cur, buddyInfo);

    return cur;
}

