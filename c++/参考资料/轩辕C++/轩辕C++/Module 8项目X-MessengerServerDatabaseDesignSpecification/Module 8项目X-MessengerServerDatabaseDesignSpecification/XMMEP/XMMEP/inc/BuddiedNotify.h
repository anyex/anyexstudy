/*
 * BuddiedNotify.h
 *
 *  Created on: 2010-7-21 下午05:45:19
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#ifndef BUDDIEDNOTIFY_H_
#define BUDDIEDNOTIFY_H_

#include "BuddyLoginNotify.h"

namespace xmessenger {

enum {
    MSG_BUDDIED_NOTIFY = 152
};

class BuddiedNotify: public BuddyLoginNotify {
public:
    BuddiedNotify();
    BuddiedNotify(const std::string& _receiver, const OnlineBuddy& _buddy);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

};

} // end of namespace xmessenger

#endif /* BUDDIEDNOTIFY_H_ */
