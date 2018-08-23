/*
 * SendFileResponse.cpp
 *
 *  Created on: Apr 5, 2011
 *      Author: kwarph
 */

#include <ostream>
#include <cstring>

#include "MessageUtils.h"
#include "SendFileResponse.h"

xmessenger::SendFileResponse::SendFileResponse() {

}

xmessenger::SendFileResponse::SendFileResponse(const std::string& _sender,
        const std::string& _receiver, const size_t& _transferSeq, bool res) :
        sender(_sender), receiver(_receiver), transferSeq(_transferSeq), result(
                res) {

}

int xmessenger::SendFileResponse::code() const {
    return MSG_SEND_FILE_RES;
}

std::ostream& xmessenger::SendFileResponse::output(std::ostream& os) const {
    os << "SendFileResponse: sender[" << sender << "], receiver[" << receiver
            << "], transferSeq[" << transferSeq << "], result[" << result
            << "]";

    return os;
}

std::string xmessenger::SendFileResponse::getSender() const {
    return sender;
}

void xmessenger::SendFileResponse::setSender(const std::string& sender) {
    this->sender = sender;
}

std::string xmessenger::SendFileResponse::getReceiver() const {
    return receiver;
}

void xmessenger::SendFileResponse::setReceiver(const std::string& receiver) {
    this->receiver = receiver;
}

size_t xmessenger::SendFileResponse::getTransferSeq() const {
    return transferSeq;
}

void xmessenger::SendFileResponse::setTransferSeq(const size_t& transferSeq) {
    this->transferSeq = transferSeq;
}

bool xmessenger::SendFileResponse::getResult() const {
    return result;
}

void xmessenger::SendFileResponse::setResult(bool result) {
    this->result = result;
}

size_t xmessenger::SendFileResponse::encodeBody(char* outputBuffer) const {
    char* cur = encodeStringField(outputBuffer, sender);
    *cur = FIELDS_DELIM;
    cur = encodeStringField(++cur, receiver);
    *cur = FIELDS_DELIM;
    cur = encodeUIntField(++cur, transferSeq);
    *cur = FIELDS_DELIM;
    cur = encodeBooleanField(++cur, result);
    *cur = '\0';

    return std::strlen(outputBuffer);
}

const char* xmessenger::SendFileResponse::decodeBody(const char* inputBuffer) {
    const char* cur = decodeStringField(inputBuffer, sender);
    cur = decodeStringField(cur, receiver);
    cur = decodeUIntField(cur, transferSeq);
    cur = decodeBooleanField(cur, result);

    return cur;
}
