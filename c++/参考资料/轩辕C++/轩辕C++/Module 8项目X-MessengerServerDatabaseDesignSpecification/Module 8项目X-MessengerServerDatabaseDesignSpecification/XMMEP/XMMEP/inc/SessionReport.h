/*
 * SessionReport.h
 *
 *  Created on: 2010-7-22 下午06:54:01
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#ifndef SESSIONREPORT_H_
#define SESSIONREPORT_H_

#include "XMMessage.h"
#include "ResultCodes.h"

namespace xmessenger {

enum {
    MSG_SESSION_REPORT = 133
};

class SessionReport: public XMMessage {
public:
    SessionReport();
    SessionReport(const ResultCode& sessionStatus);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

    ResultCode getSessionStatus() const;
    void setSessionStatus(const ResultCode& sessionStatus);

protected:
    virtual size_t encodeBody(char* outputBuffer) const;

    virtual const char* decodeBody(const char* inputBuffer);

private:
    ResultCode sessionStatus;
};

} // end of namespace xmessenger

#endif /* SESSIONREPORT_H_ */
