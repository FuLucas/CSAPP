/*
 7.11题

 未初始化的全局变量在目标文件中不分配存储空间，加载后需要分配空间。这些空间可能是为.bss中的符号预留的。
 */