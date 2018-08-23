/*
 * TextMessage.cpp
 *
 *  Created on: 2010-4-15 下午09:17:07
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <ostream>
#include <ctime>
#include <cstring>

#include "TextMessage.h"
#include "MessageUtils.h"

xmessenger::TextMessage::TextMessage() :
        sendTime() {
}

xmessenger::TextMessage::TextMessage(const std::string& _sender,
        const std::string& _receiver, const int& _sendTime,
        const std::string& _content, bool isToRoom) :
        sender(_sender), receiver(_receiver), sendTime(_sendTime), content(
                _content), isRoomMsg(isToRoom) {
}

int xmessenger::TextMessage::code() const {
    return MSG_TXT_MSG;
}

std::ostream& xmessenger::TextMessage::output(std::ostream& os) const {
    os << "TextMessage: sender[" << sender;
    os << "], receiver[" << receiver << "], sendTime[";
    char ds[24] = "";
    time_t t = sendTime;
    tm* now = std::localtime(&t);
    std::strftime(ds, sizeof(ds), "%F %T", now);
    os << ds << "], content[" << content << "]";

    return os;
}

std::string xmessenger::TextMessage::getContent() const {
    return content;
}

bool xmessenger::TextMessage::isRoomMessage() const {
    return isRoomMsg;
}

std::string xmessenger::TextMessage::getReceiver() const {
    return receiver;
}

int xmessenger::TextMessage::getSendTime() const {
    return sendTime;
}

std::string xmessenger::TextMessage::getSender() const {
    return sender;
}

void xmessenger::TextMessage::setContent(const std::string& content) {
    this->content = content;
}

void xmessenger::TextMessage::setReceiver(const std::string& receiver) {
    this->receiver = receiver;
}

void xmessenger::TextMessage::setSendTime(const int& sendTime) {
    this->sendTime = sendTime;
}

void xmessenger::TextMessage::setSender(const std::string& sender) {
    this->sender = sender;
}

void xmessenger::TextMessage::setIsRoomMessage(bool isRoomMsg) {
    this->isRoomMsg = isRoomMsg;
}

size_t xmessenger::TextMessage::encodeBody(char* outputBuffer) const {
    char* cur = encodeStringField(outputBuffer, sender);
    *cur = FIELDS_DELIM;
    cur = encodeStringField(++cur, receiver);
    *cur = FIELDS_DELIM;
    cur = encodeIntField(++cur, sendTime);
    *cur = FIELDS_DELIM;
    cur = encodeStringField(++cur, content);
    *cur = FIELDS_DELIM;
    cur = encodeBooleanField(++cur, isRoomMsg);
    *cur = '\0';

    return std::strlen(outputBuffer);
}

const char* xmessenger::TextMessage::decodeBody(const char* inputBuffer) {
    const char* cur = decodeStringField(inputBuffer, sender);
    cur = decodeStringField(cur, receiver);
    cur = decodeIntField(cur, sendTime);
    cur = decodeStringField(cur, content);
    cur = decodeBooleanField(cur, isRoomMsg);

    return cur;
}
