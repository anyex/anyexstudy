/*
 * UserOnlineNotifyResRes.cpp
 *
 *  Created on: Mar 30, 2011
 *      Author: kwarph
 */

#include "UserOnlineNotifyRes.h"

xmessenger::UserOnlineNotifyRes::UserOnlineNotifyRes() {

}

xmessenger::UserOnlineNotifyRes::UserOnlineNotifyRes(const std::string& name,
        const std::string& nickname, const std::string& avatar,
        const std::string& personalMsg) :
        UserOnlineNotify(name, nickname, avatar, personalMsg) {

}

int xmessenger::UserOnlineNotifyRes::code() const {
    return MSG_USER_ONLINE_NOTIFY_RES;
}

std::ostream& xmessenger::UserOnlineNotifyRes::output(std::ostream& os) const {
    return os << "UserOnlineNotifyRes: " << UserOnlineNotify::output(os);
}
