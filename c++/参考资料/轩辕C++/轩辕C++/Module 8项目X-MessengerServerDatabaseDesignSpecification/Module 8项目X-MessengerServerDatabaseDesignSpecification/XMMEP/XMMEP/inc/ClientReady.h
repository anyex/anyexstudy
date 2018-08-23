/*
 * ClientReady.h
 *
 *  Created on: 2010-7-19 下午12:28:58
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#ifndef CLIENTISREADY_H_
#define CLIENTISREADY_H_

#include "XMMessage.h"

namespace xmessenger {

enum {
    MSG_CLIENT_READY = 128
};

class ClientReady: public XMMessage {
public:
    ClientReady();
    ClientReady(const std::string& _userName);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

    std::string getUserName() const;
    void setUserName(const std::string& userName);

protected:
    virtual size_t encodeBody(char* outputBuffer) const;

    virtual const char* decodeBody(const char* inputBuffer);

private:
    std::string userName;
};

} // end of namespace xmessenger

#endif /* CLIENTISREADY_H_ */
