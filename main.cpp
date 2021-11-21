#include <iostream>
#include "DexParseHelper.h"
#include "DexShowHelper.h"

const char *filePath = "/Users/xulei/Desktop/Hello.dex";

int main() {
    std::ifstream dex;
    dex.open(filePath, std::ios_base::in | std::ios_base::binary);
    if (dex.is_open()) {
        std::cout << filePath << "文件打开成功" << std::endl;
    } else {
        std::cout << filePath << "文件打开失败" << std::endl;
    }

    DexParserHelper parseHelper = DexParserHelper();
    DexShowHelper showHelper = DexShowHelper();

    //解析 header
    DexHeader header = DexHeader();
    parseHelper.parseHeader(dex, &header);
    showHelper.showDexHeader(header);

    //解析 string_ids
    DexStringId *dexStringIds = new DexStringId[header.stringIdsSize];
    parseHelper.parseStringId(dex, header.stringIdsOff, dexStringIds, header.stringIdsSize);
    showHelper.showDexStringId(dexStringIds, header.stringIdsSize);
    //解析 string_ids 对应的 string
    std::string *dexStrings = new std::string [header.stringIdsSize];
    parseHelper.parseString(dex, dexStringIds, header.stringIdsSize, dexStrings);
    showHelper.showDexString(dexStrings, header.stringIdsSize);

    //解析 type_ids
    DexTypeId *dexTypeIds = new DexTypeId[header.typeIdsSize];
    parseHelper.parseTypeId(dex, header.typeIdsOff, dexTypeIds, header.typeIdsSize);
    showHelper.showDexTypeId(dexTypeIds, header.typeIdsSize);
    //解析 type_ids 对应的 type
    std::string *dexTypes = new std::string [header.typeIdsSize];
    parseHelper.parseType(dexTypeIds, header.typeIdsSize, dexStrings, dexTypes);
    showHelper.showDexType(dexTypes, header.typeIdsSize);

    //解析 proto_ids
    DexProtoId *dexProtoIds = new DexProtoId[header.protoIdsSize];
    parseHelper.parseProtoId(dex, header.protoIdsOff, dexProtoIds, header.protoIdsSize);
    showHelper.showDexProtoId(dexProtoIds, header.protoIdsSize);
    //解析 proto_ids 对应的 parameters
    DexTypeList* *dexProtoParameters = new DexTypeList*[header.protoIdsSize];
    parseHelper.parseProtoParameter(dex, dexProtoIds, header.protoIdsSize, dexProtoParameters);
    //解析 proto_ids 对应的 proto
    std::string *dexProtos = new std::string [header.protoIdsSize];
    parseHelper.parseProto(dexProtoIds, header.protoIdsSize, dexStrings, dexTypes, dexProtoParameters, dexProtos);
    showHelper.showDexProto(dexProtos, header.protoIdsSize);

    //解析 fields_ids
    DexFieldId *dexFieldIds = new DexFieldId[header.fieldIdsSize];
    parseHelper.parseFieldId(dex, header.fieldIdsOff, dexFieldIds, header.fieldIdsSize);
    showHelper.showDexFieldId(dexFieldIds, header.fieldIdsSize);
    //解析 fields_ids 对应的 fields
    std::string *dexFields = new std::string [header.fieldIdsSize];
    parseHelper.parseField(dexFieldIds, header.fieldIdsSize, dexStrings, dexTypes, dexFields);
    showHelper.showDexField(dexFields, header.fieldIdsSize);

    //解析 method_ids
    DexMethodId *dexMethodIds = new DexMethodId[header.methodIdsSize];
    parseHelper.parseMethodId(dex, header.methodIdsOff, dexMethodIds, header.methodIdsSize);
    showHelper.showDexMethodId(dexMethodIds, header.methodIdsSize);
    //解析 method_ids 对应的 methods
    std::string *dexMethods = new std::string [header.methodIdsSize];
    parseHelper.parseMethod(dexMethodIds, header.methodIdsSize, dexStrings, dexTypes, dexProtos, dexMethods);
    showHelper.showDexMethod(dexMethods, header.methodIdsSize);

    //解析 class_def
    DexClassDef *dexClassDefs = new DexClassDef[header.classDefsSize];
    parseHelper.parseClassDef(dex, header.classDefsOff, dexClassDefs, header.classDefsSize);
    showHelper.showDexClassDef(dexClassDefs, header.classDefsSize);
    //解析 class_def 中的 interfaces
    DexTypeList* *dexClassInterfaces = new DexTypeList*[header.classDefsSize];
    parseHelper.parseClassInterfaces(dex, dexClassDefs, header.classDefsSize, dexClassInterfaces);

    //解析 class_def 中的 annotations
    parseHelper.parseClassAnnotations(dex, dexClassDefs, header.classDefsSize);

    //解析 class_def 中的 classData

    //解析 class_def 中的 staticValues

    //释放 new 的内存
    delete [] dexStringIds;
    dexStringIds = nullptr;
    delete [] dexStrings;
    dexStrings = nullptr;

    delete [] dexTypeIds;
    dexTypeIds = nullptr;
    delete [] dexTypes;
    dexTypes = nullptr;

    delete [] dexProtoIds;
    dexProtoIds = nullptr;
    for (int i = 0; i < header.protoIdsSize; i++) {
        delete [] dexProtoParameters[i]->list;
        dexProtoParameters[i]->list = nullptr;
        delete dexProtoParameters[i];
        dexProtoParameters[i] = nullptr;
    }
    delete [] dexProtoParameters;
    dexProtoParameters = nullptr;
    delete [] dexProtos;
    dexProtos = nullptr;

    delete [] dexFieldIds;
    dexFieldIds = nullptr;
    delete [] dexFields;
    dexFields = nullptr;

    delete [] dexMethodIds;
    dexMethodIds = nullptr;
    delete [] dexMethods;
    dexMethods = nullptr;

    //TODO Class_Def 内存清理

    return 0;
}