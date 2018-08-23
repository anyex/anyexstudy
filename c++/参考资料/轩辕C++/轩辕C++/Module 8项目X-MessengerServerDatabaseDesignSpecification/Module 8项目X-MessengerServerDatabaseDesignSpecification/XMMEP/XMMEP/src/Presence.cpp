/*
 * Presence.cpp
 *
 *  Created on: Jan 11, 2012 11:55:37 PM
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 *     Website: http://www.xuanyuan-soft.cn
 */

#include "Presence.h"

namespace xmessenger {

static const std::string presenceStrs[] = { //
        "Available", //
        "Busy", //
        "Away", //
        "Offline" //
};

const std::string& presenceToString(const Presence& p) {
    return presenceStrs[p];
}

} /* namespace xmessenger */
