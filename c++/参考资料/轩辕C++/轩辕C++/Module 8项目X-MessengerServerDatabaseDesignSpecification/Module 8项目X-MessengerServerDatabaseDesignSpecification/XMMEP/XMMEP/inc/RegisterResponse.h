/*
 * RegisterResponse.h
 *
 *  Created on: 2010-3-31
 *      Author: kwarph
 */

#ifndef REGISTERRESPONSE_H_
#define REGISTERRESPONSE_H_

#include "XMMessage.h"
#include "ResultCodes.h"

namespace xmessenger {

enum {
    MSG_REGISTER_RES = 101
};

class RegisterResponse: public XMMessage {
public:
    RegisterResponse();
    RegisterResponse(const ResultCode& result);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

    ResultCode getResult() const;
    void setResult(const ResultCode& result);

protected:
    virtual size_t encodeBody(char* outputBuffer) const;

    virtual const char* decodeBody(const char* inputBuffer);

private:
    ResultCode result;
};

} // end of namespace xmessenger

#endif /* REGISTERRESPONSE_H_ */
