//
// Created by 王义文 on 2020-04-22.
//

#ifndef UNTITLED_BOOK_H
#define UNTITLED_BOOK_H

#endif //UNTITLED_BOOK_H
#ifndef _BOOK                /*条件编译，防止重复包含的错误*/
#define _BOOK
#include"adminMenu.h"
#define   NU 10             /*定义图书常量，根据实际需要修改值*/

#define sizeboo sizeof(book)//一条图书记录所需要的的内存大小
void borrowed(book *boo,int n,char ID[]);//图书的借出
void back(book *boo,int n);//图书的归还
void searchname(book *boo,int n);//按图书名称查询
void searchtype(book *boo,int n);//按图书种类查询
#endif
