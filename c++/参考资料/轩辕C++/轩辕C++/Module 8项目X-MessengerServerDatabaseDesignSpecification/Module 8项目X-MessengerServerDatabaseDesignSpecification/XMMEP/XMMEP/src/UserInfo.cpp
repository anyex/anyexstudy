/*
 * UserInfo.cpp
 *
 *  Created on: Jan 11, 2012 10:16:30 PM
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 *     Website: http://www.xuanyuan-soft.cn
 */

#include "UserInfo.h"
#include "MessageUtils.h"

char* xmessenger::encodeUserInfoField(char* outBuf, const UserInfo& field) {
    char* cur = encodeStringField(outBuf, field.userName);
    *cur = MEMBER_FIELDS_DELIM;
    cur = encodeStringField(++cur, field.nickname);
    *cur = MEMBER_FIELDS_DELIM;
    cur = encodeStringField(++cur, field.personalMsg);
    *cur = MEMBER_FIELDS_DELIM;
    cur = encodeStringField(++cur, field.email);
    *cur = MEMBER_FIELDS_DELIM;
    cur = encodeStringField(++cur, field.avatar);
    *cur = MEMBER_FIELDS_DELIM;
    cur = encodeStringField(++cur, field.location);
    *cur = MEMBER_FIELDS_DELIM;
    cur = encodeIntField(++cur, field.birthday);
    *cur = MEMBER_FIELDS_DELIM;
    cur = encodeIntField(++cur, field.lastLoginTime);
    *cur = MEMBER_FIELDS_DELIM;
    cur = encodeBooleanField(++cur, field.gender);

    return cur;
}

const char* xmessenger::decodeUserInfoField(const char* inBuf,
        UserInfo& field) {
    const char* cur = decodeStringField(inBuf, field.userName);
    cur = decodeStringField(cur, field.nickname);
    cur = decodeStringField(cur, field.personalMsg);
    cur = decodeStringField(cur, field.email);
    cur = decodeStringField(cur, field.avatar);
    cur = decodeStringField(cur, field.location);
    cur = decodeIntField(cur, field.birthday);
    cur = decodeIntField(cur, field.lastLoginTime);
    cur = decodeBooleanField(cur, field.gender);

    return cur;
}
