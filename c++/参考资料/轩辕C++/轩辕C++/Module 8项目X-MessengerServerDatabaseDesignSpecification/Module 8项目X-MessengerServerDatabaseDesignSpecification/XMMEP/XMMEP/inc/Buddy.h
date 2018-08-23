/*
 * Buddy.h
 *
 *  Created on: Jan 11, 2012 10:23:03 PM
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 *     Website: http://www.xuanyuan-soft.cn
 */

#ifndef BUDDY_H_
#define BUDDY_H_

#include <string>

namespace xmessenger {

struct Buddy {
    std::string buddyName; // UserId
    std::string groupName;
    std::string displayName;
};

char* encodeBuddyField(char* outBuf, const Buddy& field);
const char* decodeBuddyField(const char* inBuf, Buddy& field);

} /* namespace xmessenger */

#endif /* BUDDY_H_ */
