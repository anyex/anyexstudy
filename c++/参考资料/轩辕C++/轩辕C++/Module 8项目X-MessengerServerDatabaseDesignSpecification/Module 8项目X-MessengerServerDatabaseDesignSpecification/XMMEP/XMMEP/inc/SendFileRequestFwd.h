/*
 * SendFileRequestFwd.h
 *
 *  Created on: Jan 14, 2012 8:50:16 PM
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 *     Website: http://www.xuanyuan-soft.cn
 */

#ifndef SENDFILEREQUESTFWD_H_
#define SENDFILEREQUESTFWD_H_

#include "SendFileRequest.h"
#include "FileInfo.h"

namespace xmessenger {

enum {
    MSG_SEND_FILE_REQ_FWD = 181
};

class SendFileRequestFwd: public SendFileRequest {
public:
    SendFileRequestFwd();
    SendFileRequestFwd(const std::string& sender, const std::string& receiver,
            const std::string& fileName, const size_t& fileSize,
            const size_t& transferSeq, bool isImage, const std::string& senderIp,
            unsigned short senderPort);

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

#endif /* SENDFILEREQUESTFWD_H_ */
