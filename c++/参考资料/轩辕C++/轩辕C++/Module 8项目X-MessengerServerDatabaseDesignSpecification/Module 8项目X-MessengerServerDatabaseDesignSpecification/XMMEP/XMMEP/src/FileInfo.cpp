/*
 * FileInfo.cpp
 *
 *  Created on: Jan 11, 2012 10:26:42 PM
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 *     Website: http://www.xuanyuan-soft.cn
 */

#include "FileInfo.h"
#include "MessageUtils.h"

char* xmessenger::encodeFileInfoField(char* outBuf, const FileInfo& field) {
    char* cur = encodeUIntField(outBuf, field.fileId);
    *cur = MEMBER_FIELDS_DELIM;
    cur = encodeStringField(++cur, field.fileName);
    *cur = MEMBER_FIELDS_DELIM;
    cur = encodeStringField(++cur, field.fileType);
    *cur = MEMBER_FIELDS_DELIM;
    cur = encodeUIntField(++cur, field.fileSize);
    *cur = MEMBER_FIELDS_DELIM;
    cur = encodeStringField(++cur, field.password);
    *cur = MEMBER_FIELDS_DELIM;
    cur = encodeStringField(++cur, field.submittedBy);

    return cur;
}

const char* xmessenger::decodeFileInfoField(const char* inBuf,
        FileInfo& field) {
    const char* cur = decodeUIntField(inBuf, field.fileId);
    cur = decodeStringField(cur, field.fileName);
    cur = decodeStringField(cur, field.fileType);
    cur = decodeUIntField(cur, field.fileSize);
    cur = decodeStringField(cur, field.password);
    cur = decodeStringField(cur, field.submittedBy);

    return cur;
}
