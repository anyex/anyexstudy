/*
 * AddBuddyRequest.h
 *
 *  Created on: 2010-7-8 下午09:49:44
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#ifndef ADDBUDDYREQUEST_H_
#define ADDBUDDYREQUEST_H_

#include "XMMessage.h"
#include "Buddy.h"

namespace xmessenger {

enum {
    MSG_ADD_BUDDY_REQ = 150
};

class AddBuddyRequest: public XMMessage {
public:
    AddBuddyRequest();
    AddBuddyRequest(const std::string& _userName, const Buddy& _buddy,
            bool roomMember);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

    std::string getUserName() const;
    Buddy getBuddy() const;

    void setUserName(const std::string& userName);
    void setBuddy(const Buddy& buddy);

    bool isRoomMember() const;
    void setRoomMember(bool roomMember);

protected:
    virtual size_t encodeBody(char* outputBuffer) const;
    virtual const char* decodeBody(const char* inputBuffer);

private:
    std::string userName;
    Buddy buddy;
    bool roomMember;
};

} // end of namespace xmessenger

#endif /* ADDBUDDYREQUEST_H_ */
