/*
 * BuddyModifiedNotify.h
 *
 *  Created on: 2010-7-9 下午01:32:50
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#ifndef BUDDYMOVEDTONOTIFY_H_
#define BUDDYMOVEDTONOTIFY_H_

#include "XMMessage.h"

namespace xmessenger {

enum {
    MSG_BUDDY_MODIFIED_NOTIFY = 155
};

class BuddyModifiedNotify: public XMMessage {
public:
    BuddyModifiedNotify();
    BuddyModifiedNotify(const std::string& userName,
            const std::string& buddyName, const std::string& displayName,
            const std::string& groupName, const std::string& newGroup);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

    std::string getGroupName() const;
    std::string getUserName() const;
    std::string getNewGroup() const;
    std::string getBuddyName() const;
    std::string getDisplayName() const;

    void setGroupName(const std::string& groupName);
    void setUserName(const std::string& userName);
    void setNewGroup(const std::string& newGroup);
    void setBuddyName(const std::string& buddyName);
    void setDisplayName(const std::string& displayName);

protected:
    virtual size_t encodeBody(char* outputBuffer) const;
    virtual const char* decodeBody(const char* inputBuffer);

private:
    std::string userName;
    std::string buddyName;
    std::string displayName;
    std::string groupName;
    std::string newGroup;
};

} // end of namespace xmessenger

#endif /* BUDDYMOVEDTONOTIFY_H_ */
