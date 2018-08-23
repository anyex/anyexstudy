/*
 * XMMessage.h
 *
 *  Created on: 2010-3-23 下午04:42:38
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#ifndef XMMESSAGE_H_
#define XMMESSAGE_H_

#include <ostream>
#include <string>

namespace xmessenger {

/**
 * Base class of all XMMEP Messages.
 */
class XMMessage {
public:
    virtual ~XMMessage(); // virtual destructor.

    /**
     * @brief Serializes  XMMessage to a byte array.
     * @param outputBuffer Byte array where XMMessage put to.
     *
     * @return Message length
     */
    size_t encode(char* outputBuffer) const;

    /**
     * @brief Get XMMessage from a byte array.
     * @param inputBuffer Byte array where XMMessage get from.
     *
     * @return true if decode operation success, false otherwise.
     */
    bool decode(const char* inputBuffer);

    /**
     * @brief Get XMMessage type.
     */
    virtual int code() const = 0;

    /**
     * @brief Put XMMessage content to output stream.
     */
    virtual std::ostream& output(std::ostream& os) const = 0;

    std::string toString() const;

protected:
    virtual size_t encodeBody(char* outputBuffer) const = 0;

    virtual const char* decodeBody(const char* inputBuffer) = 0;

};

std::ostream& operator<<(std::ostream& os, const XMMessage& msg);

} // end of namespace xmessenger

#endif /* XMMESSAGE_H_ */
