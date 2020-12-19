//
// Created by 王义文 on 2020-04-22.
//

#include "book.h"
#ifndef UNTITLED_READERCONTROL_H
#define UNTITLED_READERCONTROL_H
void circulation(book *boo,int n,char ID[]);/*图书的借阅*/
void seeBorrowed(book * boo,int n,char ID[]);
void search(book *boo,int n);  /*图书的查询*/
void lossmanage(book * boo,int n,char ID[]);  /*图书的丢失登记*/
int runmenu_reader(book *boo,int n,int choice,char ID[]);/*主控模块，选择执行于读者一级菜单功能*/
void readerMenu(char ID[]);
#endif //UNTITLED_READERCONTROL_H

