/*
 * UserRegisteredNotify.h
 *
 *  Created on: Sep 15, 2011
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 */

#ifndef USERREGISTEREDNOTIFY_H_
#define USERREGISTEREDNOTIFY_H_

#include "XMMessage.h"

namespace xmessenger {

enum {
    MSG_USER_REGISTERED_NOTIFY = 104
};

class UserRegisteredNotify: public XMMessage {
public:
    //default constructor
    UserRegisteredNotify();
    UserRegisteredNotify(const std::string& _userName,
            const std::string& _password, const std::string& _email,
            const std::string& _nickname = "", const std::string& _personalMsg =
                    "", const std::string& _birthdate = "",
            const std::string& _location = "", bool _gender = true);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

    //get set functions with class private members.
    std::string getUserName() const;
    std::string getPassword() const;
    std::string getEmail() const;
    std::string getBirthdate() const;
    std::string getLocation() const;
    std::string getNickname() const;
    std::string getPersonalMsg() const;
    bool getGender() const;

    void setUserName(const std::string& userName);
    void setPassword(const std::string& password);
    void setEmail(const std::string& email);
    void setBirthdate(const std::string& birthdate);
    void setGender(bool gender);
    void setLocation(const std::string& location);
    void setNickname(const std::string& nickname);
    void setPersonalMsg(const std::string& personal_msg);

protected:
    virtual size_t encodeBody(char* outputBuffer) const;

    virtual const char* decodeBody(const char* inputBuffer);

private:
    std::string userName;
    std::string password;
    std::string email;
    std::string nickname;
    std::string personalMsg;
    std::string birthdate;
    std::string location;
    bool gender;

};

} // end of namespace xmessenger

#endif /* USERREGISTEREDNOTIFY_H_ */
