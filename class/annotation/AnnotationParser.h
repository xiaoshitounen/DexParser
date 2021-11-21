//
// Created by 许磊 on 2021/11/7.
//

#ifndef DEX_ANNOTATIONPARSER_H
#define DEX_ANNOTATIONPARSER_H

#include "../../dex.h"
#include <fstream>

class AnnotationParser {
    public:
        void parseDexAnnotationDirectoryItem(std::ifstream &dex, u4 annotationsOff, DexAnnotationsDirectoryItem *item);
};


#endif //DEX_ANNOTATIONPARSER_H
