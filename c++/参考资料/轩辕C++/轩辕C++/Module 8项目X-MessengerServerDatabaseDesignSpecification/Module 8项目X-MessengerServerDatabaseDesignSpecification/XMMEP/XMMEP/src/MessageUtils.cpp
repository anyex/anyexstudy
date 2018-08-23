/*
 * MessageUtils.cpp
 *
 *  Created on: Oct 1, 2011
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 */

#include <cstdio>
#include <cstring>
#include <cstdlib>

#include "MessageUtils.h"

namespace {

char fieldDelim[] = { xmessenger::FIELDS_DELIM, // Object's fileds delimiter
        xmessenger::MEMBER_FIELDS_DELIM, // Member object's fileds delimiter
        xmessenger::LIST_ELEMENTS_DELIM, //
        xmessenger::KEY_VALUE_DELIM, //
        0x0 };

}

char* xmessenger::encodeBooleanField(char* outBuf, bool field) {
    std::sprintf(outBuf, "%d", field);
    return outBuf + std::strlen(outBuf);
}

const char* xmessenger::decodeBooleanField(const char* inBuf, bool& field) {
    const char* pos = std::strpbrk(inBuf, fieldDelim);
    if (0 != pos) {
        size_t len = pos - inBuf + 1;
        char tmp[2] = "";
        std::memcpy(tmp, inBuf, len - 1);
        field = bool(std::atoi(tmp));
        return inBuf + len;
    }
    field = bool(std::atoi(inBuf));
    return inBuf + (std::strlen(inBuf) + 1);
}

char* xmessenger::encodeShortField(char* outBuf, const short& field) {
    std::sprintf(outBuf, "%hd", field);
    return outBuf + std::strlen(outBuf);
}

const char* xmessenger::decodeShortField(const char* inBuf, short& field) {
    const char* pos = std::strpbrk(inBuf, fieldDelim);
    if (0 != pos) {
        size_t len = pos - inBuf + 1;
        char tmp[6] = "";
        std::memcpy(tmp, inBuf, len - 1);
        field = std::atoi(tmp);
        return inBuf + len;
    }
    field = std::atoi(inBuf);
    return inBuf + (std::strlen(inBuf) + 1);
}

char* xmessenger::encodeUShortField(char* outBuf, const unsigned short& field) {
    std::sprintf(outBuf, "%hu", field);
    return outBuf + std::strlen(outBuf);
}

const char* xmessenger::decodeUShortField(const char* inBuf,
        unsigned short& field) {
    const char* pos = std::strpbrk(inBuf, fieldDelim);
    if (0 != pos) {
        size_t len = pos - inBuf + 1;
        char tmp[6] = "";
        std::memcpy(tmp, inBuf, len - 1);
        std::sscanf(tmp, "%hu", &field);
//        field = std::atoi(tmp);
        return inBuf + len;
    }
    std::sscanf(inBuf, "%hu", &field);
//    field = std::atoi(inBuf);
    return inBuf + (std::strlen(inBuf) + 1);
}

char* xmessenger::encodeIntField(char* outBuf, const int& field) {
    std::sprintf(outBuf, "%d", field);
    return outBuf + std::strlen(outBuf);
}

const char* xmessenger::decodeIntField(const char* inBuf, int& field) {
    const char* pos = std::strpbrk(inBuf, fieldDelim);
    if (0 != pos) {
        size_t len = pos - inBuf + 1;
        char tmp[12] = "";
        std::memcpy(tmp, inBuf, len - 1);
        field = std::atoi(tmp);
        return inBuf + len;
    }
    field = std::atoi(inBuf);
    return inBuf + (std::strlen(inBuf) + 1);
}

char* xmessenger::encodeUIntField(char* outBuf, const unsigned int& field) {
    std::sprintf(outBuf, "%u", field);
    return outBuf + std::strlen(outBuf);
}

const char* xmessenger::decodeUIntField(const char* inBuf,
        unsigned int& field) {
    const char* pos = std::strpbrk(inBuf, fieldDelim);
        if (0 != pos) {
            size_t len = pos - inBuf + 1;
            char tmp[12] = "";
            std::memcpy(tmp, inBuf, len - 1);
            std::sscanf(tmp, "%u", &field);
//            field = std::atoi(tmp);
            return inBuf + len;
        }
//        field = std::atoi(inBuf);
        std::sscanf(inBuf, "%u", &field);
        return inBuf + (std::strlen(inBuf) + 1);
}

char* xmessenger::encodeStringField(char* outBuf, const std::string& field) {
    std::sprintf(outBuf, "%s", field.c_str());
    return outBuf + std::strlen(outBuf);
}

const char* xmessenger::decodeStringField(const char* inBuf,
        std::string& field) {
    const char* pos = std::strpbrk(inBuf, fieldDelim);
    if (0 != pos) {
        field = std::string(inBuf, pos);
        ++pos;
    } else
        field = inBuf;

    return pos;
}
