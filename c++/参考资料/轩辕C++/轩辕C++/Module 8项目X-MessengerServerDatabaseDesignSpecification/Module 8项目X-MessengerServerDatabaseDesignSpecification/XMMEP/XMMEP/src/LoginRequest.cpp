/*
 * LoginRequest.cpp
 *
 *  Created on: 2010-3-23 下午08:45:43
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */
#include <ostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

#include "LoginRequest.h"
#include "MessageUtils.h"

xmessenger::LoginRequest::LoginRequest() :
        loginStatus(xmessenger::ONLINE) {

}

xmessenger::LoginRequest::LoginRequest(const std::string& _userName,
        const std::string& _password, const Presence& _loginStatus) :
        userName(_userName), password(_password), loginStatus(_loginStatus) {
}

int xmessenger::LoginRequest::code() const {
    return MSG_LOGIN_REQ;
}

std::ostream& xmessenger::LoginRequest::output(std::ostream& os) const {
    os << "LoginRequest: userName[" << userName;
    os << "], password[***], loginStatus[";
    os << loginStatus << "]";

    return os;
}

xmessenger::Presence xmessenger::LoginRequest::getLoginStatus() const {
    return loginStatus;
}

std::string xmessenger::LoginRequest::getPassword() const {
    return password;
}

std::string xmessenger::LoginRequest::getUserName() const {
    return userName;
}

void xmessenger::LoginRequest::setLoginStatus(const Presence& loginStatus) {
    this->loginStatus = loginStatus;
}

void xmessenger::LoginRequest::setPassword(const std::string& password) {
    this->password = password;
}

void xmessenger::LoginRequest::setUserName(const std::string& userName) {
    this->userName = userName;
}

size_t xmessenger::LoginRequest::encodeBody(char* outputBuffer) const {
    char* cur = encodeStringField(outputBuffer, userName);
    *cur = FIELDS_DELIM;
    cur = encodeStringField(++cur, password);
    *cur = FIELDS_DELIM;
    std::sprintf(++cur, "%1d", loginStatus);

    return std::strlen(outputBuffer);
}

const char* xmessenger::LoginRequest::decodeBody(const char* inputBuffer) {
    const char* cur = decodeStringField(inputBuffer, userName);
    cur = decodeStringField(cur, password);

    int p;
    cur = decodeIntField(cur, p);
    loginStatus = Presence(p);

    return cur;
}
