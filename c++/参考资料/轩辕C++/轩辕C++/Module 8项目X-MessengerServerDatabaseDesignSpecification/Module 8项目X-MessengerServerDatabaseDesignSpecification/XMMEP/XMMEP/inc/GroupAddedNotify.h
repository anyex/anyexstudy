/*
 * GroupAddedNotify.h
 *
 *  Created on: 2010-7-9 下午01:29:11
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#ifndef GROUPADDEDNOTIFY_H_
#define GROUPADDEDNOTIFY_H_

#include "XMMessage.h"

namespace xmessenger {

enum {
    MSG_GROUP_ADDED_NOTIFY = 140
};

class GroupAddedNotify: public XMMessage {
public:
    GroupAddedNotify();
    GroupAddedNotify(const std::string& _userName,
            const std::string& _groupName);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

    std::string getGroupName() const;
    std::string getUserName() const;

    void setGroupName(const std::string& groupName);
    void setUserName(const std::string& userName);

protected:
    virtual size_t encodeBody(char* outputBuffer) const;
    virtual const char* decodeBody(const char* inputBuffer);

private:
    std::string userName;
    std::string groupName;
};

} // end of namespace xmessenger

#endif /* GROUPADDEDNOTIFY_H_ */
