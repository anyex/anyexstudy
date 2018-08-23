/*
 * FileSubmittedNotify.cpp
 *
 *  Created on: May 30, 2011
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 */

#include <ostream>
#include <cstring>

#include "MessageUtils.h"
#include "FileSubmittedNotify.h"

xmessenger::FileSubmittedNotify::FileSubmittedNotify() {

}

xmessenger::FileSubmittedNotify::FileSubmittedNotify(const std::string& _sender) :
        sender(_sender) {

}

int xmessenger::FileSubmittedNotify::code() const {
    return MSG_FILE_SUBMITTED_NOTIFY;
}

std::ostream& xmessenger::FileSubmittedNotify::output(std::ostream& os) const {
    os << "FileCancelledNotify: sender[" << sender << "], files[ "
            << files.size() << " items]";

    return os;
}

void xmessenger::FileSubmittedNotify::addFileInfo(const FileInfo& info) {
    files.push_back(info);
}

const std::vector<xmessenger::FileInfo>& xmessenger::FileSubmittedNotify::getFileInfos() const {
    return files;
}

std::string xmessenger::FileSubmittedNotify::getSender() const {
    return sender;
}

void xmessenger::FileSubmittedNotify::setSender(const std::string& _sender) {
    sender = _sender;
}

size_t xmessenger::FileSubmittedNotify::encodeBody(char* outputBuffer) const {
    char* cur = encodeStringField(outputBuffer, sender);
    *cur = FIELDS_DELIM;
    for (size_t i = 0; i < files.size(); ++i) {
        cur = encodeFileInfoField(++cur, files[i]);
        *cur = LIST_ELEMENTS_DELIM;
    }
    *cur = '\0';

    return std::strlen(outputBuffer);
}

const char* xmessenger::FileSubmittedNotify::decodeBody(
        const char* inputBuffer) {
    const char* cur = decodeStringField(inputBuffer, sender);
    while (cur) {
        FileInfo f;
        cur = decodeFileInfoField(cur, f);
        files.push_back(f);
    }

    return cur;
}
