/*
 * FileCancelledNotify.h
 *
 *  Created on: Jan 29, 2012 11:41:46 AM
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 *     Website: http://www.xuanyuan-soft.cn
 */

#ifndef FILECANCELLEDNOTIFY_H_
#define FILECANCELLEDNOTIFY_H_

#include "XMMessage.h"

namespace xmessenger {

enum {
    MSG_FILE_CANCELLED_NOTIFY = 812
};

class FileCancelledNotify: public XMMessage {
public:
    FileCancelledNotify();
    FileCancelledNotify(const std::string& sender, const size_t& id);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

    std::string getSender() const;
    void setSender(const std::string& sender);

    size_t getFileId() const;
    void setFileId(const size_t& fileId);

protected:
    virtual size_t encodeBody(char* outputBuffer) const;
    virtual const char* decodeBody(const char* inputBuffer);

private:
    std::string sender;
    size_t fileId;

};

} /* namespace xmessenger */

#endif /* FILECANCELLEDNOTIFY_H_ */
