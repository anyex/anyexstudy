/*
 * LoginResponseEnd.h
 *
 *  Created on: 2010-7-19 下午12:28:26
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#ifndef LOGINRESPONSEEND_H_
#define LOGINRESPONSEEND_H_

#include "XMMessage.h"

namespace xmessenger {

enum {
    MSG_LOGIN_RES_END = 127
};

class LoginResponseEnd: public XMMessage {
public:
    LoginResponseEnd();

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

protected:
    virtual size_t encodeBody(char* outputBuffer) const;
    virtual const char* decodeBody(const char* inputBuffer);

};

} // end of namespace xmessenger

#endif /* LOGINRESPONSEEND_H_ */
