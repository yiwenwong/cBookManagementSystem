//
// Created by 王义文 on 2020-04-22.
//

#ifndef UNTITLED_READERFILE_H
#define UNTITLED_READERFILE_H
#include "book.h"
int createbookFile(book *boo,int n);       /*建立初始的数据文件*/
int readbookFile(book *boo);        /*将文件中的内容读出置于结构体数组boo中*/
void savebookFile(book *boo,int n);  /*将结构体数组的内容写入文件*/
#endif //UNTITLED_READERFILE_H
