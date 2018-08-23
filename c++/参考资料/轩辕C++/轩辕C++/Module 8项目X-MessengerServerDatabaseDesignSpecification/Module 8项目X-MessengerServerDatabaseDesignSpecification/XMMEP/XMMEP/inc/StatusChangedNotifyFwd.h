/*
 * StatusChangedNotifyFwd.h
 *
 *  Created on: 2010-7-6 下午04:22:36
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#ifndef STATUSCHANGEDNOTIFYFWD_H_
#define STATUSCHANGEDNOTIFYFWD_H_

#include "XMMessage.h"
#include "Presence.h"

namespace xmessenger {

enum {
    MSG_STATUS_CHANGED_NOTIFY_FWD = 136
};

class StatusChangedNotifyFwd: public XMMessage {
public:
    StatusChangedNotifyFwd();
    StatusChangedNotifyFwd(const std::string& _observer,
            const std::string& _userName, const Presence& _status);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

    Presence getStatus() const;
    std::string getUserName() const;
    std::string getObserver() const;

    void setStatus(const Presence& status);
    void setUserName(const std::string& userName);
    void setObserver(const std::string& observer);

protected:
    virtual size_t encodeBody(char* outputBuffer) const;

    virtual const char* decodeBody(const char* inputBuffer);

private:
    std::string observer;
    std::string userName;
    Presence status;
};

} // end of namespace xmessenger

#endif /* STATUSCHANGEDNOTIFYFWD_H_ */
