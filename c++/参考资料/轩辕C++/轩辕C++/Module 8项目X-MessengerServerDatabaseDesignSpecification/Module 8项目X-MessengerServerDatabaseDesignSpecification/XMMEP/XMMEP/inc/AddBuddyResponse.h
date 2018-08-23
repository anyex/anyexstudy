/*
 * AddBuddyResponse.h
 *
 *  Created on: 2010-7-8 下午09:49:44
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#ifndef ADDBUDDYRESPONSE_H_
#define ADDBUDDYRESPONSE_H_

#include "XMMessage.h"
#include "OnlineBuddy.h"

namespace xmessenger {

enum {
    MSG_ADD_BUDDY_RES = 151
};

class AddBuddyResponse: public XMMessage {
public:
    AddBuddyResponse();
    AddBuddyResponse(const std::string& _userName, const bool& _result,
            const OnlineBuddy& _buddy, bool roomMember);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

    std::string getUserName() const;
    bool getResult() const;
    OnlineBuddy getBuddy() const;
    bool isRoomMember() const;

    void setUserName(const std::string& userName);
    void setResult(const bool& result);
    void setBuddy(const OnlineBuddy& buddy);
    void setRoomMember(bool roomMember);

protected:
    virtual size_t encodeBody(char* outputBuffer) const;
    virtual const char* decodeBody(const char* inputBuffer);

private:
    std::string userName;
    bool result;
    OnlineBuddy buddy;
    bool roomMember;

};

} // end of namespace xmessenger

#endif /* ADDBUDDYRESPONSE_H_ */
