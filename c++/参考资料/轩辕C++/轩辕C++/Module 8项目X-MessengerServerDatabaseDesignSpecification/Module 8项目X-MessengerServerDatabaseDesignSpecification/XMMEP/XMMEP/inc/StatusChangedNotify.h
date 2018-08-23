/*
 * StatusChangedNotify.h
 *
 *  Created on: 2010-7-6 下午04:22:36
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#ifndef STATUSCHANGEDNOTIFY_H_
#define STATUSCHANGEDNOTIFY_H_

#include "XMMessage.h"
#include "Presence.h"

namespace xmessenger {

enum {
    MSG_STATUS_CHANGED_NOTIFY = 135
};

class StatusChangedNotify: public XMMessage {
public:
    StatusChangedNotify();
    StatusChangedNotify(const std::string& _userName, const Presence& _status);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

    Presence getStatus() const;
    std::string getUserName() const;

    void setStatus(const Presence& status);
    void setUserName(const std::string& userName);

protected:
    virtual size_t encodeBody(char* outputBuffer) const;

    virtual const char* decodeBody(const char* inputBuffer);

private:
    std::string userName;
    Presence status;
};

} // end of namespace xmessenger

#endif /* STATUSCHANGEDNOTIFY_H_ */
