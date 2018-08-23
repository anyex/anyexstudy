/*
 * BuddyRemovedNotify.h
 *
 *  Created on: 2010-7-9 下午01:31:39
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#ifndef BUDDYREMOVEDNOTIFY_H_
#define BUDDYREMOVEDNOTIFY_H_

#include "XMMessage.h"

namespace xmessenger {

enum {
    MSG_BUDDY_REMOVED_NOTIFY = 154
};

class BuddyRemovedNotify: public XMMessage {
public:
    BuddyRemovedNotify();
    BuddyRemovedNotify(const std::string& _userName, const std::string& _group,
            const std::string& _buddyName, bool isRoomMember);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

    std::string getGroup() const;
    std::string getBuddyName() const;
    std::string getUserName() const;
    bool isRoomMember() const;

    void setGroup(const std::string& group);
    void setBuddyName(const std::string& buddyName);
    void setUserName(const std::string& userName);
    void setIsRoomMember(bool roomMember);

protected:
    virtual size_t encodeBody(char* outputBuffer) const;
    virtual const char* decodeBody(const char* inputBuffer);

private:
    std::string userName;
    std::string group;
    std::string buddyName;
    bool roomMember;
};

} // end of namespace xmessenger

#endif /* BUDDYREMOVEDNOTIFY_H_ */
