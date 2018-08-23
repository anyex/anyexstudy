/*
 * BuddyLoginNotifyFwd.h
 *
 *  Created on: Sep 27, 2011
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 */

#ifndef BUDDYLOGINNOTIFYFWD_H_
#define BUDDYLOGINNOTIFYFWD_H_

#include <vector>
#include <string>

#include "XMMessage.h"
#include "OnlineBuddy.h"

namespace xmessenger {

enum {
    MSG_BUDDY_LOGIN_NOTIFY_FWD = 131
};

class BuddyLoginNotifyFwd: public XMMessage {
public:
    enum {
        // 每次回应（每个消息）发送多少个好友信息
        MAX_RECORDS_PER_RES = 70
    };

    BuddyLoginNotifyFwd();

    BuddyLoginNotifyFwd(const OnlineBuddy& loginUser);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

    const OnlineBuddy& getUser() const;
    void setUser(const OnlineBuddy& loginUser);

    const std::vector<std::string>& getReceivers() const;
    std::vector<std::string>& getReceivers();

protected:
    virtual size_t encodeBody(char* outputBuffer) const;

    virtual const char* decodeBody(const char* inputBuffer);

private:
    std::vector<std::string> receivers;
    OnlineBuddy user;
};

} // end of namespace xmessenger

#endif /* BUDDYLOGINNOTIFYFWD_H_ */
