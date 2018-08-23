/*
 * TextMessage.h
 *
 *  Created on: 2010-4-15 下午09:17:07
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#ifndef TEXTMESSAGE_H_
#define TEXTMESSAGE_H_

#include <string>
#include "XMMessage.h"

namespace xmessenger {

enum {
    MSG_TXT_MSG = 170
};

class TextMessage: public XMMessage {
public:
    TextMessage();

    TextMessage(const std::string& sender, const std::string& receiver,
            const int& sendTime, const std::string& content, bool isRoomMsg =
                    false);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

    std::string getReceiver() const;
    int getSendTime() const;
    std::string getSender() const;
    std::string getContent() const;
    bool isRoomMessage() const;

    void setReceiver(const std::string& receiver);
    void setSendTime(const int& sendTime);
    void setSender(const std::string& sender);
    void setContent(const std::string& content);
    void setIsRoomMessage(bool isRoomMsg);

protected:
    virtual size_t encodeBody(char* outputBuffer) const;

    virtual const char* decodeBody(const char* inputBuffer);

private:
    std::string sender;
    std::string receiver;
    int sendTime;
    std::string content;
    bool isRoomMsg;
};

} // end of namespace xmessenger

#endif /* TEXTMESSAGE_H_ */
