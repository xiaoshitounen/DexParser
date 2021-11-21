//
// Created by 许磊 on 2021/11/6.
//

#ifndef DEX_DEXPARSEHELPER_H
#define DEX_DEXPARSEHELPER_H

#include <iostream>
#include <fstream>
#include "dex.h"
#include "class/annotation/AnnotationParser.h"

class DexParserHelper {
    public:
        DexParserHelper();
        void parseHeader(std::ifstream &dex, DexHeader *header);
        void parseStringId(std::ifstream &dex, u4 stringIdsOff, DexStringId dexStringIds[], u4 stringIdsSize);
        void parseString(std::ifstream &dex, const DexStringId dexStringIds[], u4 stringIdsSize, std::string dexStrings[]);
        void parseTypeId(std::ifstream &dex, u4 typeIdsOff, DexTypeId dexTypeIds[], u4 typeIdsSize);
        void parseType(const DexTypeId dexTypeIds[], u4 typeIdsSize, const std::string dexStrings[], std::string dexTypes[]);
        void parseProtoId(std::ifstream &dex, u4 protoIdsOff, DexProtoId dexProtoIds[], u4 protoIdsSize);
        void parseProtoParameter(std::ifstream &dex, const DexProtoId dexProtoIds[], u4 protoIdsSize, DexTypeList* dexProtoParameters[]);
        void parseProto(DexProtoId dexProtoIds[], u4 protoIdsSize, const std::string dexStrings[], const std::string dexTypes[], DexTypeList* dexProtoParameters[], std::string dexProtos[]);
        void parseFieldId(std::ifstream &dex, u4 fieldIdsOff, DexFieldId dexFieldIds[], u4 fieldIdsSize);
        void parseField(const DexFieldId dexFieldIds[], u4 fieldIdsSize, const std::string dexStrings[], const std::string dexTypes[], std::string dexFields[]);
        void parseMethodId(std::ifstream &dex, u4 methodIdsOff, DexMethodId dexMethodIds[], u4 methodIdsSize);
        void parseMethod(const DexMethodId dexMethodIds[], u4 methodIdsSize, const std::string dexStrings[], const std::string dexTypes[], const std::string dexProtos[], std::string dexMethods[]);
        void parseClassDef(std::ifstream &dex, u4 classDefOff, DexClassDef dexClassDefs[], u4 classDefSize);
        void parseClassInterfaces(std::ifstream &dex, DexClassDef dexClassDefs[], u4 classDefSize, DexTypeList* dexClassInterfaces[]);
        void parseClassAnnotations(std::ifstream &dex, DexClassDef dexClassDefs[], u4 classDefSize);

private:
        AnnotationParser annotationParser;
        void parseTypeList(std::ifstream &dex, const u4 typeOffs[], u4 typeSize, DexTypeList* dexTypeLists[]);
};


#endif //DEX_DEXPARSEHELPER_H
