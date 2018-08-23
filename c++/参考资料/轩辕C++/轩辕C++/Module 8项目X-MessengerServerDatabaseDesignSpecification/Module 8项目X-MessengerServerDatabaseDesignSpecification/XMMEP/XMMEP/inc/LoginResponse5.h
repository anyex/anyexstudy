/*
 * LoginReponse4.h
 *
 *  Created on: Sep 24, 2011
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 */

#ifndef LOGINREPONSE5_H_
#define LOGINREPONSE5_H_

#include <string>

#include "LoginResponseN.h"

namespace xmessenger {

enum {
    MSG_LOGIN_RES5 = 117
};

/**
 * @brief Contains joined chatrooms of login user
 *
 */

class LoginResponse5: public LoginResponseN {
public:
    enum {
        // 每次回应（每个消息）发送多少个聊天室名
        MAX_RECORDS_PER_RES = 40
    };

    LoginResponse5();
    LoginResponse5(const short& seqNumber);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

};

} /* namespace xmessenger */

#endif /* LOGINREPONSE5_H_ */
