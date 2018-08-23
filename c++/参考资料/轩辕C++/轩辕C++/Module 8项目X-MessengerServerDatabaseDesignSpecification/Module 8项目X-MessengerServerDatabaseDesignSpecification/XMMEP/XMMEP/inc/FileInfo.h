/*
 * FileInfo.h
 *
 *  Created on: Jan 11, 2012 10:26:42 PM
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 *     Website: http://www.xuanyuan-soft.cn
 */

#ifndef FILEINFO_H_
#define FILEINFO_H_

#include <string>

namespace xmessenger {

struct FileInfo {
    size_t fileId; // hash code
    std::string fileName; // full path
    std::string fileType; // MIME type
    size_t fileSize;
    std::string password;
    std::string submittedBy; // contact id
};

char* encodeFileInfoField(char* outBuf, const FileInfo& field);
const char* decodeFileInfoField(const char* inBuf, FileInfo& field);

} /* namespace xmessenger */

#endif /* FILEINFO_H_ */
