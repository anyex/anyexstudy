/*
 * UserOnlineNotifyRes.h
 *
 *  Created on: Mar 30, 2011
 *      Author: kwarph
 */

#ifndef USERONLINENOTIFYRES_H_
#define USERONLINENOTIFYRES_H_

#include "UserOnlineNotify.h"

namespace xmessenger {

enum {
    MSG_USER_ONLINE_NOTIFY_RES = 801
};

class UserOnlineNotifyRes: public UserOnlineNotify {
public:
public:
    UserOnlineNotifyRes();
    UserOnlineNotifyRes(const std::string& name, const std::string& nickname,
            const std::string& avatar, const std::string& personalMsg);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

};

} // end of namespace xmessenger

#endif /* USERONLINENOTIFYRES_H_ */
