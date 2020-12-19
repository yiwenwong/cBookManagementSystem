//
// Created by 王义文 on 2020-04-22.
//

#ifndef UNTITLED_FILE_H
#define UNTITLED_FILE_H
#include "account.h"
int readFile(account *acc );       /*建立初始的数据文件*/
void saveFile(account *acc,int n);        /*将文件中的内容读出置于结构体数组stu中*/
int  createFile(account *acc) ;
#endif //UNTITLED_FILE_H


