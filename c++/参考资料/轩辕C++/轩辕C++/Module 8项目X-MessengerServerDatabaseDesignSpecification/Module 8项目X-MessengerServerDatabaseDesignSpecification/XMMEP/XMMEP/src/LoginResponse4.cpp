/*
 * LoginResponse4.cpp
 *
 *  Created on: 2010-7-9 下午12:38:57
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <ostream>
#include "LoginResponse4.h"
#include "MessageUtils.h"

xmessenger::LoginResponse4::LoginResponse4() {

}

xmessenger::LoginResponse4::LoginResponse4(const short& seqNumber) :
        LoginResponseN(seqNumber) {

}

int xmessenger::LoginResponse4::code() const {
    return MSG_LOGIN_RES4;
}

std::ostream& xmessenger::LoginResponse4::output(std::ostream& os) const {
    return LoginResponseN::partialOutput(os, "LoginResponse4", "blocked users");
}
