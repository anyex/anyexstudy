/*
 * GetFileListRequest.cpp
 *
 *  Created on: May 30, 2011
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 */

#include <ostream>
#include <cstring>

#include "MessageUtils.h"
#include "GetFileListRequest.h"

xmessenger::GetFileListRequest::GetFileListRequest() {

}

xmessenger::GetFileListRequest::GetFileListRequest(const std::string& name) :
        userName(name) {

}

int xmessenger::GetFileListRequest::code() const {
    return MSG_GET_FILE_LIST_REQ;
}

std::ostream& xmessenger::GetFileListRequest::output(std::ostream& os) const {
    return os << "GetFileListRequest: userName[" << userName << "]";
}

std::string xmessenger::GetFileListRequest::getUserName() const {
    return userName;
}

void xmessenger::GetFileListRequest::setUserName(const std::string& name) {
    userName = name;
}

size_t xmessenger::GetFileListRequest::encodeBody(char* outputBuffer) const {
    char* cur = encodeStringField(outputBuffer, userName);
    *cur = '\0';
    return std::strlen(outputBuffer);
}

const char* xmessenger::GetFileListRequest::decodeBody(
        const char* inputBuffer) {
    return decodeStringField(inputBuffer, userName);
}
