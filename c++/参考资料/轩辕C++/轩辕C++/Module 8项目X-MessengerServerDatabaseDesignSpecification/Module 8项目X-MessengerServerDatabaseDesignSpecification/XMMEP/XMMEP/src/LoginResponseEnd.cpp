/*
 * LoginResponseEnd.cpp
 *
 *  Created on: 2010-7-19 下午12:28:26
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <ostream>

#include "LoginResponseEnd.h"
#include "MessageUtils.h"

xmessenger::LoginResponseEnd::LoginResponseEnd() {
}

int xmessenger::LoginResponseEnd::code() const {
    return MSG_LOGIN_RES_END;
}

std::ostream& xmessenger::LoginResponseEnd::output(std::ostream& os) const {
    os << "LoginResponseEnd";

    return os;
}

size_t xmessenger::LoginResponseEnd::encodeBody(char* outputBuffer) const {
    return 0;
}

const char* xmessenger::LoginResponseEnd::decodeBody(const char* inputBuffer) {
    return inputBuffer;
}

