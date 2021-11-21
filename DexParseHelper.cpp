//
// Created by 许磊 on 2021/11/6.
//
#include <sstream>
#include "DexParseHelper.h"

DexParserHelper::DexParserHelper() {
    annotationParser = AnnotationParser();
}

void DexParserHelper::parseHeader(std::ifstream &dex, DexHeader *header) {
    dex.read((char *) header, sizeof(DexHeader));
}

void DexParserHelper::parseStringId(std::ifstream &dex, u4 stringIdsOff, DexStringId dexStringIds[], u4 stringIdsSize) {
    dex.seekg(stringIdsOff);
    for (int i = 0; i < stringIdsSize; i++) {
        DexStringId stringId = DexStringId();
        dex.read((char *)&stringId, sizeof(DexStringId));
        dexStringIds[i] = stringId;
    }
}

void DexParserHelper::parseString(std::ifstream &dex, const DexStringId dexStringIds[], u4 stringIdsSize, std::string dexStrings[]) {
    //data 区域：第一个 byte 存储的是大小，后面紧跟着内容
    for (int i = 0; i < stringIdsSize; i++) {
        //1.找到存储位置
        dex.seekg(dexStringIds[i].stringDataOff);
        //2.读取存储大小
        u1 size = 0;
        dex.read((char *)&size, sizeof(u1));
        //3.读取内容
        char *content = new char[(int) size + 1];
        dex.read((char *)content, (int) size);
        content[size] = '\0'; // C 风格字符串需要自己手动加一个 \0
        dexStrings[i] = content; // 默认深拷贝
        //4.释放
        delete[] content;
    }
}

void DexParserHelper::parseTypeId(std::ifstream &dex, u4 typeIdsOff, DexTypeId dexTypeIds[], u4 typeIdsSize) {
    dex.seekg(typeIdsOff);
    for (int i = 0; i < typeIdsSize; i++) {
        DexTypeId typeId = DexTypeId();
        dex.read((char *)&typeId, sizeof(DexTypeId));
        dexTypeIds[i] = typeId;
    }
}

void DexParserHelper::parseType(const DexTypeId dexTypeIds[], u4 typeIdsSize, const std::string dexStrings[],
                                std::string dexTypes[]) {
    for (int i = 0; i < typeIdsSize; i++) {
        dexTypes[i] = dexStrings[dexTypeIds[i].descriptorIdx];
    }
}

void DexParserHelper::parseProtoId(std::ifstream &dex, u4 protoIdsOff, DexProtoId dexProtoIds[], u4 protoIdsSize) {
    dex.seekg(protoIdsOff);
    for (int i = 0; i < protoIdsSize; i++) {
        DexProtoId protoId = DexProtoId();
        dex.read((char *)&protoId, sizeof(DexProtoId));
        dexProtoIds[i] = protoId;
    }
}

void DexParserHelper::parseProtoParameter(std::ifstream &dex, const DexProtoId dexProtoIds[], u4 protoIdsSize,
                                          DexTypeList* dexProtoParameters[]) {
    u4 *typeOffs = new u4[protoIdsSize];
    for (int i = 0; i < protoIdsSize; i++) {
        typeOffs[i] = dexProtoIds[i].parametersOff;
    }
    parseTypeList(dex, typeOffs, protoIdsSize, dexProtoParameters);
    delete [] typeOffs;
    typeOffs = nullptr;
}

void DexParserHelper::parseProto(DexProtoId dexProtoIds[], u4 protoIdsSize, const std::string dexStrings[],
                                 const std::string dexTypes[], DexTypeList* dexProtoParameters[],
                                 std::string dexProtos[]) {
    for (int i = 0; i < protoIdsSize; i++) {
        DexProtoId protoId = dexProtoIds[i];
        std::stringstream proto;
        proto << "shorty:" << dexStrings[protoId.shortyIdx] << " ";
        proto << "returnType:" << dexTypes[protoId.returnTypeIdx] << " ";
        proto << "parameters:";
        DexTypeList* parameters =  dexProtoParameters[i];
        if (parameters->size == 0) proto << "NULL";
        for (int j = 0; j < parameters->size; j++) {
            proto << dexTypes[parameters->list[j].typeIdx];
        }
        dexProtos[i] = proto.str();
    }
}

