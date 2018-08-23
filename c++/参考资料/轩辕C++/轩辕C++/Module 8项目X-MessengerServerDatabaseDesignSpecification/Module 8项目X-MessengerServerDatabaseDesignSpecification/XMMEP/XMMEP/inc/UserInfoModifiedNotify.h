/*
 * UserInfoModifiedNotify.h
 *
 *  Created on: Jan 15, 2012 6:16:53 PM
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 *     Website: http://www.xuanyuan-soft.cn
 */

#ifndef USERINFOMODIFIEDNOTIFY_H_
#define USERINFOMODIFIEDNOTIFY_H_

#include "UserOnlineNotify.h"

namespace xmessenger {

enum {
    MSG_USER_INFO_MODIFIED_NOTIFY = 805
};

class UserInfoModifiedNotify: public UserOnlineNotify {
public:
    UserInfoModifiedNotify();
    UserInfoModifiedNotify(const std::string& name, const std::string& nickname,
            const std::string& avatar, const std::string& personalMsg);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

};

} // end of namespace xmessenger

#endif /* USERINFOMODIFIEDNOTIFY_H_ */
