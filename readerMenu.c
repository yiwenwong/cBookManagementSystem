//
// Created by 王义文 on 2020-04-22.
//

#include "readerMenu.h"
#include <stdio.h>
void menureader( )         /*读者菜单函数*/
{

    printf("\t\t******** 1. 图书的借阅      ********\n");
    printf("\t\t******** 2. 查看已借的图书  ********\n");
    printf("\t\t******** 3. 图书的查询      ********\n");
    printf("\t\t******** 4. 丢失图书登记    ********\n");
    printf("\t\t******** 5. AI游戏          ********\n");
    printf("\t\t******** 0. 退出            ********\n");
}

void menuBorrow( )     /*图书借阅菜单函数*/
{
    printf("******** 1. 图书的借出    ********\n");
    printf("******** 2. 图书的归还    ********\n");
    printf("******** 0. 返回上层菜单  ********\n");
}

void menuSearch( )     /*图书查询菜单函数*/
{
    printf("******** 1. 按图书名称   ********\n");
    printf("******** 2. 按图书类别   ********\n");
    printf("******** 0. 返回上层菜单 ********\n");
}
