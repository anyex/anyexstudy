/*
 * FileDownloadRequest.cpp
 *
 *  Created on: Jan 29, 2012 12:14:04 PM
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 *     Website: http://www.xuanyuan-soft.cn
 */

#include <ostream>
#include <cstring>

#include "FileDownloadRequest.h"
#include "MessageUtils.h"

xmessenger::FileDownloadRequest::FileDownloadRequest() {

}

xmessenger::FileDownloadRequest::FileDownloadRequest(const std::string& _sender,
        const size_t& id, const size_t& _transferId) :
        sender(_sender), fileId(id), transferId(_transferId) {

}

int xmessenger::FileDownloadRequest::code() const {
    return MSG_FILE_DOWNLOAD_REQ;
}

std::ostream& xmessenger::FileDownloadRequest::output(std::ostream& os) const {
    os << "FileDownloadRequest: sender[" << sender << "], fileId[" << fileId
            << "]";

    return os;
}

size_t xmessenger::FileDownloadRequest::getFileId() const {
    return fileId;
}

void xmessenger::FileDownloadRequest::setFileId(const size_t& fileId) {
    this->fileId = fileId;
}

size_t xmessenger::FileDownloadRequest::getTransferId() const {
    return transferId;
}

void xmessenger::FileDownloadRequest::setTransferId(const size_t& transferId) {
    this->transferId = transferId;
}

std::string xmessenger::FileDownloadRequest::getSender() const {
    return sender;
}

void xmessenger::FileDownloadRequest::setSender(const std::string& _sender) {
    sender = _sender;
}

size_t xmessenger::FileDownloadRequest::encodeBody(char* outputBuffer) const {
    char* cur = encodeStringField(outputBuffer, sender);
    *cur = FIELDS_DELIM;
    cur = encodeUIntField(++cur, fileId);
    *cur = FIELDS_DELIM;
    cur = encodeUIntField(++cur, transferId);

    *cur = '\0';

    return std::strlen(outputBuffer);
}

const char* xmessenger::FileDownloadRequest::decodeBody(
        const char* inputBuffer) {
    const char* cur = decodeStringField(inputBuffer, sender);
    cur = decodeUIntField(cur, fileId);
    cur = decodeUIntField(cur, transferId);

    return cur;
}
