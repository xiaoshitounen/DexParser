//
// Created by 许磊 on 2021/11/6.
//

#ifndef DEX_DEX_H
#define DEX_DEX_H

//参考：http://androidxref.com/9.0.0_r3/xref/dalvik/libdex/DexFile.h
#include <iostream>

typedef uint8_t u1;
typedef uint16_t u2;
typedef uint32_t u4;

struct DexHeader {
    u1 magic[8];
    u4 checksum;
    u1 signature[20];
    u4 fileSize;
    u4 headerSize;
    u4 endianTag;
    u4 linkSize;
    u4 linkOff;
    u4 mapOff;
    u4 stringIdsSize;
    u4 stringIdsOff;
    u4 typeIdsSize;
    u4 typeIdsOff;
    u4 protoIdsSize;
    u4 protoIdsOff;
    u4 fieldIdsSize;
    u4 fieldIdsOff;
    u4 methodIdsSize;
    u4 methodIdsOff;
    u4 classDefsSize;
    u4 classDefsOff;
    u4 dataSize;
    u4 dataOff;
};

struct DexStringId {
    u4 stringDataOff;
};

struct DexTypeId {
    u4 descriptorIdx;
};

struct DexProtoId {
    u4 shortyIdx;
    u4 returnTypeIdx;
    u4 parametersOff;
};

struct DexTypeItem {
    u2 typeIdx;
};

struct DexTypeList {
    u4 size;
    DexTypeItem* list;
};

struct DexFieldId {
    u2 classIdx;
    u2 typeIdx;
    u4 nameIdx;
};

struct DexMethodId {
    u2 classIdx;
    u2 protoIdx;
    u4 nameIdx;
};

struct DexClassDef {
    u4 classIdx;
    u4 accessFlags;
    u4 superClassIdx;
    u4 interfaceOff;
    u4 sourceFileIdx;
    u4 annotationsOff;
    u4 classDataOff;
    u4 staticValuesOff;
};

struct DexAnnotationsDirectoryItem {
    u4 classAnnotationsOff;
    u4 fieldsSize;
    u4 methodsSize;
    u4 parametersSize;
};

struct DexFieldAnnotationsItem {
    u4 fieldIdx;
    u4 annotationsOff;
};

struct DexMethodAnnotationsItem {
    u4 methodIdx;
    u4 annotationsOff;
};

struct DexParameterAnnotationsItem {
    u4 methodIdx;
    u4 annotationsOff;
};

struct DexAnnotationSetItem {
    u4 size;
    u4 *entries;
};

struct DexAnnotationItem {
    u1 visibility;
    u1 annotation[1];
};

#endif //DEX_DEX_H
