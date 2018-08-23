/*
 * FileDownloadRequest.h
 *
 *  Created on: Jan 29, 2012 12:14:04 PM
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 *     Website: http://www.xuanyuan-soft.cn
 */

#ifndef FILEDOWNLOADREQUEST_H_
#define FILEDOWNLOADREQUEST_H_

#include "XMMessage.h"

namespace xmessenger {

enum {
    MSG_FILE_DOWNLOAD_REQ = 811
};

class FileDownloadRequest: public XMMessage {
public:
    FileDownloadRequest();
    FileDownloadRequest(const std::string& sender, const size_t& fileId,
            const size_t& transferId);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

    std::string getSender() const;
    void setSender(const std::string& sender);

    size_t getFileId() const;
    void setFileId(const size_t& fileId);

    size_t getTransferId() const;
    void setTransferId(const size_t& transferId);

protected:
    virtual size_t encodeBody(char* outputBuffer) const;
    virtual const char* decodeBody(const char* inputBuffer);

private:
    std::string sender;
    size_t fileId;
    size_t transferId;

};

} /* namespace xmessenger */

#endif /* FILEDOWNLOADREQUEST_H_ */
