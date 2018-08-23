/*
 * GetLoginInfoResponse.h
 *
 *  Created on: 2010-3-31
 *      Author: kwarph
 */

#ifndef GETLOGININFORESPONSE_H_
#define GETLOGININFORESPONSE_H_

#include "XMMessage.h"
#include "ResultCodes.h"

namespace xmessenger {

enum {
    MSG_GET_LOGIN_INFO_RES = 111
};

class GetLoginInfoResponse: public XMMessage {
public:
    GetLoginInfoResponse();
    GetLoginInfoResponse(const ResultCode& result, const std::string& serverIp,
            const short& serverPort);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

    ResultCode getResult() const;
    std::string getServerIp() const;
    short getServerPort() const;

    void setResult(const ResultCode& result);
    void setServerIp(const std::string& serverIp);
    void setServerPort(const short& serverPort);

protected:
    virtual size_t encodeBody(char* outputBuffer) const;

    virtual const char* decodeBody(const char* inputBuffer);

private:
    ResultCode result;
    std::string serverIp;
    short serverPort;
};

} // end of namespace xmessenger

#endif /* GETLOGININFORESPONSE_H_ */
