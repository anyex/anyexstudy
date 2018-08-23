/*
 * BuddyLoginNotify.h
 *
 *  Created on: 2010-7-20 下午03:48:48
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#ifndef BUDDYLOGINNOTIFY_H_
#define BUDDYLOGINNOTIFY_H_

#include "XMMessage.h"
#include "OnlineBuddy.h"

namespace xmessenger {

enum {
    MSG_BUDDY_LOGIN_NOTIFY = 130
};

class BuddyLoginNotify: public XMMessage {
public:
    BuddyLoginNotify();
    BuddyLoginNotify(const std::string& _receiver, const OnlineBuddy& _buddy);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

    std::string getReceiver() const;
    const OnlineBuddy& getBuddy() const;

    void setReceiver(const std::string& receiver);
    void setBuddy(const OnlineBuddy& buddy);

protected:
    virtual size_t encodeBody(char* outputBuffer) const;

    virtual const char* decodeBody(const char* inputBuffer);

private:
    std::string receiver;
    OnlineBuddy buddy;
};

} // end of namespace xmessenger

#endif /* BUDDYLOGINNOTIFY_H_ */
