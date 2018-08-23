/*
 * SendFileRequestFwd.cpp
 *
 *  Created on: Jan 14, 2012 8:50:16 PM
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 *     Website: http://www.xuanyuan-soft.cn
 */

#include <ostream>
#include <cstring>

#include "MessageUtils.h"
#include "SendFileRequestFwd.h"

xmessenger::SendFileRequestFwd::SendFileRequestFwd() {

}

xmessenger::SendFileRequestFwd::SendFileRequestFwd(const std::string& _sender,
        const std::string& _receiver, const std::string& _fileName,
        const size_t& _fileSize, const size_t& _transferSeq, bool isImage,
        const std::string& _senderIp, unsigned short _senderPort) :
        SendFileRequest(_sender, _receiver, _fileName, _fileSize, _transferSeq,
                isImage), senderIp(_senderIp), senderPort(_senderPort) {

}

int xmessenger::SendFileRequestFwd::code() const {
    return MSG_SEND_FILE_REQ_FWD;
}

std::ostream& xmessenger::SendFileRequestFwd::output(std::ostream& os) const {
    os << "SendFileRequestFwd: ";
    os << SendFileRequest::output(os);
    os << "], senderIp[" << senderIp;
    os << "], senderPort[" << senderPort << "]";

    return os;
}

std::string xmessenger::SendFileRequestFwd::getSenderIp() const {
    return senderIp;
}

void xmessenger::SendFileRequestFwd::setSenderIp(const std::string& senderIp) {
    this->senderIp = senderIp;
}

unsigned short xmessenger::SendFileRequestFwd::getSenderPort() const {
    return senderPort;
}

void xmessenger::SendFileRequestFwd::setSenderPort(
        const unsigned short& senderPort) {
    this->senderPort = senderPort;
}

size_t xmessenger::SendFileRequestFwd::encodeBody(char* outputBuffer) const {
    size_t len = SendFileRequest::encodeBody(outputBuffer);
    outputBuffer[len] = FIELDS_DELIM;

    char* cur = encodeStringField(outputBuffer + len + 1, senderIp);
    *cur = FIELDS_DELIM;
    cur = encodeUShortField(++cur, senderPort);
    *cur = '\0';

    return std::strlen(outputBuffer);
}

const char* xmessenger::SendFileRequestFwd::decodeBody(
        const char* inputBuffer) {
    const char* cur = SendFileRequest::decodeBody(inputBuffer);
    cur = decodeStringField(cur, senderIp);
    cur = decodeUShortField(cur, senderPort);

    return cur;
}
