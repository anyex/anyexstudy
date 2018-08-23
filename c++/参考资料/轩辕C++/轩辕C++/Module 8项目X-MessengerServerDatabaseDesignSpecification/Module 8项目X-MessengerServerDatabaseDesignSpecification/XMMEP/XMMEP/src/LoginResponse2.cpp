/*
 * LoginResponse2.cpp
 *
 *  Created on: Sep 29, 2011
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 */

#include <ostream>
#include "LoginResponse2.h"
#include "MessageUtils.h"

xmessenger::LoginResponse2::LoginResponse2() {

}

xmessenger::LoginResponse2::LoginResponse2(const short& seqNumber) :
        LoginResponseN(seqNumber) {

}

int xmessenger::LoginResponse2::code() const {
    return MSG_LOGIN_RES2;
}

std::ostream& xmessenger::LoginResponse2::output(std::ostream& os) const {
    return LoginResponseN::partialOutput(os, "LoginResponse2", "groups");
}
