/*
 * XMMessageHead.cpp
 *
 *  Created on: Oct 1, 2011
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 */

#include <cstring>
#include <cstdlib>

#include "XMMessageHead.h"

xmessenger::XMMessageHead xmessenger::decodeHeader(const char* inputBuffer) {
    char tmp[5] = "";
    std::strncpy(tmp, inputBuffer, 4);
    XMMessageHead head;
    head.bodyLength = std::atoi(tmp);
    memset(tmp, 0, 5);
    std::strncpy(tmp, inputBuffer + 4, 4);
    head.code = std::atoi(tmp);

    return head;
}
