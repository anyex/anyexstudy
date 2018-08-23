/*
 * Buddy.cpp
 *
 *  Created on: Jan 11, 2012 10:23:03 PM
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 *     Website: http://www.xuanyuan-soft.cn
 */

#include "Buddy.h"
#include "MessageUtils.h"

char* xmessenger::encodeBuddyField(char* outBuf, const Buddy& field) {
    char* cur = encodeStringField(outBuf, field.buddyName);
    *cur = MEMBER_FIELDS_DELIM;
    cur = encodeStringField(++cur, field.groupName);
    *cur = MEMBER_FIELDS_DELIM;
    cur = encodeStringField(++cur, field.displayName);

    return cur;
}

const char* xmessenger::decodeBuddyField(const char* inBuf, Buddy& field) {
    const char* cur = decodeStringField(inBuf, field.buddyName);
    cur = decodeStringField(cur, field.groupName);
    cur = decodeStringField(cur, field.displayName);

    return cur;
}
