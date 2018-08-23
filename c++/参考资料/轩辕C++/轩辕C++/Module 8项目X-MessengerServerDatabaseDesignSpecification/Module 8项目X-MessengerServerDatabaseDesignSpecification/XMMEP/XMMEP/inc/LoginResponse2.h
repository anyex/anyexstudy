/*
 * LoginResponse2.h
 *
 *  Created on: Sep 29, 2011
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 */

#ifndef LOGINRESPONSE2_H_
#define LOGINRESPONSE2_H_

#include <string>

#include "LoginResponseN.h"

namespace xmessenger {

enum {
    MSG_LOGIN_RES2 = 114
};

/**
 * @brief Contains groups of login user
 *
 */
class LoginResponse2: public LoginResponseN {
public:
    enum {
        // 每次回应（每个消息）发送多少个组名
        MAX_RECORDS_PER_RES = 60
    };

    LoginResponse2();
    LoginResponse2(const short& seqNumber);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

};

} /* namespace xmessenger */

#endif /* LOGINRESPONSE2_H_ */
