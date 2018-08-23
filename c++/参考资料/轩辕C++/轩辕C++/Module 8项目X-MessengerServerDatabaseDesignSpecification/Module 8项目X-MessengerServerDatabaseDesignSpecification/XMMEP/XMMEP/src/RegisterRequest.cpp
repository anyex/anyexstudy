/*
 * RegisterRequest.cpp
 *
 *  Created on: Mar 27, 2010
 *      Author: fengw
 */

#include <ostream>
#include <cstring>

#include "RegisterRequest.h"
#include "MessageUtils.h"

xmessenger::RegisterRequest::RegisterRequest() {

}

xmessenger::RegisterRequest::RegisterRequest(const std::string& _userName,
        const std::string& _password, const std::string& _email,
        const std::string& _nickname, const std::string& _personalMsg,
        const std::string& _birthdate, const std::string& _location,
        bool _gender) :
        userName(_userName), password(_password), email(_email), nickname(
                _nickname), personalMsg(_personalMsg), birthdate(_birthdate), location(
                _location), gender(_gender) {

}

int xmessenger::RegisterRequest::code() const {
    return MSG_REGISTER_REQ;
}

std::ostream& xmessenger::RegisterRequest::output(std::ostream& os) const {
    os << "RegisterRequest: userName[" << userName;
    os << "], password[" << password << "], email[";
    os << email << "]";

    return os;
}

std::string xmessenger::RegisterRequest::getUserName() const {
    return userName;
}

std::string xmessenger::RegisterRequest::getPassword() const {
    return password;
}

std::string xmessenger::RegisterRequest::getEmail() const {
    return email;
}

void xmessenger::RegisterRequest::setUserName(const std::string& userName) {
    this->userName = userName;
}

void xmessenger::RegisterRequest::setPassword(const std::string& password) {
    this->password = password;
}

void xmessenger::RegisterRequest::setEmail(const std::string& email) {
    this->email = email;
}

std::string xmessenger::RegisterRequest::getBirthdate() const {
    return birthdate;
}

std::string xmessenger::RegisterRequest::getLocation() const {
    return location;
}

std::string xmessenger::RegisterRequest::getNickname() const {
    return nickname;
}

std::string xmessenger::RegisterRequest::getPersonalMsg() const {
    return personalMsg;
}

bool xmessenger::RegisterRequest::getGender() const {
    return gender;
}

void xmessenger::RegisterRequest::setBirthdate(const std::string& birthdate) {
    this->birthdate = birthdate;
}

void xmessenger::RegisterRequest::setGender(bool gender) {
    this->gender = gender;
}

void xmessenger::RegisterRequest::setLocation(const std::string& location) {
    this->location = location;
}

void xmessenger::RegisterRequest::setNickname(const std::string& nickname) {
    this->nickname = nickname;
}

void xmessenger::RegisterRequest::setPersonalMsg(
        const std::string& personalMsg) {
    this->personalMsg = personalMsg;
}

size_t xmessenger::RegisterRequest::encodeBody(char* outputBuffer) const {
    char* cur = encodeStringField(outputBuffer, userName);
    *cur = FIELDS_DELIM;
    cur = encodeStringField(++cur, password);
    *cur = FIELDS_DELIM;
    cur = encodeStringField(++cur, email);
    *cur = FIELDS_DELIM;
    cur = encodeStringField(++cur, nickname);
    *cur = FIELDS_DELIM;
    cur = encodeStringField(++cur, personalMsg);
    *cur = FIELDS_DELIM;
    cur = encodeStringField(++cur, birthdate);
    *cur = FIELDS_DELIM;
    cur = encodeStringField(++cur, location);
    *cur = FIELDS_DELIM;
    cur = encodeBooleanField(++cur, gender);
    *cur = '\0';

    return std::strlen(outputBuffer);
}

const char* xmessenger::RegisterRequest::decodeBody(const char* inputBuffer) {
    const char* cur = decodeStringField(inputBuffer, userName);
    cur = decodeStringField(cur, password);
    cur = decodeStringField(cur, email);
    cur = decodeStringField(cur, nickname);
    cur = decodeStringField(cur, personalMsg);
    cur = decodeStringField(cur, birthdate);
    cur = decodeStringField(cur, location);
    cur = decodeBooleanField(cur, gender);

    return cur;
}
