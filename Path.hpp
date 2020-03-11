//
//  Path.hpp
//  PathKit
//
//  Created by Michael Eisel on 3/10/20.
//

#import <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

void PATFreePathComponents(const char **components, void *temp);
const char **PATPathComponents(const char *path, size_t *count, void **temp);

#ifdef __cplusplus
}
#endif
