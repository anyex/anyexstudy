/*
 * AddBuddyRequest.cpp
 *
 *  Created on: 2010-7-8 下午09:49:44
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <ostream>
#include <cstring>

#include "AddBuddyRequest.h"
#include "MessageUtils.h"

xmessenger::AddBuddyRequest::AddBuddyRequest() {

}

xmessenger::AddBuddyRequest::AddBuddyRequest(const std::string& _userName,
        const Buddy& _buddy, bool _roomMember) :
        userName(_userName), buddy(_buddy), roomMember(_roomMember) {
}

int xmessenger::AddBuddyRequest::code() const {
    return MSG_ADD_BUDDY_REQ;
}

std::ostream& xmessenger::AddBuddyRequest::output(std::ostream& os) const {
    os << "AddBuddyRequest: userName[" << userName;
    os << "], buddy[" << buddy.buddyName;
    os << "], isRoomMember[" << roomMember << "]";

    return os;
}

std::string xmessenger::AddBuddyRequest::getUserName() const {
    return userName;
}

xmessenger::Buddy xmessenger::AddBuddyRequest::getBuddy() const {
    return buddy;
}

void xmessenger::AddBuddyRequest::setUserName(const std::string& userName) {
    this->userName = userName;
}

void xmessenger::AddBuddyRequest::setBuddy(const Buddy& buddy) {
    this->buddy = buddy;
}

bool xmessenger::AddBuddyRequest::isRoomMember() const {
    return roomMember;
}

void xmessenger::AddBuddyRequest::setRoomMember(bool roomMember) {
    this->roomMember = roomMember;
}

size_t xmessenger::AddBuddyRequest::encodeBody(char* outputBuffer) const {
    char* cur = encodeStringField(outputBuffer, userName);
    *cur = FIELDS_DELIM;
    cur = encodeBuddyField(++cur, buddy);
    *cur = FIELDS_DELIM;
    cur = encodeBooleanField(++cur, roomMember);
    *cur = '\0';

    return std::strlen(outputBuffer);
}

const char* xmessenger::AddBuddyRequest::decodeBody(const char* inputBuffer) {
    const char* cur = decodeStringField(inputBuffer, userName);
    cur = decodeBuddyField(cur, buddy);
    cur = decodeBooleanField(cur, roomMember);

    return cur;
}
