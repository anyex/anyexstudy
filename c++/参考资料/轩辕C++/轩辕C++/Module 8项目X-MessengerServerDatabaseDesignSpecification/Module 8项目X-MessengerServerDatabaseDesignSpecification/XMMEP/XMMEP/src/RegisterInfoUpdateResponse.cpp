/*
 * RegisterInfoUpdateResponse.cpp
 *
 *  Created on: 2010-7-9 下午10:20:41
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <ostream>

#include "RegisterInfoUpdateResponse.h"
#include "MessageUtils.h"

xmessenger::RegisterInfoUpdateResponse::RegisterInfoUpdateResponse() {
}

int xmessenger::RegisterInfoUpdateResponse::code() const {
    return MSG_REGISTER_INFO_UPDATE_RES;
}

std::ostream& xmessenger::RegisterInfoUpdateResponse::output(
        std::ostream& os) const {
    os << "RegisterInfoUpdateResponse";

    return os;
}

size_t xmessenger::RegisterInfoUpdateResponse::encodeBody(
        char* outputBuffer) const {
    return 0;
}

const char* xmessenger::RegisterInfoUpdateResponse::decodeBody(
        const char* inputBuffer) {
    return inputBuffer;
}
