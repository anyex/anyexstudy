/*
 * RegisterInfoUpdateRequest.cpp
 *
 *  Created on: 2010-7-9 下午10:20:24
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <ostream>
#include <cstring>

#include "RegisterInfoUpdateRequest.h"
#include "MessageUtils.h"

xmessenger::RegisterInfoUpdateRequest::RegisterInfoUpdateRequest() {

}

xmessenger::RegisterInfoUpdateRequest::RegisterInfoUpdateRequest(
        const std::string& _userName, const UserInfo& ui,
        const std::string& passwd) :
        userName(_userName), userInfo(ui), password(passwd) {

}

int xmessenger::RegisterInfoUpdateRequest::code() const {
    return MSG_REGISTER_INFO_UPDATE_REQ;
}

std::ostream& xmessenger::RegisterInfoUpdateRequest::output(
        std::ostream& os) const {
    os << "RegisterInfoUpdateRequest: userName[" << userName;
    os << "], userInfo[" << userInfo.userName << "]";
    return os;
}

std::string xmessenger::RegisterInfoUpdateRequest::getUserName() const {
    return userName;
}

xmessenger::UserInfo xmessenger::RegisterInfoUpdateRequest::getUserInfo() const {
    return userInfo;
}

void xmessenger::RegisterInfoUpdateRequest::setUserName(
        const std::string& userName) {
    this->userName = userName;
}

void xmessenger::RegisterInfoUpdateRequest::setUserInfo(
        const UserInfo& userInfo) {
    this->userInfo = userInfo;
}

std::string xmessenger::RegisterInfoUpdateRequest::getPassword() const {
    return password;
}

void xmessenger::RegisterInfoUpdateRequest::setPassword(
        const std::string& passwd) {
    password = passwd;
}

size_t xmessenger::RegisterInfoUpdateRequest::encodeBody(
        char* outputBuffer) const {
    char* cur = encodeStringField(outputBuffer, userName);
    *cur = FIELDS_DELIM;

    cur = encodeUserInfoField(++cur, userInfo);
    *cur = FIELDS_DELIM;

    cur = encodeStringField(++cur, password);
    *cur = '\0';
    return std::strlen(outputBuffer);
}

const char* xmessenger::RegisterInfoUpdateRequest::decodeBody(
        const char* inputBuffer) {
    const char* cur = decodeStringField(inputBuffer, userName);
    cur = decodeUserInfoField(cur, userInfo);
    cur = decodeStringField(cur, password);

    return cur;
}

