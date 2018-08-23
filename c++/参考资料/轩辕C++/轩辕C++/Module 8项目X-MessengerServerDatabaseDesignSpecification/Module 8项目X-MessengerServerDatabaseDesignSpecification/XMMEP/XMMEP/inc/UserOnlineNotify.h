/*
 * UserOnlineNotify.h
 *
 *  Created on: Mar 30, 2011
 *      Author: kwarph
 */

#ifndef USERONLINENOTIFY_H_
#define USERONLINENOTIFY_H_

#include "XMMessage.h"

namespace xmessenger {

enum {
    MSG_USER_ONLINE_NOTIFY = 800
};

class UserOnlineNotify: public XMMessage {
public:
    UserOnlineNotify();
    UserOnlineNotify(const std::string& name, const std::string& nickname,
            const std::string& avatar, const std::string& personalMsg);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

    std::string getUserName() const;
    void setUserName(const std::string& name);

    std::string getNickname() const;
    void setNickname(const std::string& nickname);

    std::string getAvatar() const;
    void setAvatar(const std::string& avatar);

    std::string getPersonalMsg() const;
    void setPersonalMsg(const std::string& personalMsg);

protected:
    virtual size_t encodeBody(char* outputBuffer) const;
    virtual const char* decodeBody(const char* inputBuffer);

private:
    std::string userName;
    std::string nickname;
    std::string avatar;
    std::string personalMsg;
};

} // end of namespace xmessenger

#endif /* USERONLINENOTIFY_H_ */
