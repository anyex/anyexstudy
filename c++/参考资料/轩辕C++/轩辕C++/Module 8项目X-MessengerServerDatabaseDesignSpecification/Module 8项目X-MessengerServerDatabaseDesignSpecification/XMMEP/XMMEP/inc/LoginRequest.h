/*
 * LoginRequest.h
 *
 *  Created on: 2010-3-23 下午08:45:43
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#ifndef LOGINREQUEST_H_
#define LOGINREQUEST_H_

#include "XMMessage.h"
#include "Presence.h"

namespace xmessenger {

enum {
    MSG_LOGIN_REQ = 112
};

class LoginRequest: public XMMessage {
public:
    LoginRequest();
    LoginRequest(const std::string& _userName, const std::string& _password,
            const Presence& _loginStatus = ONLINE);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

    Presence getLoginStatus() const;
    std::string getPassword() const;
    std::string getUserName() const;

    void setLoginStatus(const Presence& loginStatus);
    void setPassword(const std::string& password);
    void setUserName(const std::string& userName);

protected:
    virtual size_t encodeBody(char* outputBuffer) const;

    virtual const char* decodeBody(const char* inputBuffer);

private:
    std::string userName;
    std::string password;
    Presence loginStatus;
};

} // end of namespace xmessenger

#endif /* LOGINREQUEST_H_ */
