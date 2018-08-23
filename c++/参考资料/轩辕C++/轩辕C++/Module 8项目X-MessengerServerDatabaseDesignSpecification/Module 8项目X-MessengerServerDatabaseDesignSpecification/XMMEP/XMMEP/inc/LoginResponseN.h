/*
 * LoginResponseN.h
 *
 *  Created on: Sep 29, 2011
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 */

#ifndef LOGINRESPONSEN_H_
#define LOGINRESPONSEN_H_

#include <string>
#include <vector>

#include "XMMessage.h"

namespace xmessenger {

class LoginResponseN: public XMMessage {
public:
    LoginResponseN();
    LoginResponseN(const short& seqNumber);

    virtual ~LoginResponseN();

    short getSeqNumber() const;
    void setSeqNumber(const short& seqNumber);

    const std::vector<std::string>& getItems() const;
    std::vector<std::string>& getItems();

protected:
    std::ostream& partialOutput(std::ostream& os, const std::string& msgName,
            const std::string& itemName) const;

    virtual size_t encodeBody(char* outputBuffer) const;

    virtual const char* decodeBody(const char* inputBuffer);

private:
    short seqNumber;
    std::vector<std::string> items;
};

} /* namespace xmessenger */
#endif /* LOGINRESPONSEN_H_ */
