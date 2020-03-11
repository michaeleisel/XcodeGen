//
//  Path.cpp
//  PathKit
//
//  Created by Michael Eisel on 3/10/20.
//

#include "Path.hpp"
#include <cstring>
#include <vector>
#include <string>

using namespace std;

void PATFreePathComponents(const char **components, void *temp) {
    delete components;
    vector<string> *array = (vector<string> *)temp;
    delete array;
}

const char **PATPathComponents(const char *path, size_t *count, void **temp) {
    if (!*path) {
        *count = 0;
        return NULL;
    }
    vector<string> *strings = new vector<string>();
    size_t curPos = 0;
    size_t endPos = strlen(path);
    if (path[curPos] == '/') {
        strings->push_back("/");
    }
    while (curPos < endPos) {
        while (curPos < endPos && path[curPos] == '/') {
            curPos++;
        }
        if (curPos == endPos) {
            break;
        }
        auto curEnd = curPos;
        while (curEnd < endPos && path[curEnd] != '/') {
            curEnd++;
        }
        string str(path + curPos, curEnd - curPos);
        strings->push_back(str);
        curPos = curEnd;
    }
    if (endPos > 1 && path[endPos - 1] == '/') {
        strings->push_back("/");
    }
    const char **components = new const char *[strings->size()];
    for (int i = 0; i < strings->size(); i++) {
        components[i] = (*strings)[i].c_str();
    }
    *count = strings->size();
    return components;
}



/*internal func _pathComponents(_ path: String?) -> [String]? {
    guard let p = path else {
        return nil
    }

    var result = [String]()
    if p.length == 0 {
        return result
    } else {
        let characterView = p
        var curPos = characterView.startIndex
        let endPos = characterView.endIndex
        if characterView[curPos] == "/" {
            result.append("/")
        }

        while curPos < endPos {
            while curPos < endPos && characterView[curPos] == "/" {
                curPos = characterView.index(after: curPos)
            }
            if curPos == endPos {
                break
            }
            var curEnd = curPos
            while curEnd < endPos && characterView[curEnd] != "/" {
                curEnd = characterView.index(after: curEnd)
            }
            result.append(String(characterView[curPos ..< curEnd]))
            curPos = curEnd
        }
    }
    if p.length > 1 && p.hasSuffix("/") {
        result.append("/")
    }
    return result
}
*/
