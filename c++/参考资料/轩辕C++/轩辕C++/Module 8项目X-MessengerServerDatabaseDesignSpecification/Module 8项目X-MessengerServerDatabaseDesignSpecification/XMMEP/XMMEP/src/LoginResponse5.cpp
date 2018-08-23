/*
 * LoginReponse5.cpp
 *
 *  Created on: Sep 24, 2011
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 */

#include <ostream>

#include "LoginResponse5.h"
#include "MessageUtils.h"

xmessenger::LoginResponse5::LoginResponse5() {

}

xmessenger::LoginResponse5::LoginResponse5(const short& seqNumber) :
        LoginResponseN(seqNumber) {

}

int xmessenger::LoginResponse5::code() const {
    return MSG_LOGIN_RES5;
}

std::ostream& xmessenger::LoginResponse5::output(std::ostream& os) const {
    return LoginResponseN::partialOutput(os, "LoginResponse5", "joined rooms");
}
