/*
 * XMMessage.cpp
 *
 *  Created on: 2010-3-23 下午04:42:38
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <sstream>
#include <cstdio>

#include "XMMessage.h"
#include "XMMessageHead.h"

xmessenger::XMMessage::~XMMessage() {
}

size_t xmessenger::XMMessage::encode(char* outputBuffer) const {
    // Step1: encode body first
    size_t bodyLength = encodeBody(outputBuffer + HEAD_LENGTH);
    char c = outputBuffer[HEAD_LENGTH];

    // Step2: encode header
    std::sprintf(outputBuffer, "%4d%4d", bodyLength, code());
    outputBuffer[HEAD_LENGTH] = c;
    outputBuffer[bodyLength + HEAD_LENGTH] = '\0';
    return bodyLength + HEAD_LENGTH;
}

bool xmessenger::XMMessage::decode(const char* inputBuffer) {
    decodeBody(inputBuffer + HEAD_LENGTH);
    return true;
}

std::ostream& xmessenger::operator<<(std::ostream& os,
        const xmessenger::XMMessage& msg) {
    return msg.output(os);
}

std::string xmessenger::XMMessage::toString() const {
    std::ostringstream os;
    output(os);
    return os.str();
}
