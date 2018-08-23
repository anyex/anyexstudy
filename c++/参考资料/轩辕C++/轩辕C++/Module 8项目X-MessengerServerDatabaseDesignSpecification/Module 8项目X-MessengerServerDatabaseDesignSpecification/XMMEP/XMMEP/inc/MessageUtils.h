/*
 * MessageUtils.h
 *
 *  Created on: Oct 1, 2011
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 */

#ifndef MESSAGEUTILS_H_
#define MESSAGEUTILS_H_

#include <string>

namespace xmessenger {

enum BodyFieldDelim {
    FIELDS_DELIM = 0x1, // Object's fileds delimiter
    MEMBER_FIELDS_DELIM = 0x2, // Member object's fileds delimiter
    LIST_ELEMENTS_DELIM = 0x3, //
    KEY_VALUE_DELIM = 0x04
};

char* encodeBooleanField(char* outBuf, bool field);
const char* decodeBooleanField(const char* inBuf, bool& field);

char* encodeShortField(char* outBuf, const short& field);
const char* decodeShortField(const char* inBuf, short& field);

char* encodeUShortField(char* outBuf, const unsigned short& field);
const char* decodeUShortField(const char* inBuf, unsigned short& field);

char* encodeIntField(char* outBuf, const int& field);
const char* decodeIntField(const char* inBuf, int& field);

char* encodeUIntField(char* outBuf, const unsigned int& field);
const char* decodeUIntField(const char* inBuf, unsigned int& field);

char* encodeStringField(char* outBuf, const std::string& field);
const char* decodeStringField(const char* inBuf, std::string& field);

} /* namespace xmessenger */

#endif /* MESSAGEUTILS_H_ */
