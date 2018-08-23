/*
 * SendFileResponseFwd.h
 *
 *  Created on: Jan 14, 2012 8:50:43 PM
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 *     Website: http://www.xuanyuan-soft.cn
 */

#ifndef SENDFILERESPONSEFWD_H_
#define SENDFILERESPONSEFWD_H_

#include "SendFileResponse.h"
#include "FileInfo.h"

namespace xmessenger {

enum {
    MSG_SEND_FILE_RES_FWD = 183
};

class SendFileResponseFwd: public SendFileResponse {
public:
    SendFileResponseFwd();
    SendFileResponseFwd(const std::string& sender, const std::string& receiver,
             const size_t& transferSeq, bool result,
            const std::string& senderIp, unsigned short senderPort);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

    std::string getSenderIp() const;
    void setSenderIp(const std::string& senderIp);

    unsigned short getSenderPort() const;
    void setSenderPort(const unsigned short& senderPort);

protected:
    virtual size_t encodeBody(char* outputBuffer) const;
    virtual const char* decodeBody(const char* inputBuffer);

private:
    std::string senderIp;
    unsigned short senderPort;
};

} // end of namespace xmessenger

#endif /* SENDFILERESPONSEFWD_H_ */
