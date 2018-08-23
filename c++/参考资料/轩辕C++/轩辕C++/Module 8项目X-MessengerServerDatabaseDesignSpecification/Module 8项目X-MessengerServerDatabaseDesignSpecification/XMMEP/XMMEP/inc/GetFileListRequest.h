/*
 * GetFileListRequest.h
 *
 *  Created on: May 30, 2011
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 */

#ifndef GETFILELISTREQUEST_H_
#define GETFILELISTREQUEST_H_

#include "XMMessage.h"

namespace xmessenger {

enum {
    MSG_GET_FILE_LIST_REQ = 815
};

class GetFileListRequest: public XMMessage {
public:
    GetFileListRequest();
    GetFileListRequest(const std::string& name);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

    std::string getUserName() const;
    void setUserName(const std::string& name);

protected:
    virtual size_t encodeBody(char* outputBuffer) const;
    virtual const char* decodeBody(const char* inputBuffer);

private:
    std::string userName;

};

} // end of namespace xmessenger

#endif /* GETFILELISTREQUEST_H_ */
