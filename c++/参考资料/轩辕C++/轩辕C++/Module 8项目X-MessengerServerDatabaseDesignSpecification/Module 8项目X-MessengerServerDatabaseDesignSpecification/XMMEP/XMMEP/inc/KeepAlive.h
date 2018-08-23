/*
 * KeepAlive.h
 *
 *  Created on: 2010-7-9 下午01:37:13
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#ifndef KEEPALIVE_H_
#define KEEPALIVE_H_

#include "XMMessage.h"

namespace xmessenger {

enum {
    MSG_KEEP_ALIVE = 200
};

class KeepAlive: public XMMessage {
public:
    KeepAlive();
    KeepAlive(const std::string& _userName);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

    std::string getUserName() const;
    void setUserName(const std::string& userName);

protected:
    virtual size_t encodeBody(char* outputBuffer) const;

    virtual const char* decodeBody(const char* inputBuffer);

private:
    std::string userName;
};

} // end of namespace xmessenger

#endif /* KEEPALIVE_H_ */
