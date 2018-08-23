/*
 * UserInfoModifiedNotify.cpp
 *
 *  Created on: Jan 15, 2012 6:16:54 PM
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 *     Website: http://www.xuanyuan-soft.cn
 */

#include <ostream>

#include "UserInfoModifiedNotify.h"

xmessenger::UserInfoModifiedNotify::UserInfoModifiedNotify() {

}

xmessenger::UserInfoModifiedNotify::UserInfoModifiedNotify(
        const std::string& name, const std::string& nickname,
        const std::string& avatar, const std::string& personalMsg) :
        UserOnlineNotify(name, nickname, avatar, personalMsg) {

}

int xmessenger::UserInfoModifiedNotify::code() const {
    return MSG_USER_INFO_MODIFIED_NOTIFY;
}

std::ostream& xmessenger::UserInfoModifiedNotify::output(
        std::ostream& os) const {
    return os << "UserInfoModifiedNotify: " << UserOnlineNotify::output(os);
}
