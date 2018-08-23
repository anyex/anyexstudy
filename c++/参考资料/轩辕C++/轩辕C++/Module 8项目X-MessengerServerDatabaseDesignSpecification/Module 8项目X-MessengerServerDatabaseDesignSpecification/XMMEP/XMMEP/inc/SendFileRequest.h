/*
 * SendFileRequest.h
 *
 *  Created on: Jan 13, 2011
 *      Author: kwarph
 */

#ifndef SENDFILEREQUEST_H_
#define SENDFILEREQUEST_H_

#include "XMMessage.h"
#include "FileInfo.h"

namespace xmessenger {

enum {
    MSG_SEND_FILE_REQ = 180
};

class SendFileRequest: public XMMessage {
public:
    SendFileRequest();
    SendFileRequest(const std::string& sender, const std::string& receiver,
            const std::string& fileName, const size_t& fileSize,
            const size_t& transferSeq, bool isImage);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

    std::string getSender() const;
    void setSender(const std::string& sender);

    std::string getReceiver() const;
    void setReceiver(const std::string& receiver);

    std::string getFileName() const;
    void setFileName(const std::string& fileName);

    size_t getFileSize() const;
    void setFileSize(const size_t& fileSize);

    size_t getTransferSeq() const;
    void setTransferSeq(const size_t& transferSeq);

    bool isImage() const;
    void setIsImage(bool imageFile);

protected:
    virtual size_t encodeBody(char* outputBuffer) const;
    virtual const char* decodeBody(const char* inputBuffer);

private:
    std::string sender;
    std::string receiver;
    std::string fileName;
    size_t fileSize;
    size_t transferSeq;
    bool imageFile;
};

} // end of namespace xmessenger

#endif /* SENDFILEREQUEST_H_ */
