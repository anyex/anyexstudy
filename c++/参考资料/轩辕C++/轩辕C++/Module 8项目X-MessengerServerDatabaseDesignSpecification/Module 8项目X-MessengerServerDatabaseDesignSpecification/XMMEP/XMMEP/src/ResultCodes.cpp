/*
 * ResultCodes.cpp
 *
 *  Created on: Jan 11, 2012 10:36:36 PM
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 *     Website: http://www.xuanyuan-soft.cn
 */

#include "ResultCodes.h"

namespace xmessenger {

static const std::string resultStr[RESULT_COUNT] = { // string mapping
        "Success", //  RESULT_SUCCESS = 0,
        "Error", // RESULT_ERROR,
        "Parameters error", // RESULT_PARAM_ERROR,
        "Networking error", // RESULT_NETWORKING_ERROR,
        "Database error", // RESULT_DATABASE_ERROR,
        "Server is busy", // RESULT_SERVER_BUSY,
        "Server is not ready", // RESULT_SERVER_NOT_READY,
        "Login time out", // RESULT_TIME_OUT,
        "No such user", // RESULT_NO_SUCH_USER,
        "User alreay exists", // RESULT_USER_EXISTS,
        "Email in use", // RESULT_MAIL_IN_USE,
        "User alreay exists and email in use", // RESULT_USER_MAIL_EXISTS,
        "Password mismatch", // RESULT_PASSWD_MISMATCH,
        "Activation code mismatch", // RESULT_ACTIVATE_CODE_MISMATCH,
        "User has not been activated", // RESULT_USER_NOT_ACTIVATED,
        "Session expires", // RESULT_EXPIRED_SESSION,
        "Duplicate session" // RESULT_DUPLICATE_SESSION
};

const std::string& resultCodeToString(const ResultCode& r) {
    if (RESULT_COUNT <= r)
        return resultStr[1];

    return resultStr[r];
}

} /* namespace xmessenger */
