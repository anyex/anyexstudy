/*
 * FileCancelledNotify.cpp
 *
 *  Created on: Jan 29, 2012 11:41:46 AM
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 *     Website: http://www.xuanyuan-soft.cn
 */

#include <ostream>
#include <cstring>

#include "FileCancelledNotify.h"
#include "MessageUtils.h"

xmessenger::FileCancelledNotify::FileCancelledNotify() {

}

xmessenger::FileCancelledNotify::FileCancelledNotify(const std::string& _sender,
        const size_t& id) :
        sender(_sender), fileId(id) {

}

int xmessenger::FileCancelledNotify::code() const {
    return MSG_FILE_CANCELLED_NOTIFY;
}

std::ostream& xmessenger::FileCancelledNotify::output(std::ostream& os) const {
    os << "FileCancelledNotify: sender[" << sender << "], fileId[" << fileId
            << "]";

    return os;
}

size_t xmessenger::FileCancelledNotify::getFileId() const {
    return fileId;
}

void xmessenger::FileCancelledNotify::setFileId(const size_t& fileId) {
    this->fileId = fileId;
}

std::string xmessenger::FileCancelledNotify::getSender() const {
    return sender;
}

void xmessenger::FileCancelledNotify::setSender(const std::string& _sender) {
    sender = _sender;
}

size_t xmessenger::FileCancelledNotify::encodeBody(char* outputBuffer) const {
    char* cur = encodeStringField(outputBuffer, sender);
    *cur = FIELDS_DELIM;
    cur = encodeUIntField(++cur, fileId);

    *cur = '\0';

    return std::strlen(outputBuffer);
}

const char* xmessenger::FileCancelledNotify::decodeBody(const char* inputBuffer) {
    const char* cur = decodeStringField(inputBuffer, sender);
    cur = decodeUIntField(cur, fileId);

    return cur;
}
