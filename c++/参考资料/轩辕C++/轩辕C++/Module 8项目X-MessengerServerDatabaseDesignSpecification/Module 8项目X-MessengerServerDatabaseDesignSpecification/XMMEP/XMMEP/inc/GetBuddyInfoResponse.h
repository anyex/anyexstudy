/*
 * GetBuddyInfoResponse.h
 *
 *  Created on: 2010-7-9 下午01:36:34
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#ifndef GETBUDDYINFORESPONSE_H_
#define GETBUDDYINFORESPONSE_H_

#include <string>

#include "XMMessage.h"
#include "ResultCodes.h"
#include "UserInfo.h"

namespace xmessenger {

enum {
    MSG_GET_BUDDY_INFO_RES = 191
};

class GetBuddyInfoResponse: public XMMessage {
public:
    GetBuddyInfoResponse();
    GetBuddyInfoResponse(const std::string& userName, const ResultCode& result,
            const UserInfo& ui);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

    std::string getUserName() const;
    ResultCode getResult() const;
    UserInfo getBuddyInfo() const;

    void setUserName(const std::string& userName);
    void setResult(const ResultCode& result);
    void setBuddyInfo(const UserInfo& userInfo);

protected:
    virtual size_t encodeBody(char* outputBuffer) const;

    virtual const char* decodeBody(const char* inputBuffer);

private:
    std::string userName;
    ResultCode result;
    UserInfo buddyInfo;
};

} // end of namespace xmessenger

#endif /* GETBUDDYINFORESPONSE_H_ */
