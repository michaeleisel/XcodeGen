//
//  RelativePath.cpp
//  XcodeGen
//
//  Created by Michael Eisel on 3/11/20.
//

#include "RelativePath.hpp"
#include <boost/filesystem.hpp>
#include <cstring>

const char *PATRelativePath(const char *baseOrig, const char *pathOrig) {
    if (strcmp("/Users/meisel/projects/client-ios/libraries/GLUE/Resources", baseOrig) == 0) {
        printf("");
    }
    boost::system::error_code code;
    char *base = strdup(baseOrig);
    char *path = strdup(pathOrig);
    for (char *curr = base; *curr; curr++) {
        if (*curr == '+') {
            *curr = '\n';//(char)0x1;
        }
    }
    for (char *curr = path; *curr; curr++) {
        if (*curr == '+') {
            *curr = '\n';//(char)0x1;
        }
    }
    char *out = strdup(boost::filesystem::relative(path, base, code).c_str());
    for (char *curr = out; *curr; curr++) {
        if (*curr == '\n') {
            *curr = '+';//(char)0x1;
        }
    }
    return out;
}
