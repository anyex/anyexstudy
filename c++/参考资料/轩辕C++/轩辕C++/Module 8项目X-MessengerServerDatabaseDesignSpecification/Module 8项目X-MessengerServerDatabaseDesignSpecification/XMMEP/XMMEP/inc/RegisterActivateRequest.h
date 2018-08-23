/*
 * RegisterActivateRequest.h
 *
 *  Created on: 2010-3-31
 *      Author: kwarph
 */

#ifndef REGISTERACTIVATEREQUEST_H_
#define REGISTERACTIVATEREQUEST_H_

#include "XMMessage.h"

namespace xmessenger {

enum {
    MSG_REGISTER_ACTIVATE_REQ = 102
};

class RegisterActivateRequest: public XMMessage {
public:
    RegisterActivateRequest();
    RegisterActivateRequest(const std::string& userName,
            const std::string& activateCode);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

    //get set functions with class private members.
    std::string getUserName() const;
    std::string getActivateCode() const;

    void setUserName(const std::string& userName);
    void setActivateCode(const std::string& activateCode);

protected:
    virtual size_t encodeBody(char* outputBuffer) const;

    virtual const char* decodeBody(const char* inputBuffer);

private:
    std::string userName;
    std::string activateCode;
};

} // end of namespace xmessenger

#endif /* REGISTERACTIVATEREQUEST_H_ */
