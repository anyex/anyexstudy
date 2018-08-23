/*
 * BuddiedNotify.cpp
 *
 *  Created on: 2010-7-21 下午05:45:19
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <ostream>
#include <cstring>

#include "BuddiedNotify.h"
#include "MessageUtils.h"

xmessenger::BuddiedNotify::BuddiedNotify() :
        xmessenger::BuddyLoginNotify() {
}

xmessenger::BuddiedNotify::BuddiedNotify(const std::string& _receiver,
        const OnlineBuddy& _buddy) :
        xmessenger::BuddyLoginNotify(_receiver, _buddy) {

}

int xmessenger::BuddiedNotify::code() const {
    return MSG_BUDDIED_NOTIFY;
}

std::ostream& xmessenger::BuddiedNotify::output(std::ostream& os) const {
    os << "BuddiedNotify: " << BuddyLoginNotify::output(os);
    return os;
}
