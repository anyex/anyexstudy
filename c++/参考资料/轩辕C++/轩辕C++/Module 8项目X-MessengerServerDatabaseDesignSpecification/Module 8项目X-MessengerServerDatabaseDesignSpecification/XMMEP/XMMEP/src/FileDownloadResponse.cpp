/*
 * FileDownloadResponse.cpp
 *
 *  Created on: Jan 29, 2012 3:14:18 PM
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 *     Website: http://www.xuanyuan-soft.cn
 */

#include <ostream>
#include <cstring>

#include "FileDownloadResponse.h"
#include "MessageUtils.h"

xmessenger::FileDownloadResponse::FileDownloadResponse() {

}

xmessenger::FileDownloadResponse::FileDownloadResponse(
        const std::string& _sender, const size_t& _transferId) :
        sender(_sender), transferId(_transferId) {

}

int xmessenger::FileDownloadResponse::code() const {
    return MSG_FILE_DOWNLOAD_RES;
}

std::ostream& xmessenger::FileDownloadResponse::output(std::ostream& os) const {
    os << "FileDownloadResponse: sender[" << sender << "], transferId["
            << transferId << "]";

    return os;
}

size_t xmessenger::FileDownloadResponse::getTransferId() const {
    return transferId;
}

void xmessenger::FileDownloadResponse::setTransferId(const size_t& transferId) {
    this->transferId = transferId;
}

std::string xmessenger::FileDownloadResponse::getSender() const {
    return sender;
}

void xmessenger::FileDownloadResponse::setSender(const std::string& _sender) {
    sender = _sender;
}

size_t xmessenger::FileDownloadResponse::encodeBody(char* outputBuffer) const {
    char* cur = encodeStringField(outputBuffer, sender);
    *cur = FIELDS_DELIM;
    cur = encodeUIntField(++cur, transferId);

    *cur = '\0';

    return std::strlen(outputBuffer);
}

const char* xmessenger::FileDownloadResponse::decodeBody(
        const char* inputBuffer) {
    const char* cur = decodeStringField(inputBuffer, sender);
    cur = decodeUIntField(cur, transferId);

    return cur;
}
