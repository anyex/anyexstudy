/*
 * OnlineBuddy.cpp
 *
 *  Created on: Jan 11, 2012 10:25:01 PM
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 *     Website: http://www.xuanyuan-soft.cn
 */

#include "OnlineBuddy.h"

#include "MessageUtils.h"

char* xmessenger::encodeOnlineBuddyField(char* outBuf,
        const OnlineBuddy& field) {
    char* cur = encodeStringField(outBuf, field.buddyName);
    *cur = MEMBER_FIELDS_DELIM;
    cur = encodeStringField(++cur, field.groupName);
    *cur = MEMBER_FIELDS_DELIM;
    cur = encodeStringField(++cur, field.displayName);
    *cur = MEMBER_FIELDS_DELIM;
    cur = encodeStringField(++cur, field.personalMsg);
    *cur = MEMBER_FIELDS_DELIM;
    cur = encodeStringField(++cur, field.avatar);
    *cur = MEMBER_FIELDS_DELIM;
    cur = encodeStringField(++cur, field.ip);
    *cur = MEMBER_FIELDS_DELIM;
    cur = encodeUShortField(++cur, field.port);
    *cur = MEMBER_FIELDS_DELIM;
    cur = encodeIntField(++cur, field.status);

    return cur;
}

const char* xmessenger::decodeOnlineBuddyField(const char* inBuf,
        OnlineBuddy& field) {
    const char* cur = decodeStringField(inBuf, field.buddyName);
    cur = decodeStringField(cur, field.groupName);
    cur = decodeStringField(cur, field.displayName);
    cur = decodeStringField(cur, field.personalMsg);
    cur = decodeStringField(cur, field.avatar);
    cur = decodeStringField(cur, field.ip);
    cur = decodeUShortField(cur, field.port);
    int s;
    cur = decodeIntField(cur, s);
    field.status = Presence(s);

    return cur;
}
