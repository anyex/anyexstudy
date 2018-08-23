/*
 * Chatroom.cpp
 *
 *  Created on: Jan 11, 2012 10:19:43 PM
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 *     Website: http://www.xuanyuan-soft.cn
 */

#include "Chatroom.h"

#include "MessageUtils.h"

char* xmessenger::encodeChatroomField(char* outBuf, Chatroom& field) {
    char* cur = encodeStringField(outBuf, field.roomName);
    *cur = MEMBER_FIELDS_DELIM;
    cur = encodeStringField(++cur, field.creator);
    *cur = MEMBER_FIELDS_DELIM;
    cur = encodeStringField(++cur, field.announce);

    return cur;
}

const char* xmessenger::decodeChatroomField(const char* inBuf,
        Chatroom& field) {
    const char* cur = decodeStringField(inBuf, field.roomName);
    cur = decodeStringField(cur, field.creator);
    cur = decodeStringField(cur, field.announce);

    return cur;
}
