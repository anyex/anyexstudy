/*
 * BuddyUnblockedNotify.h
 *
 *  Created on: 2010-7-9 下午01:35:28
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#ifndef BUDDYUNBLOCKEDNOTIFY_H_
#define BUDDYUNBLOCKEDNOTIFY_H_

#include "XMMessage.h"

namespace xmessenger {

enum {
    MSG_BUDDY_UNBLOCKED_NOTIFY = 157
};

class BuddyUnblockedNotify: public XMMessage {
public:
    BuddyUnblockedNotify();
    BuddyUnblockedNotify(const std::string& _userName,
            const std::string& _buddyName, const std::string& _group);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

    std::string getBuddyName() const;
    std::string getUserName() const;
    std::string getGroup() const;

    void setBuddyName(const std::string& buddyName);
    void setUserName(const std::string& userName);
    void setGroup(const std::string& group);

protected:
    virtual size_t encodeBody(char* outputBuffer) const;
    virtual const char* decodeBody(const char* inputBuffer);

private:
    std::string userName;
    std::string buddyName;
    std::string group;
};

} // end of namespace xmessenger

#endif /* BUDDYUNBLOCKEDNOTIFY_H_ */
