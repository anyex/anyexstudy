/*
 * GroupRemovedNotify.h
 *
 *  Created on: 2010-7-9 下午01:30:00
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#ifndef GROUPREMOVEDNOTIFY_H_
#define GROUPREMOVEDNOTIFY_H_

#include "XMMessage.h"

namespace xmessenger {

enum {
    MSG_GROUP_REMOVED_NOTIFY = 141
};

class GroupRemovedNotify: public XMMessage {
public:
    GroupRemovedNotify();
    GroupRemovedNotify(const std::string& _userName,
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

#endif /* GROUPREMOVEDNOTIFY_H_ */
