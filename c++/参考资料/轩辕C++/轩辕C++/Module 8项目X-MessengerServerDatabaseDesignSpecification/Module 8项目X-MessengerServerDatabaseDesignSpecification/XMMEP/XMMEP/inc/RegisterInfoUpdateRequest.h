/*
 * RegisterInfoUpdateRequest.h
 *
 *  Created on: 2010-7-9 下午10:20:24
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#ifndef REGISTERINFOUPDATEREQUEST_H_
#define REGISTERINFOUPDATEREQUEST_H_

#include <string>

#include "XMMessage.h"
#include "UserInfo.h"

namespace xmessenger {

enum {
    MSG_REGISTER_INFO_UPDATE_REQ = 120
};

class RegisterInfoUpdateRequest: public XMMessage {
public:
    RegisterInfoUpdateRequest();
    RegisterInfoUpdateRequest(const std::string& userName, const UserInfo& ui,
            const std::string& passwd);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

    std::string getUserName() const;
    UserInfo getUserInfo() const;
    std::string getPassword() const;

    void setUserName(const std::string& userName);
    void setUserInfo(const UserInfo& userInfo);
    void setPassword(const std::string& passwd);

protected:
    virtual size_t encodeBody(char* outputBuffer) const;

    virtual const char* decodeBody(const char* inputBuffer);

private:
    std::string userName;
    UserInfo userInfo;
    std::string password;
};

} // end of namespace xmessenger

#endif /* REGISTERINFOUPDATEREQUEST_H_ */
