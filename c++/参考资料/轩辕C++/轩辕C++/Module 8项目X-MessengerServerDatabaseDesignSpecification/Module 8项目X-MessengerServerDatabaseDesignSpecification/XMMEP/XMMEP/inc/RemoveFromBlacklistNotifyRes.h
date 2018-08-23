/*
 * RemoveFromBlacklistNotifyRes.h
 *
 *  Created on: 2010-7-9 下午01:35:40
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#ifndef REMOVEFROMBLACKLISTNOTIFYRES_H_
#define REMOVEFROMBLACKLISTNOTIFYRES_H_

#include "XMMessage.h"

namespace xmessenger {

enum {
    MSG_REMOVE_FROM_BLACKLIST_NOTIFY_RES = 150
};

class RemoveFromBlacklistNotifyRes: public XMMessage {
public:
    RemoveFromBlacklistNotifyRes();

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

protected:
    virtual size_t encodeBody(char* outputBuffer) const;

    virtual const char* decodeBody(const char* inputBuffer);
};

} // end of namespace xmessenger

#endif /* REMOVEFROMBLACKLISTNOTIFYRES_H_ */
