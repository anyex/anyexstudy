/*
 * FindBuddiesResponse.h
 *
 *  Created on: 2010-7-9 下午03:52:53
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#ifndef FINDBUDDIESRESPONSE_H_
#define FINDBUDDIESRESPONSE_H_

#include <vector>
#include <string>

#include "XMMessage.h"
#include "UserInfo.h"

namespace xmessenger {

enum {
    MSG_FIND_BUDDIES_RES = 196
};

class FindBuddiesResponse: public XMMessage {
public:
    enum {
        MAX_USER_PER_RES = 8
    };

    FindBuddiesResponse();
    FindBuddiesResponse(const short& seqNumber);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

    const std::vector<UserInfo>& getUsers() const;
    std::vector<UserInfo>& getUsers();

    short getSeqNumber() const;

    void setSeqNumber(const short& seqNumber);

protected:
    virtual size_t encodeBody(char* outputBuffer) const;

    virtual const char* decodeBody(const char* inputBuffer);

private:
    short seqNumber;
    std::vector<UserInfo> users;
};

} // end of namespace xmessenger

#endif /* FINDBUDDIESRESPONSE_H_ */
