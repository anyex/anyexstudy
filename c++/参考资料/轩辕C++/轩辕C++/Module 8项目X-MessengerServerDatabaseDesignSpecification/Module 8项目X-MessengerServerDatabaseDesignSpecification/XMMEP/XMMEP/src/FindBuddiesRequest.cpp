/*
 * FindBuddiesRequest.cpp
 *
 *  Created on: 2010-7-9 下午03:52:41
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <ostream>
#include <cstring>

#include "FindBuddiesRequest.h"
#include "MessageUtils.h"

xmessenger::FindBuddiesRequest::FindBuddiesRequest() {

}

xmessenger::FindBuddiesRequest::FindBuddiesRequest(const std::string& _userName) :
        userName(_userName) {
}

int xmessenger::FindBuddiesRequest::code() const {
    return MSG_FIND_BUDDIES_REQ;
}

std::ostream& xmessenger::FindBuddiesRequest::output(std::ostream& os) const {
    os << "FindBuddiesRequest: userName[" << userName << "]";

    return os;
}

std::string xmessenger::FindBuddiesRequest::getUserName() const {
    return userName;
}

void xmessenger::FindBuddiesRequest::setUserName(const std::string& userName) {
    this->userName = userName;
}

const xmessenger::FindBuddiesRequest::ConditionMap&
xmessenger::FindBuddiesRequest::getConditions() const {
    return conditions;
}

xmessenger::FindBuddiesRequest::ConditionMap&
xmessenger::FindBuddiesRequest::getConditions() {
    return conditions;
}

size_t xmessenger::FindBuddiesRequest::encodeBody(char* outputBuffer) const {
    char* cur = encodeStringField(outputBuffer, userName);
    *cur = FIELDS_DELIM;
    cur = encodeIntField(++cur, conditions.size());
    if (!conditions.empty()) {
        *cur = FIELDS_DELIM;
        ConditionMap::const_iterator it = conditions.begin();
        for (; it != conditions.end(); ++it) {
            cur = encodeIntField(++cur, it->first);
            *cur = KEY_VALUE_DELIM;
            cur = encodeStringField(++cur, it->second);
            *cur = LIST_ELEMENTS_DELIM;
        }
    }
    *cur = '\0'; // rewrite last LIST_ELEMENTS_DELIM to '\0'

    return std::strlen(outputBuffer);
}

const char* xmessenger::FindBuddiesRequest::decodeBody(
        const char* inputBuffer) {
    const char* cur = decodeStringField(inputBuffer, userName);
    cur = decodeIntField(cur, conditionCount);
    if (conditionCount > 0) {
        int key;
        std::string value;
        for (int i = 0; i < conditionCount; ++i) {
            cur = decodeIntField(cur, key);
            cur = decodeStringField(cur, userName);
            conditions.insert(make_pair(SearchCondition(key), value));
        }
    }

    return cur;
}
