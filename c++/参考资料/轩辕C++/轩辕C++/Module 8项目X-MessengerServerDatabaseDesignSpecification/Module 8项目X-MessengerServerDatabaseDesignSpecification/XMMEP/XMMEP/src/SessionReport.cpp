/*
 * SessionReport.cpp
 *
 *  Created on: 2010-7-22 下午06:54:01
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <ostream>
#include <cstring>

#include "SessionReport.h"
#include "MessageUtils.h"

xmessenger::SessionReport::SessionReport() {

}

xmessenger::SessionReport::SessionReport(const ResultCode& _sessionStatus) :
        sessionStatus(_sessionStatus) {
}

int xmessenger::SessionReport::code() const {
    return MSG_SESSION_REPORT;
}

std::ostream& xmessenger::SessionReport::output(std::ostream& os) const {
    os << "SessionReport: sessionStatus[" << sessionStatus << "]";

    return os;
}

xmessenger::ResultCode xmessenger::SessionReport::getSessionStatus() const {
    return sessionStatus;
}

void xmessenger::SessionReport::setSessionStatus(
        const ResultCode& sessionStatus) {
    this->sessionStatus = sessionStatus;
}

size_t xmessenger::SessionReport::encodeBody(char* outputBuffer) const {
    char* cur = encodeIntField(outputBuffer, sessionStatus);
    *cur = '\0';

    return std::strlen(outputBuffer);
}

const char* xmessenger::SessionReport::decodeBody(const char* inputBuffer) {
    int status;
    const char* cur = decodeIntField(inputBuffer, status);
    sessionStatus = ResultCode(status);

    return cur;
}

