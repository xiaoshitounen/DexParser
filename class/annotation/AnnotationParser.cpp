//
// Created by 许磊 on 2021/11/7.
//

#include "AnnotationParser.h"
#include <iostream>

void AnnotationParser::parseDexAnnotationDirectoryItem(std::ifstream &dex, u4 annotationsOff, DexAnnotationsDirectoryItem *item) {
    dex.seekg(annotationsOff);
    dex.read((char *)item, sizeof(DexAnnotationsDirectoryItem));

    if (item->classAnnotationsOff != 0) {
        //TODO 只是测试，因为这里 seekg 会影响后面 读
        dex.seekg(item->classAnnotationsOff);
        u4 size = 0;
        dex.read((char *)&size, sizeof(size));
        std::cout << "当前类的注解个数" << size << std::endl;
        for (int i = 0; i < item->classAnnotationsOff; i++) {

        }
    } else {
        // 当前类没有注解
    }

    DexFieldAnnotationsItem *fieldAnnotationsItem = new DexFieldAnnotationsItem[item->fieldsSize];
    for (int i = 0; i < item->fieldsSize; i++) {
        dex.read((char *)&fieldAnnotationsItem[i], sizeof(DexFieldAnnotationsItem));
    }
    for (int i = 0; i < item->fieldsSize; i++) {
        std::cout << "fieldIdx" << fieldAnnotationsItem[i].fieldIdx << std::endl;
    }
    DexMethodAnnotationsItem *methodAnnotationsItem = new DexMethodAnnotationsItem[item->methodsSize];
    for (int i = 0; i < item->methodsSize; i++) {
        dex.read((char *)&methodAnnotationsItem[i], sizeof(DexMethodAnnotationsItem));
    }
    for (int i = 0; i < item->methodsSize; i++) {
        std::cout << "methodIdx" << methodAnnotationsItem[i].methodIdx << std::endl;
    }
    DexParameterAnnotationsItem *parameterAnnotationsItem = new DexParameterAnnotationsItem[item->parametersSize];
    for (int i = 0; i < item->parametersSize; i++) {
        dex.read((char *)&parameterAnnotationsItem[i], sizeof(DexParameterAnnotationsItem));
    }
    for (int i = 0; i < item->parametersSize; i++) {
        std::cout << "methodIdx" << parameterAnnotationsItem[i].methodIdx << std::endl;
    }
}
