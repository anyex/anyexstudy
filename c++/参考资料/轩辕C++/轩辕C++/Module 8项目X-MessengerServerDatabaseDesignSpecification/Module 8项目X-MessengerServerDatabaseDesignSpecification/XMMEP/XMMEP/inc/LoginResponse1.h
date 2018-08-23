/*
 * LoginResponse1.h
 *
 *  Created on: 2010-6-4
 *      Author: teacher
 */

#ifndef LOGINRESPONSE1_H_
#define LOGINRESPONSE1_H_

#include <string>

#include "XMMessage.h"
#include "ResultCodes.h"
#include "UserInfo.h"

namespace xmessenger {

enum {
    MSG_LOGIN_RES1 = 113
};

/**
 * @brief Contains UserInfo of login user
 *
 */

class LoginResponse1: public XMMessage {
public:
    LoginResponse1();
    LoginResponse1(const ResultCode& result, const UserInfo& ui);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

    ResultCode getResult() const;
    const UserInfo& getUserInfo() const;

    void setResult(const ResultCode& result);
    void setUserInfo(const UserInfo& userInfo);

protected:
    virtual size_t encodeBody(char* outputBuffer) const;

    virtual const char* decodeBody(const char* inputBuffer);

private:
    ResultCode result;
    UserInfo userInfo;
};

} // end of namespace xmessenger

#endif /* LOGINRESPONSE1_H_ */
