/*
 * SendFileRequest.cpp
 *
 *  Created on: Jan 13, 2011
 *      Author: kwarph
 */

#include <ostream>
#include <cstring>

#include "MessageUtils.h"
#include "SendFileRequest.h"

xmessenger::SendFileRequest::SendFileRequest() {

}

xmessenger::SendFileRequest::SendFileRequest(const std::string& _sender,
        const std::string& _receiver, const std::string& _fileName,
        const size_t& _fileSize, const size_t& _transferSeq, bool _isImage) :
        sender(_sender), receiver(_receiver), fileName(_fileName), fileSize(
                _fileSize), transferSeq(_transferSeq), imageFile(_isImage) {

}

int xmessenger::SendFileRequest::code() const {
    return MSG_SEND_FILE_REQ;
}

std::ostream& xmessenger::SendFileRequest::output(std::ostream& os) const {
    os << "SendFileRequest: sender[" << sender << "], receiver[" << receiver
            << "], fileName[" << fileName << "], fileSize[" << fileSize
            << "], transferSeq[" << transferSeq << "]";

    return os;
}

std::string xmessenger::SendFileRequest::getSender() const {
    return sender;
}

void xmessenger::SendFileRequest::setSender(const std::string& sender) {
    this->sender = sender;
}

std::string xmessenger::SendFileRequest::getReceiver() const {
    return receiver;
}

void xmessenger::SendFileRequest::setReceiver(const std::string& receiver) {
    this->receiver = receiver;
}

std::string xmessenger::SendFileRequest::getFileName() const {
    return fileName;
}

void xmessenger::SendFileRequest::setFileName(const std::string& fileName) {
    this->fileName = fileName;
}

size_t xmessenger::SendFileRequest::getFileSize() const {
    return fileSize;
}

void xmessenger::SendFileRequest::setFileSize(const size_t& fileSize) {
    this->fileSize = fileSize;
}

size_t xmessenger::SendFileRequest::getTransferSeq() const {
    return transferSeq;
}

void xmessenger::SendFileRequest::setTransferSeq(const size_t& transferSeq) {
    this->transferSeq = transferSeq;
}

bool xmessenger::SendFileRequest::isImage() const {
    return imageFile;
}

void xmessenger::SendFileRequest::setIsImage(bool imageFile) {
    this->imageFile = imageFile;
}

size_t xmessenger::SendFileRequest::encodeBody(char* outputBuffer) const {
    char* cur = encodeStringField(outputBuffer, sender);
    *cur = FIELDS_DELIM;
    cur = encodeStringField(++cur, receiver);
    *cur = FIELDS_DELIM;
    cur = encodeStringField(++cur, fileName);
    *cur = FIELDS_DELIM;
    cur = encodeUIntField(++cur, fileSize);
    *cur = FIELDS_DELIM;
    cur = encodeUIntField(++cur, transferSeq);
    *cur = FIELDS_DELIM;
    cur = encodeBooleanField(++cur, imageFile);
    *cur = '\0';

    return std::strlen(outputBuffer);
}

const char* xmessenger::SendFileRequest::decodeBody(const char* inputBuffer) {
    const char* cur = decodeStringField(inputBuffer, sender);
    cur = decodeStringField(cur, receiver);
    cur = decodeStringField(cur, fileName);
    cur = decodeUIntField(cur, fileSize);
    cur = decodeUIntField(cur, transferSeq);
    cur = decodeBooleanField(cur, imageFile);

    return cur;
}
