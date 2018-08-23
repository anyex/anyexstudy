/*
 * SendFileResponseFwd.cpp
 *
 *  Created on: Jan 14, 2012 8:50:43 PM
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 *     Website: http://www.xuanyuan-soft.cn
 */

#include <ostream>
#include <cstring>

#include "MessageUtils.h"
#include "SendFileResponseFwd.h"

xmessenger::SendFileResponseFwd::SendFileResponseFwd() {

}

xmessenger::SendFileResponseFwd::SendFileResponseFwd(const std::string& _sender,
        const std::string& _receiver, const size_t& _transferSeq, bool _result,
        const std::string& _senderIp, unsigned short _senderPort) :
        SendFileResponse(_sender, _receiver, _transferSeq, _result), senderIp(
                _senderIp), senderPort(_senderPort) {

}

int xmessenger::SendFileResponseFwd::code() const {
    return MSG_SEND_FILE_RES_FWD;
}

std::ostream& xmessenger::SendFileResponseFwd::output(std::ostream& os) const {
    os << "SendFileResponseFwd: ";
    os << SendFileResponse::output(os);
    os << "], senderIp[" << senderIp;
    os << "], senderPort[" << senderPort << "]";

    return os;
}

std::string xmessenger::SendFileResponseFwd::getSenderIp() const {
    return senderIp;
}

void xmessenger::SendFileResponseFwd::setSenderIp(const std::string& senderIp) {
    this->senderIp = senderIp;
}

unsigned short xmessenger::SendFileResponseFwd::getSenderPort() const {
    return senderPort;
}

void xmessenger::SendFileResponseFwd::setSenderPort(
        const unsigned short& senderPort) {
    this->senderPort = senderPort;
}

size_t xmessenger::SendFileResponseFwd::encodeBody(char* outputBuffer) const {
    size_t len = SendFileResponse::encodeBody(outputBuffer);
    outputBuffer[len] = FIELDS_DELIM;

    char* cur = encodeStringField(outputBuffer + len + 1, senderIp);
    *cur = FIELDS_DELIM;
    cur = encodeUShortField(++cur, senderPort);
    *cur = '\0';

    return std::strlen(outputBuffer);
}

const char* xmessenger::SendFileResponseFwd::decodeBody(
        const char* inputBuffer) {
    const char* cur = SendFileResponse::decodeBody(inputBuffer);
    cur = decodeStringField(cur, senderIp);
    cur = decodeUShortField(cur, senderPort);

    return cur;
}
