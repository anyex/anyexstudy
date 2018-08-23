/*
 * UserRegisteredNotify.cpp
 *
 *  Created on: Sep 15, 2011
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 */

#include <ostream>
#include <cstring>

#include "UserRegisteredNotify.h"
#include "MessageUtils.h"

xmessenger::UserRegisteredNotify::UserRegisteredNotify() {

}

xmessenger::UserRegisteredNotify::UserRegisteredNotify(
        const std::string& _userName, const std::string& _password,
        const std::string& _email, const std::string& _nickname,
        const std::string& _personalMsg, const std::string& _birthdate,
        const std::string& _location, bool _gender) :
        userName(_userName), password(_password), email(_email), nickname(
                _nickname), personalMsg(_personalMsg), birthdate(_birthdate), location(
                _location), gender(_gender) {

}

int xmessenger::UserRegisteredNotify::code() const {
    return MSG_USER_REGISTERED_NOTIFY;
}

std::ostream& xmessenger::UserRegisteredNotify::output(std::ostream& os) const {
    os << "UserRegisteredNotify: userName[" << userName;
    os << "], password[" << password << "], email[";
    os << email << "]";

    return os;
}

std::string xmessenger::UserRegisteredNotify::getUserName() const {
    return userName;
}

std::string xmessenger::UserRegisteredNotify::getPassword() const {
    return password;
}

std::string xmessenger::UserRegisteredNotify::getEmail() const {
    return email;
}

void xmessenger::UserRegisteredNotify::setUserName(
        const std::string& userName) {
    this->userName = userName;
}

void xmessenger::UserRegisteredNotify::setPassword(
        const std::string& password) {
    this->password = password;
}

void xmessenger::UserRegisteredNotify::setEmail(const std::string& email) {
    this->email = email;
}

std::string xmessenger::UserRegisteredNotify::getBirthdate() const {
    return birthdate;
}

std::string xmessenger::UserRegisteredNotify::getLocation() const {
    return location;
}

std::string xmessenger::UserRegisteredNotify::getNickname() const {
    return nickname;
}

std::string xmessenger::UserRegisteredNotify::getPersonalMsg() const {
    return personalMsg;
}

bool xmessenger::UserRegisteredNotify::getGender() const {
    return gender;
}

void xmessenger::UserRegisteredNotify::setBirthdate(
        const std::string& birthdate) {
    this->birthdate = birthdate;
}

void xmessenger::UserRegisteredNotify::setGender(bool gender) {
    this->gender = gender;
}

void xmessenger::UserRegisteredNotify::setLocation(
        const std::string& location) {
    this->location = location;
}

void xmessenger::UserRegisteredNotify::setNickname(
        const std::string& nickname) {
    this->nickname = nickname;
}

void xmessenger::UserRegisteredNotify::setPersonalMsg(
        const std::string& personalMsg) {
    this->personalMsg = personalMsg;
}

size_t xmessenger::UserRegisteredNotify::encodeBody(char* outputBuffer) const {
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

const char* xmessenger::UserRegisteredNotify::decodeBody(
        const char* inputBuffer) {
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
