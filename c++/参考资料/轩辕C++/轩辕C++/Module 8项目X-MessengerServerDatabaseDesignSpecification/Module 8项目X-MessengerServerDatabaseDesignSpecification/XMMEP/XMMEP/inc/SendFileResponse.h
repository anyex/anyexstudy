/*
 * SendFileResponse.h
 *
 *  Created on: Apr 5, 2011
 *      Author: kwarph
 */

#ifndef SENDFILERESPONSE_H_
#define SENDFILERESPONSE_H_

#include "XMMessage.h"
#include "FileInfo.h"

namespace xmessenger {

enum {
    MSG_SEND_FILE_RES = 182
};

class SendFileResponse: public XMMessage {
public:
    SendFileResponse();
    SendFileResponse(const std::string& sender, const std::string& receiver,
            const size_t& transferSeq, bool result);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

    std::string getSender() const;
    void setSender(const std::string& sender);

    std::string getReceiver() const;
    void setReceiver(const std::string& receiver);

    size_t getTransferSeq() const;
    void setTransferSeq(const size_t& transferSeq);

    bool getResult() const;
    void setResult(bool result);

protected:
    virtual size_t encodeBody(char* outputBuffer) const;
    virtual const char* decodeBody(const char* inputBuffer);

private:
    std::string sender;
    std::string receiver;
    size_t transferSeq;
    bool result;
};

} // end of namespace xmessenger

#endif /* SENDFILERESPONSE_H_ */
