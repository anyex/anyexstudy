/*
 * BuddyLoginNotifyFwd.cpp
 *
 *  Created on: Sep 27, 2011
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 */

#include <ostream>
#include <cstring>

#include "BuddyLoginNotifyFwd.h"
#include "MessageUtils.h"

xmessenger::BuddyLoginNotifyFwd::BuddyLoginNotifyFwd() {

}

xmessenger::BuddyLoginNotifyFwd::BuddyLoginNotifyFwd(
        const OnlineBuddy& loginUser) :
        user(loginUser) {

}

int xmessenger::BuddyLoginNotifyFwd::code() const {
    return MSG_BUDDY_LOGIN_NOTIFY_FWD;
}

std::ostream& xmessenger::BuddyLoginNotifyFwd::output(std::ostream& os) const {
    os << "UserLoginNotifyFwd: loginUser[" << user.buddyName << "], receivers["
            << receivers.size() << " receivers]";
    return os;
}

const std::vector<std::string>&
xmessenger::BuddyLoginNotifyFwd::getReceivers() const {
    return receivers;
}

std::vector<std::string>& xmessenger::BuddyLoginNotifyFwd::getReceivers() {
    return receivers;
}

const xmessenger::OnlineBuddy& xmessenger::BuddyLoginNotifyFwd::getUser() const {
    return user;
}

void xmessenger::BuddyLoginNotifyFwd::setUser(
        const xmessenger::OnlineBuddy& user) {
    this->user = user;
}

size_t xmessenger::BuddyLoginNotifyFwd::encodeBody(char* outputBuffer) const {
    const size_t count = receivers.size();
    char* cur = encodeIntField(++outputBuffer, count);
    *cur = FIELDS_DELIM;

    for (size_t i = 0; i < count; ++i) {
        cur = encodeStringField(++cur, receivers[i]);
        *cur = LIST_ELEMENTS_DELIM;
    }
    *cur = FIELDS_DELIM;

    cur = encodeOnlineBuddyField(++cur, user);
    *cur = '\0'; // rewrite last LIST_ELEMENTS_DELIM to '\0'

    return std::strlen(outputBuffer);
}

const char* xmessenger::BuddyLoginNotifyFwd::decodeBody(
        const char* inputBuffer) {
    int count = 0;
    const char* cur = decodeIntField(inputBuffer, count);
    for (int i = 0; i < count; ++i) {
        std::string u;
        cur = decodeStringField(cur, u);
        receivers.push_back(u);
    }

    cur = decodeOnlineBuddyField(cur, user);

    return cur;
}
