/*
 * RegisterInfoUpdateResponse.h
 *
 *  Created on: 2010-7-9 下午10:20:41
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#ifndef REGISTERINFOUPDATERESPONSE_H_
#define REGISTERINFOUPDATERESPONSE_H_

#include "XMMessage.h"

namespace xmessenger {

enum {
    MSG_REGISTER_INFO_UPDATE_RES = 108
};

class RegisterInfoUpdateResponse: public XMMessage {
public:
    RegisterInfoUpdateResponse();

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

protected:
    virtual size_t encodeBody(char* outputBuffer) const;

    virtual const char* decodeBody(const char* inputBuffer);
};

} // end of namespace xmessenger

#endif /* REGISTERINFOUPDATERESPONSE_H_ */