void DexParserHelper::parseFieldId(std::ifstream &dex, u4 fieldIdsOff, DexFieldId dexFieldIds[], u4 fieldIdsSize) {
    dex.seekg(fieldIdsOff);
    for (int i = 0; i < fieldIdsSize; i++) {
        DexFieldId fieldId = DexFieldId();
        dex.read((char *)&fieldId, sizeof(DexFieldId));
        dexFieldIds[i] = fieldId;
    }
}

void DexParserHelper::parseField(const DexFieldId dexFieldIds[], u4 fieldIdsSize, const std::string dexStrings[],
                                 const std::string dexTypes[], std::string dexFields[]) {
    for (int i = 0; i < fieldIdsSize; i++) {
        DexFieldId fieldId = dexFieldIds[i];
        std::stringstream field;
        field << "class:" << dexTypes[fieldId.classIdx] << " ";
        field << "type:" << dexTypes[fieldId.typeIdx] << " ";
        field << "name:" << dexStrings[fieldId.nameIdx];
        dexFields[i] = field.str();
    }
}

void DexParserHelper::parseMethodId(std::ifstream &dex, u4 methodIdsOff, DexMethodId dexMethodIds[], u4 methodIdsSize) {
    dex.seekg(methodIdsOff);
    for (int i = 0; i < methodIdsSize; i++) {
        DexMethodId methodId = DexMethodId();
        dex.read((char *)&methodId, sizeof(DexFieldId));
        dexMethodIds[i] = methodId;
    }
}

void DexParserHelper::parseMethod(const DexMethodId dexMethodIds[], u4 methodIdsSize, const std::string dexStrings[],
                                  const std::string dexTypes[], const std::string dexProtos[], std::string dexMethods[]) {
    for (int i = 0; i < methodIdsSize; i++) {
        DexMethodId methodId = dexMethodIds[i];
        std::stringstream method;
        method << "class:" << dexTypes[methodId.classIdx] << " ";
        method << "proto:" << dexProtos[methodId.protoIdx] << " ";
        method << "name:" << dexStrings[methodId.nameIdx];
        dexMethods[i] = method.str();
    }
}

void DexParserHelper::parseClassDef(std::ifstream &dex, u4 classDefOff, DexClassDef dexClassDefs[], u4 classDefSize) {
    dex.seekg(classDefOff);
    for (int i = 0; i < classDefSize; i++) {
        DexClassDef classDef = DexClassDef();
        dex.read((char *)&classDef, sizeof(DexClassDef));
        dexClassDefs[i] = classDef;
    }
}

void DexParserHelper::parseClassInterfaces(std::ifstream &dex, DexClassDef dexClassDefs[], u4 classDefSize,
                                           DexTypeList* dexClassInterfaces[]) {
    u4 *typeOffs = new u4[classDefSize];
    for (int i = 0; i < classDefSize; i++) {
        typeOffs[i] = dexClassDefs[i].interfaceOff;
    }
    parseTypeList(dex, typeOffs, classDefSize, dexClassInterfaces);
    delete [] typeOffs;
    typeOffs = nullptr;
}

void DexParserHelper::parseClassAnnotations(std::ifstream &dex, DexClassDef dexClassDefs[], u4 classDefSize) {
    for (int i = 0; i < classDefSize; i++) {
        DexClassDef classDef = dexClassDefs[i];
        DexAnnotationsDirectoryItem item = DexAnnotationsDirectoryItem();
        if (classDef.annotationsOff != 0) {
            annotationParser.parseDexAnnotationDirectoryItem(dex, classDef.annotationsOff, &item);
        } else {
            //TODO 无注解数据
        }
    }
}

void DexParserHelper::parseTypeList(std::ifstream &dex, const u4 typeOffs[], u4 typeSize, DexTypeList* dexTypeLists[]) {
    for (int i = 0; i < typeSize; i++) {
        u4 typeOff = typeOffs[i];
        if (typeOff == 0) {
            DexTypeList *parameter = new DexTypeList;
            DexTypeItem *items = new DexTypeItem[0];
            parameter->size = 0;
            parameter->list = items;
            dexTypeLists[i] = parameter;
        } else {
            dex.seekg(typeOff);
            u4 size = 0;
            dex.read((char *)&size, sizeof(u4));
            DexTypeList *parameter = new DexTypeList;
            DexTypeItem *items = new DexTypeItem[size];
            for (int j = 0; j < size; j++) {
                dex.read((char *)&items[j], sizeof(DexTypeItem));
            }
            parameter->size = size;
            parameter->list = items;
            dexTypeLists[i] = parameter;
        }
    }
}




