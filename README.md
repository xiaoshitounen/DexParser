# DexParser
dex 文件主要内容：
- header
- string_ids
- type_ids
- proto_ids
- fields
- method_ids
- class_def

这些内容除了 class_def，都已经解析完毕了。class_def 最外层也已经解析完毕，内层内容也解析了一部分，其他部分都是堆代码就不继续了。
后续可以考虑换种方式重写一边解析。
