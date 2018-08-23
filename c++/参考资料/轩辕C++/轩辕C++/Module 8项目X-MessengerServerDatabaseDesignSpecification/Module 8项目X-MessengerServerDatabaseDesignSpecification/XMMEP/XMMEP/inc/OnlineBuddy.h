/*
 * OnlineBuddy.h
 *
 *  Created on: Jan 11, 2012 10:25:01 PM
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 *     Website: http://www.xuanyuan-soft.cn
 */

#ifndef ONLINEBUDDY_H_
#define ONLINEBUDDY_H_

#include <string>
#include "Presence.h"

namespace xmessenger {

struct OnlineBuddy {
    std::string buddyName; // UserId
    std::string groupName;
    std::string displayName;
    std::string personalMsg;
    std::string avatar;
    std::string ip;
    unsigned short port;
    Presence status;
};

char* encodeOnlineBuddyField(char* outBuf, const OnlineBuddy& field);
const char* decodeOnlineBuddyField(const char* inBuf, OnlineBuddy& field);

} /* namespace xmessenger */

#endif /* ONLINEBUDDY_H_ */
