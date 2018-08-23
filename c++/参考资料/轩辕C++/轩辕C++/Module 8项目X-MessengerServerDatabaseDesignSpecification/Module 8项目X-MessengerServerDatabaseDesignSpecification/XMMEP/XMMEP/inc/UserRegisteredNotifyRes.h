/*
 * UserRegisteredNotifyRes.h
 *
 *  Created on: Sep 15, 2011
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 */

#ifndef USERREGISTEREDNOTIFYRES_H_
#define USERREGISTEREDNOTIFYRES_H_

#include "XMMessage.h"

namespace xmessenger {

enum {
    MSG_USER_REGISTERED_NOTIFY_RES = 105
};

class UserRegisteredNotifyRes: public XMMessage {
public:
    UserRegisteredNotifyRes();
    UserRegisteredNotifyRes(const std::string& _userName);

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
#endif /* USERREGISTEREDNOTIFYRES_H_ */
