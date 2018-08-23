/*
 * FileDownloadResponse.h
 *
 *  Created on: Jan 29, 2012 3:14:18 PM
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 *     Website: http://www.xuanyuan-soft.cn
 */

#ifndef FILEDOWNLOADRESPONSE_H_
#define FILEDOWNLOADRESPONSE_H_

#include "XMMessage.h"

namespace xmessenger {

enum {
    MSG_FILE_DOWNLOAD_RES = 812
};

class FileDownloadResponse: public XMMessage {
public:
    FileDownloadResponse();
    FileDownloadResponse(const std::string& sender,
            const size_t& transferId);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

    std::string getSender() const;
    void setSender(const std::string& sender);

    size_t getTransferId() const;
    void setTransferId(const size_t& transferId);

protected:
    virtual size_t encodeBody(char* outputBuffer) const;
    virtual const char* decodeBody(const char* inputBuffer);

private:
    std::string sender;
    size_t transferId;

};

} /* namespace xmessenger */
#endif /* FILEDOWNLOADRESPONSE_H_ */
