/*
 * GetBuddyInfoRequest.h
 *
 *  Created on: 2010-7-9 下午01:36:22
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#ifndef GETBUDDYINFOREQUEST_H_
#define GETBUDDYINFOREQUEST_H_

#include "XMMessage.h"

namespace xmessenger {

enum {
    MSG_GET_BUDDY_INFO_REQ = 190
};

class GetBuddyInfoRequest: public XMMessage {
public:
    GetBuddyInfoRequest();
    GetBuddyInfoRequest(const std::string& _userName,
            const std::string& _buddyName);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

    std::string getBuddyName() const;
    std::string getUserName() const;

    void setBuddyName(const std::string& buddyName);
    void setUserName(const std::string& userName);

protected:
    virtual size_t encodeBody(char* outputBuffer) const;
    virtual const char* decodeBody(const char* inputBuffer);

private:
    std::string userName;
    std::string buddyName;
};

} // end of namespace xmessenger

#endif /* GETBUDDYINFOREQUEST_H_ */
