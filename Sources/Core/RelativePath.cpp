//
//  RelativePath.cpp
//  Core
//
//  Created by Michael Eisel on 3/6/20.
//

#include "RelativePath.hpp"
#include <filesystem>

const char *relativePath(const char *path, const char *base) {
    auto relative = std::filesystem::relative(path, base);
    return strdup(relative.c_str());
}
