/*
 * FileSubmittedNotify.h
 *
 *  Created on: May 30, 2011
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 */

#ifndef FILESUBMITTEDNOTIFY_H_
#define FILESUBMITTEDNOTIFY_H_

#include <vector>

#include "FileInfo.h"
#include "XMMessage.h"

namespace xmessenger {

enum {
    MSG_FILE_SUBMITTED_NOTIFY = 810
};

class FileSubmittedNotify: public XMMessage {
public:
    enum {
        FILES_PER_MSG = 5
    };

    FileSubmittedNotify();

    FileSubmittedNotify(const std::string& sender);

    virtual int code() const;
    virtual std::ostream& output(std::ostream& os) const;

    void addFileInfo(const FileInfo& info);
    const std::vector<FileInfo>& getFileInfos() const;

    std::string getSender() const;
    void setSender(const std::string& sender);

protected:
    virtual size_t encodeBody(char* outputBuffer) const;
    virtual const char* decodeBody(const char* inputBuffer);

private:
    std::string sender;
    std::vector<FileInfo> files;
};

} // end of namespace xmessenger

#endif /* FILESUBMITTEDNOTIFY_H_ */
