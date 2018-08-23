/*
 * GetLoginInfoRequest.h
 *
 *  Created on: 2010-3-31
 *      Author: kwarph
 */

#ifndef GETLOGININFOREQUEST_H_
#define GETLOGININFOREQUEST_H_

#include "XMMessage.h"

namespace xmessenger {

enum {
    MSG_GET_LOGIN_INFO_REQ = 110
};

class GetLoginInfoRequest: public XMMessage {
public:
    GetLoginInfoRequest();
    GetLoginInfoRequest(const std::string& _userName);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

    std::string getUserName() const;
    void setUserName(const std::string& userName);

protected:
    virtual size_t encodeBody(char* outputBuffer) const;

    virtual const char* decodeBody(const char* inputBuffer);

private:
    std::string userName;

};

} // end of namespace xmessenger

#endif /* GETLOGININFOREQUEST_H_ */
