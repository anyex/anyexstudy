/*
 * AddBuddyResponse.cpp
 *
 *  Created on: 2010-7-8 下午09:49:44
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <ostream>
#include <cstring>

#include "AddBuddyResponse.h"
#include "MessageUtils.h"

xmessenger::AddBuddyResponse::AddBuddyResponse() {

}

xmessenger::AddBuddyResponse::AddBuddyResponse(const std::string& _userName,
        const bool& _result, const xmessenger::OnlineBuddy& _buddy,
        bool _roomMember) :
        userName(_userName), result(_result), buddy(_buddy), roomMember(
                _roomMember) {

}

int xmessenger::AddBuddyResponse::code() const {
    return MSG_ADD_BUDDY_RES;
}

std::ostream& xmessenger::AddBuddyResponse::output(std::ostream& os) const {
    os << "AddBuddyResponse: userName[" << userName;
    os << "], result[" << result;
    os << "], buddy[" << buddy.buddyName;
    os << "], isRoomMember[" << roomMember << "]";

    return os;
}

std::string xmessenger::AddBuddyResponse::getUserName() const {
    return userName;
}

bool xmessenger::AddBuddyResponse::getResult() const {
    return result;
}

xmessenger::OnlineBuddy xmessenger::AddBuddyResponse::getBuddy() const {
    return buddy;
}

void xmessenger::AddBuddyResponse::setUserName(const std::string& userName) {
    this->userName = userName;
}

void xmessenger::AddBuddyResponse::setResult(
        const bool& result) {
    this->result = result;
}

void xmessenger::AddBuddyResponse::setBuddy(const xmessenger::OnlineBuddy& buddy) {
    this->buddy = buddy;
}

bool xmessenger::AddBuddyResponse::isRoomMember() const {
    return roomMember;
}

void xmessenger::AddBuddyResponse::setRoomMember(bool roomMember) {
    this->roomMember = roomMember;
}

size_t xmessenger::AddBuddyResponse::encodeBody(char* outputBuffer) const {
    char* cur = encodeStringField(outputBuffer, userName);
    *cur = FIELDS_DELIM;
    cur = encodeBooleanField(++cur, result);
    *cur = FIELDS_DELIM;
    cur = encodeOnlineBuddyField(++cur, buddy);
    *cur = FIELDS_DELIM;
    cur = encodeBooleanField(++cur, roomMember);
    *cur = '\0';

    return std::strlen(outputBuffer);
}

const char* xmessenger::AddBuddyResponse::decodeBody(const char* inputBuffer) {
    const char* cur = decodeStringField(inputBuffer, userName);
    cur = decodeBooleanField(cur, result);
    cur = decodeOnlineBuddyField(cur, buddy);
    cur = decodeBooleanField(cur, roomMember);
    return cur;
}
