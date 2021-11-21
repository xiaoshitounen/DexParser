//
// Created by 许磊 on 2021/11/6.
//

#include <sstream>
#include "DexShowHelper.h"

void DexShowHelper::showDexHeader(DexHeader &header) {
    int width = 17;
    std::cout.setf(std::ios_base::left, std::ios_base::adjustfield);
    std::cout << "****************************" << std::endl;
    std::cout << "dex header:" << std::endl;
    formatPrint(width, "file size", header.fileSize);
    formatPrint(width, "header size", header.headerSize);
    formatPrint(width, "string_ids size", header.stringIdsSize);
    formatPrint(width, "string_ids offset", header.stringIdsOff);
    formatPrint(width, "type_ids size", header.typeIdsSize);
    formatPrint(width, "type_ids offset", header.typeIdsOff);
    formatPrint(width, "proto_ids size", header.protoIdsSize);
    formatPrint(width, "proto_ids offset", header.protoIdsOff);
    formatPrint(width, "field_ids size", header.fieldIdsSize);
    formatPrint(width, "field_ids offset", header.fieldIdsOff);
    formatPrint(width, "method_ids size", header.methodIdsSize);
    formatPrint(width, "method_ids offset", header.methodIdsOff);
    formatPrint(width, "class_defs size", header.classDefsSize);
    formatPrint(width, "class_defs offset", header.classDefsOff);
    formatPrint(width, "data size", header.dataSize);
    formatPrint(width, "data offset", header.dataOff);
}

void DexShowHelper::showDexStringId(const DexStringId dexStringIds[], u4 stringIdsSize) {
    int width = 15;
    std::cout.setf(std::ios_base::left, std::ios_base::adjustfield);
    std::cout << "****************************" << std::endl;
    std::cout << "dex string ids:" << std::endl;
    for (int i = 0; i < stringIdsSize; i++) {
        std::stringstream key;
        key << "string ids [" << i << "]";
        formatPrint(width, key.str(), dexStringIds[i].stringDataOff);
    }
}

void DexShowHelper::showDexString(const std::string dexStrings[], u4 stringIdsSize) {
    int width = 12;
    std::cout.setf(std::ios_base::left, std::ios_base::adjustfield);
    std::cout << "****************************" << std::endl;
    std::cout << "dex strings:" << std::endl;
    for (int i = 0; i < stringIdsSize; i++) {
        std::stringstream key;
        key << "strings [" << i << "]";
        formatPrint(width, key.str(), dexStrings[i]);
    }
}

void DexShowHelper::showDexTypeId(const DexTypeId dexTypeIds[], u4 typeIdsSize) {
    int width = 12;
    std::cout.setf(std::ios_base::left, std::ios_base::adjustfield);
    std::cout << "****************************" << std::endl;
    std::cout << "dex type ids:" << std::endl;
    for (int i = 0; i < typeIdsSize; i++) {
        std::stringstream key;
        key << "type ids [" << i << "]";
        formatPrint(width, key.str(), dexTypeIds[i].descriptorIdx);
    }
}

void DexShowHelper::showDexType(const std::string dexTypes[], u4 typeIdsSize) {
    int width = 9;
    std::cout.setf(std::ios_base::left, std::ios_base::adjustfield);
    std::cout << "****************************" << std::endl;
    std::cout << "dex types:" << std::endl;
    for (int i = 0; i < typeIdsSize; i++) {
        std::stringstream key;
        key << "types [" << i << "]";
        formatPrint(width, key.str(), dexTypes[i]);
    }
}

void DexShowHelper::showDexProtoId(const DexProtoId dexProtoIds[], u4 protoIdsSize) {
    int width = 12;
    std::cout.setf(std::ios_base::left, std::ios_base::adjustfield);
    std::cout << "****************************" << std::endl;
    std::cout << "dex proto ids:" << std::endl;
    for (int i = 0; i < protoIdsSize; i++) {
        std::stringstream key;
        key << "proto ids [" << i << "]";
        std::stringstream value;
        value << "shortyIdx:" << dexProtoIds[i].shortyIdx << " returnTypeIdx:" << dexProtoIds[i].returnTypeIdx << " parametersOff:" << dexProtoIds[i].parametersOff;
        formatPrint(width, key.str(), value.str());
    }
}

