/*
 * RemoveFromBlacklistNotifyRes.cpp
 *
 *  Created on: 2010-7-9 下午01:35:40
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <ostream>

#include "RemoveFromBlacklistNotifyRes.h"
#include "MessageUtils.h"

xmessenger::RemoveFromBlacklistNotifyRes::RemoveFromBlacklistNotifyRes() {
}

int xmessenger::RemoveFromBlacklistNotifyRes::code() const {
    return MSG_REMOVE_FROM_BLACKLIST_NOTIFY_RES;
}

std::ostream& xmessenger::RemoveFromBlacklistNotifyRes::output(
        std::ostream& os) const {
    os << "RemoveFromBlacklistNotifyRes";

    return os;
}

size_t xmessenger::RemoveFromBlacklistNotifyRes::encodeBody(
        char* outputBuffer) const {
    return 0;
}

const char* xmessenger::RemoveFromBlacklistNotifyRes::decodeBody(
        const char* inputBuffer) {
    return inputBuffer;
}

