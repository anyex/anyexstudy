/*
 * LoginResponse3.h
 *
 *  Created on: 2010-6-4
 *      Author: teacher
 */

#ifndef LOGINRESPONSE3_H_
#define LOGINRESPONSE3_H_

#include <string>
#include <vector>

#include "XMMessage.h"
#include "Buddy.h"

namespace xmessenger {

enum {
    MSG_LOGIN_RES3 = 115
};

/**
 * @brief Contains buddies of login user
 *
 */

class LoginResponse3: public XMMessage {
public:
    enum {
        // 每次回应（每个消息）发送多少个好友信息
        MAX_RECORDS_PER_RES = 20
    };

    LoginResponse3();
    LoginResponse3(const short& seqNumber);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

    short getSeqNumber() const;
    void setSeqNumber(const short& seqNumber);

    const std::vector<Buddy>& getBuddies() const;
    std::vector<Buddy>& getBuddies();

protected:
    virtual size_t encodeBody(char* outputBuffer) const;
    virtual const char* decodeBody(const char* inputBuffer);

private:
    short seqNumber;
    std::vector<Buddy> buddies;

};

} /* namespace xmessenger */

#endif /* LOGINRESPONSE3_H_ */