void DexShowHelper::showDexProto(const std::string dexProtos[], u4 protoIdsSize) {
    int width = 8;
    std::cout.setf(std::ios_base::left, std::ios_base::adjustfield);
    std::cout << "****************************" << std::endl;
    std::cout << "dex protos:" << std::endl;
    for (int i = 0; i < protoIdsSize; i++) {
        std::stringstream key;
        key << "protos [" << i << "]";
        std::stringstream value;
        value << dexProtos[i];
        formatPrint(width, key.str(), value.str());
    }
}

void DexShowHelper::showDexFieldId(const DexFieldId dexFieldIds[], u4 fieldIdsSize) {
    int width = 12;
    std::cout.setf(std::ios_base::left, std::ios_base::adjustfield);
    std::cout << "****************************" << std::endl;
    std::cout << "dex field ids:" << std::endl;
    for (int i = 0; i < fieldIdsSize; i++) {
        std::stringstream key;
        key << "field ids [" << i << "]";
        std::stringstream value;
        value << "classIdx:" << dexFieldIds[i].classIdx << " typeIdx:" << dexFieldIds[i].typeIdx << " nameIdx:" << dexFieldIds[i].nameIdx;
        formatPrint(width, key.str(), value.str());
    }
}

void DexShowHelper::showDexField(const std::string dexFields[], u4 fieldIdsSize) {
    int width = 8;
    std::cout.setf(std::ios_base::left, std::ios_base::adjustfield);
    std::cout << "****************************" << std::endl;
    std::cout << "dex fields:" << std::endl;
    for (int i = 0; i < fieldIdsSize; i++) {
        std::stringstream key;
        key << "fields [" << i << "]";
        std::stringstream value;
        value << dexFields[i];
        formatPrint(width, key.str(), value.str());
    }
}

void DexShowHelper::showDexMethodId(const DexMethodId dexMethodIds[], u4 methodIdsSize) {
    int width = 12;
    std::cout.setf(std::ios_base::left, std::ios_base::adjustfield);
    std::cout << "****************************" << std::endl;
    std::cout << "dex method ids:" << std::endl;
    for (int i = 0; i < methodIdsSize; i++) {
        std::stringstream key;
        key << "method ids [" << i << "]";
        std::stringstream value;
        value << "classIdx:" << dexMethodIds[i].classIdx << " protoIdx:" << dexMethodIds[i].protoIdx << " nameIdx:" << dexMethodIds[i].nameIdx;
        formatPrint(width, key.str(), value.str());
    }
}

void DexShowHelper::showDexMethod(const std::string dexMethods[], u4 methodIdsSize) {
    int width = 8;
    std::cout.setf(std::ios_base::left, std::ios_base::adjustfield);
    std::cout << "****************************" << std::endl;
    std::cout << "dex methods:" << std::endl;
    for (int i = 0; i < methodIdsSize; i++) {
        std::stringstream key;
        key << "methods [" << i << "]";
        std::stringstream value;
        value << dexMethods[i];
        formatPrint(width, key.str(), value.str());
    }
}

void DexShowHelper::showDexClassDef(const DexClassDef dexClassDefs[], u4 classDefsSize) {
    int width = 12;
    std::cout.setf(std::ios_base::left, std::ios_base::adjustfield);
    std::cout << "****************************" << std::endl;
    std::cout << "dex class defs:" << std::endl;
    for (int i = 0; i < classDefsSize; i++) {
        std::stringstream key;
        key << "class defs [" << i << "]";
        std::stringstream value;
        value << "classIdx:" << dexClassDefs[i].classIdx << " accessFlags:" << dexClassDefs[i].accessFlags << " namesuperClassIdxIdx:" << dexClassDefs[i].superClassIdx << " ";
        value << "interfaceOff:" << dexClassDefs[i].interfaceOff << " sourceFileIdx:" << dexClassDefs[i].sourceFileIdx << " annotationsOff:" << dexClassDefs[i].annotationsOff << " ";
        value << "classDataOff:" << dexClassDefs[i].classDataOff << " staticValuesOff:" << dexClassDefs[i].staticValuesOff;
        formatPrint(width, key.str(), value.str());
    }
}

void DexShowHelper::formatPrint(int width, const std::string &key, unsigned int value) {
    std::cout << "   ";
    std::cout.width(width);
    std::cout << key;
    std::cout << " = " << value << std::endl;
}

void DexShowHelper::formatPrint(int width, const std::string &key, const std::string &value) {
    std::cout << "   ";
    std::cout.width(width);
    std::cout << key;
    std::cout << " = " << value << std::endl;
}
