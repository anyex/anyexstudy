/*
 * ResultCodes.h
 *
 *  Created on: Jan 11, 2012 10:36:36 PM
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 *     Website: http://www.xuanyuan-soft.cn
 */

#ifndef RESULTCODES_H_
#define RESULTCODES_H_

#include <string>

namespace xmessenger {

enum ResultCode {
    RESULT_SUCCESS = 0,
    RESULT_ERROR,
    RESULT_PARAM_ERROR,
    RESULT_NETWORKING_ERROR,
    RESULT_DATABASE_ERROR,
    RESULT_SERVER_BUSY,
    RESULT_SERVER_NOT_READY,
    RESULT_TIME_OUT,
    RESULT_NO_SUCH_USER,
    RESULT_USER_EXISTS,
    RESULT_MAIL_IN_USE,
    RESULT_USER_MAIL_EXISTS,
    RESULT_PASSWD_MISMATCH,
    RESULT_ACTIVATE_CODE_MISMATCH,
    RESULT_USER_NOT_ACTIVATED,
    RESULT_EXPIRED_SESSION,
    RESULT_DUPLICATE_SESSION,
    RESULT_COUNT // count of enum ResultCode items, not a result
};

const std::string& resultCodeToString(const ResultCode& r);

} /* namespace xmessenger */

#endif /* RESULTCODES_H_ */
