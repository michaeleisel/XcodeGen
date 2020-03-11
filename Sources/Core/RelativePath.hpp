//
//  RelativePath.hpp
//  XcodeGen
//
//  Created by Michael Eisel on 3/11/20.
//

#ifndef RelativePath_hpp
#define RelativePath_hpp

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

const char *PATRelativePath(const char *base, const char *path);

#ifdef __cplusplus
}
#endif

#endif /* RelativePath_hpp */
