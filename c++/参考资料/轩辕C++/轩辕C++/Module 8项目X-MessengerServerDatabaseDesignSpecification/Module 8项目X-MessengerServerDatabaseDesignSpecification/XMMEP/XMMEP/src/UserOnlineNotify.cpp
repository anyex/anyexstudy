/*
 * UserOnlineNotify.cpp
 *
 *  Created on: Mar 30, 2011
 *      Author: kwarph
 */

#include <ostream>
#include <cstring>

#include "UserOnlineNotify.h"
#include "MessageUtils.h"

xmessenger::UserOnlineNotify::UserOnlineNotify() {

}

xmessenger::UserOnlineNotify::UserOnlineNotify(const std::string& name,
        const std::string& _nickname, const std::string& _avatar,
        const std::string& _personalMsg) :
        userName(name), nickname(_nickname), avatar(_avatar), personalMsg(
                _personalMsg) {

}

int xmessenger::UserOnlineNotify::code() const {
    return MSG_USER_ONLINE_NOTIFY;
}

std::ostream& xmessenger::UserOnlineNotify::output(std::ostream& os) const {
    return os << "UserOnlineNotify: userName[" << userName << "], nickname["
            << nickname << "]";
}

std::string xmessenger::UserOnlineNotify::getUserName() const {
    return userName;
}

void xmessenger::UserOnlineNotify::setUserName(const std::string& name) {
    userName = name;
}

std::string xmessenger::UserOnlineNotify::getNickname() const {
    return nickname;
}

void xmessenger::UserOnlineNotify::setNickname(const std::string& nickname) {
    this->nickname = nickname;
}

std::string xmessenger::UserOnlineNotify::getAvatar() const {
    return avatar;
}

void xmessenger::UserOnlineNotify::setAvatar(const std::string& avatar) {
    this->avatar = avatar;
}

std::string xmessenger::UserOnlineNotify::getPersonalMsg() const {
    return personalMsg;
}

void xmessenger::UserOnlineNotify::setPersonalMsg(
        const std::string& personalMsg) {
    this->personalMsg = personalMsg;
}

size_t xmessenger::UserOnlineNotify::encodeBody(char* outputBuffer) const {
    char* cur = encodeStringField(outputBuffer, userName);
    *cur = FIELDS_DELIM;
    cur = encodeStringField(++cur, nickname);
    *cur = FIELDS_DELIM;
    cur = encodeStringField(++cur, avatar);
    *cur = FIELDS_DELIM;
    cur = encodeStringField(++cur, personalMsg);
    *cur = '\0';

    return std::strlen(outputBuffer);
}

const char* xmessenger::UserOnlineNotify::decodeBody(const char* inputBuffer) {
    const char* cur = decodeStringField(inputBuffer, userName);
    cur = decodeStringField(cur, nickname);
    cur = decodeStringField(cur, avatar);
    cur = decodeStringField(cur, personalMsg);
    return cur;
}
