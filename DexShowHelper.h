//
// Created by 许磊 on 2021/11/6.
//

#ifndef DEX_DEXSHOWHELPER_H
#define DEX_DEXSHOWHELPER_H

#include <iostream>
#include "dex.h"

class DexShowHelper {
    public:
        void showDexHeader(DexHeader &header);
        void showDexStringId(const DexStringId dexStringIds[], u4 stringIdsSize);
        void showDexString(const std::string dexStrings[], u4 stringIdsSize);
        void showDexTypeId(const DexTypeId dexTypeIds[], u4 typeIdsSize);
        void showDexType(const std::string dexTypes[], u4 typeIdsSize);
        void showDexProtoId(const DexProtoId dexProtoIds[], u4 protoIdsSize);
        void showDexProto(const std::string dexProtos[], u4 protoIdsSize);
        void showDexFieldId(const DexFieldId dexFieldIds[], u4 fieldIdsSize);
        void showDexField(const std::string dexFields[], u4 fieldIdsSize);
        void showDexMethodId(const DexMethodId dexMethodIds[], u4 methodIdsSize);
        void showDexMethod(const std::string dexMethods[], u4 methodIdsSize);
        void showDexClassDef(const DexClassDef dexClassDefs[], u4 classDefsSize);
    private:
        void formatPrint(int width, const std::string& key,  unsigned int value);
        void formatPrint(int width, const std::string& key, const std::string& value);
};


#endif //DEX_DEXSHOWHELPER_H
