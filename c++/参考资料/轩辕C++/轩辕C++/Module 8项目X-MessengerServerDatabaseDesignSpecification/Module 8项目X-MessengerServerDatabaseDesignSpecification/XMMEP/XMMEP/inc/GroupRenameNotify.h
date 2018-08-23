/*
 * GroupRenameNotify.h
 *
 *  Created on: 2010-7-9 下午01:30:39
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#ifndef GROUPRENAMENOTIFY_H_
#define GROUPRENAMENOTIFY_H_

#include "XMMessage.h"

namespace xmessenger {

enum {
    MSG_GROUP_RENAME_NOTIFY = 142
};

class GroupRenameNotify: public XMMessage {
public:
    GroupRenameNotify();
    GroupRenameNotify(const std::string& _userName,
            const std::string& _groupName, const std::string& _newName);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

    std::string getGroupName() const;
    std::string getUserName() const;
    std::string getNewName() const;

    void setGroupName(const std::string& groupName);
    void setUserName(const std::string& userName);
    void setNewName(const std::string& newName);

protected:
    virtual size_t encodeBody(char* outputBuffer) const;
    virtual const char* decodeBody(const char* inputBuffer);

private:
    std::string userName;
    std::string groupName;
    std::string newName;
};

} // end of namespace xmessenger

#endif /* GROUPRENAMENOTIFY_H_ */
