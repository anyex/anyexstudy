/*
 * Presence.h
 *
 *  Created on: Jan 11, 2012 11:55:37 PM
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 *     Website: http://www.xuanyuan-soft.cn
 */

#ifndef PRESENCE_H_
#define PRESENCE_H_

#include <string>

namespace xmessenger {

/**
 * Defines X-Messenger Client user's online status.
 */
enum Presence {
    ONLINE = 0, BUSY, AWAY, OFFLINE
};

const std::string& presenceToString(const Presence& p);

} /* namespace xmessenger */

#endif /* PRESENCE_H_ */
