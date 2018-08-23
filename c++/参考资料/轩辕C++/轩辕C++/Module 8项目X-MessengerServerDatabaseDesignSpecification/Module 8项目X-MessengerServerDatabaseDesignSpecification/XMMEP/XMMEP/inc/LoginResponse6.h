/*
 * LoginResponse6.h
 *
 *  Created on: Oct 1, 2011
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 */

#ifndef LOGINRESPONSE6_H_
#define LOGINRESPONSE6_H_

#include  <vector>

#include "XMMessage.h"
#include "OnlineBuddy.h"

namespace xmessenger {

enum {
    MSG_LOGIN_RES6 = 118
};

class LoginResponse6: public XMMessage {
public:
    enum {
        MAX_BUDDY_PER_RES = 10
    };

    LoginResponse6();
    LoginResponse6(const short& seqNumber);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

    const std::vector<OnlineBuddy>& getUsers() const;
    std::vector<OnlineBuddy>& getUsers();

    short getSeqNumber() const;
    void setSeqNumber(const short& seqNumber);

protected:
    virtual size_t encodeBody(char* outputBuffer) const;

    virtual const char* decodeBody(const char* inputBuffer);

private:
    short seqNumber;
    std::vector<OnlineBuddy> buddies;

};

} /* namespace xmessenger */

#endif /* LOGINRESPONSE6_H_ */
