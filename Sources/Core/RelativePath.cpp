//
//  RelativePath.cpp
//  Core
//
//  Created by Michael Eisel on 3/6/20.
//

#include "RelativePath.hpp"
#include <filesystem>

const char *relativePath2(const char *path, const char *base) {
    auto relative = std::filesystem::relative(path, base);
    char *b = NULL;
    asprintf(&b, "%s/", base);
    auto relative2 = std::filesystem::relative(path, b);
    const char *d = strdup(relative.c_str());
    auto ff = std::filesystem::relative("/Users/meisel/projects/client-ios/libraries/GLUE/include/GLUE/SPTThemeGLUE+TokensType.h", "/Users/meisel/projects/client-ios/libraries/GLUE/include/GLUE/");
    auto fa = std::filesystem::relative("/base/MyFile+Extra.h", "/base/");
    if (strcmp("/Users/meisel/projects/client-ios/libraries/GLUE/include/GLUE/SPTTheme+GLUETokensType.h", path) == 0) {
        printf("");
    }
    return d;
}
