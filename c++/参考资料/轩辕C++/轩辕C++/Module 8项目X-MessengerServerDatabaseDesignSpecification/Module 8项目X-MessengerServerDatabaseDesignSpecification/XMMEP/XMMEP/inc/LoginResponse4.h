/*
 * LoginResponse4.h
 *
 *  Created on: 2010-7-9 下午12:38:57
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#ifndef LOGINRESPONSE4_H_
#define LOGINRESPONSE4_H_

#include <string>

#include "LoginResponseN.h"

namespace xmessenger {

enum {
    MSG_LOGIN_RES4 = 116
};

/**
 * @brief Contains blacklist of login user
 *
 */

class LoginResponse4: public LoginResponseN {
public:
    enum {
        // 每次回应（每个消息）发送多少个被阻止的用户名
        MAX_RECORDS_PER_RES = 90
    };

    LoginResponse4();
    LoginResponse4(const short& seqNumber);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

};

} /* namespace xmessenger */

#endif /* LOGINRESPONSE3_H_ */
