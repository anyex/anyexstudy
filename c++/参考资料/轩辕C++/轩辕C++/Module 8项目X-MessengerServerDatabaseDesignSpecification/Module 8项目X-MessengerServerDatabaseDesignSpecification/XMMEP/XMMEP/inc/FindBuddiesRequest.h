/*
 * FindBuddiesRequest.h
 *
 *  Created on: 2010-7-9 下午03:52:41
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#ifndef FINDBUDDIESREQUEST_H_
#define FINDBUDDIESREQUEST_H_

#include <map>

#include "XMMessage.h"

namespace xmessenger {

enum {
    MSG_FIND_BUDDIES_REQ = 195
};

/**
 * Buddy search conditions
 */
enum SearchCondition {
    SEARCH_COND_NAME = 20,
    SEARCH_COND_NICKNAME = 21,
    SEARCH_COND_EMAIL = 22,
    SEARCH_COND_LOCATION = 23
};

class FindBuddiesRequest: public XMMessage {
public:

    typedef std::map<SearchCondition, std::string> ConditionMap;

    FindBuddiesRequest();
    FindBuddiesRequest(const std::string& _userName);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

    std::string getUserName() const;
    void setUserName(const std::string& userName);

    const ConditionMap& getConditions() const;
    ConditionMap& getConditions();

protected:
    virtual size_t encodeBody(char* outputBuffer) const;

    virtual const char* decodeBody(const char* inputBuffer);

private:
    std::string userName;
    int conditionCount;
    std::map<SearchCondition, std::string> conditions;
};

} // end of namespace xmessenger

#endif /* FINDBUDDIESREQUEST_H_ */
