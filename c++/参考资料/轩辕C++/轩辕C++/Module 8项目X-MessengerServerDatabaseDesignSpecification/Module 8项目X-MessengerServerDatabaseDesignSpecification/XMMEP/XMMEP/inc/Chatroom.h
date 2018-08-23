/*
 * Chatroom.h
 *
 *  Created on: Jan 11, 2012 10:19:43 PM
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 *     Website: http://www.xuanyuan-soft.cn
 */

#ifndef CHATROOM_H_
#define CHATROOM_H_

#include <string>

namespace xmessenger {

struct Chatroom {
    std::string roomName;
    std::string creator;
    std::string announce;
};

char* encodeChatroomField(char* outBuf, Chatroom& field);
const char* decodeChatroomField(const char* inBuf, Chatroom& field);

} /* namespace xmessenger */

#endif /* CHATROOM_H_ */
