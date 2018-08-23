/*
 * XMMessageHead.h
 *
 *  Created on: Jan 12, 2012 12:46:27 AM
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 *     Website: http://www.xuanyuan-soft.cn
 */

#ifndef XMMESSAGEHEAD_H_
#define XMMESSAGEHEAD_H_

namespace xmessenger {

enum {
    HEAD_LENGTH = 8, MAX_MSG_SIZE = 1450
};

struct XMMessageHead {
    size_t bodyLength;
    int code;
};

/**
 * @brief Get XMMessage head from a byte array.
 * @param inputBuffer Byte array where XMMessage get from.
 *
 */
XMMessageHead decodeHeader(const char* inputBuffer);

} /* namespace xmessenger */

#endif /* XMMESSAGEHEAD_H_ */
