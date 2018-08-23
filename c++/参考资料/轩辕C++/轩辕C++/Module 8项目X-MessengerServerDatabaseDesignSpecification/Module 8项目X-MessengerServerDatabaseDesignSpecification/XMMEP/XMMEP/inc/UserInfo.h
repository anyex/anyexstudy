/*
 * UserInfo.h
 *
 *  Created on: Jan 11, 2012 10:16:30 PM
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 *     Website: http://www.xuanyuan-soft.cn
 */

#ifndef USERINFO_H_
#define USERINFO_H_

#include <string>

namespace xmessenger {

struct UserInfo {
    std::string userName;
    std::string nickname;
    std::string personalMsg;
    std::string email;
    std::string avatar; // Avatar picture file name
    std::string location;
    int birthday; // seconds since 1970-01-01 00:00:00
    int lastLoginTime; // seconds since 1970-01-01 00:00:00
    bool gender; // 0 - Female, 1 - Male
};

char* encodeUserInfoField(char* outBuf, const UserInfo& field);

const char* decodeUserInfoField(const char* inBuf, UserInfo& field);

} /* namespace xmessenger */

#endif /* USERINFO_H_ */
