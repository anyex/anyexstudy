/*
 * BuddiedNotifyRes.h
 *
 *  Created on: 2010-7-21 下午05:45:51
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#ifndef BUDDIEDNOTIFYRES_H_
#define BUDDIEDNOTIFYRES_H_

#include "XMMessage.h"
#include "OnlineBuddy.h"

namespace xmessenger {

enum {
    MSG_BUDDIED_NOTIFY_RES = 153
};

class BuddiedNotifyRes: public XMMessage {
public:
    BuddiedNotifyRes();
    BuddiedNotifyRes(const std::string& _userName, const OnlineBuddy& _buddy, bool add);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

    std::string getUserName() const;
    OnlineBuddy getBuddy() const;
    bool isAdd() const;

    void setUserName(const std::string& userName);
    void setBuddy(const OnlineBuddy& buddy);
    void setAdd(bool add);

protected:
    virtual size_t encodeBody(char* outputBuffer) const;
    virtual const char* decodeBody(const char* inputBuffer);

private:
    std::string userName;
    OnlineBuddy buddy;
    bool add;

};

} // end of namespace xmessenger

#endif /* BUDDIEDNOTIFYRES_H_ */
