//
// Created by 王义文 on 2020-04-22.
//

#include "readerControl.h"
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include"book.h"
#include "AIgame.h"
#include "readerMenu.h"
#include "bookFile.h"
#include "timenow.h"



void circulation(book *boo,int n,char ID[])
{	int choice;
    do
    { 	menuBorrow();
        printf("请输入您的选择\n");
        scanf("%d",&choice);
        switch(choice)
        {	case 1:    borrowed(boo,n, ID);break;
            case 2:    back(boo,n);break;

            case 0:    break;
            default:printf("请输入有效数字！");
                circulation(boo,n,ID);
        }
    }while(choice);
}

void  seeBorrowed(book * boo,int n,char ID[])//查看已借的书
{  int i,d;;
    printf("你所借的书为：\n");
    for(i=0;i<n;i++)
    {
        if(strcmp(boo[i].id,ID)==0)
        {
            printf("编号：%s\n", boo[i].number);
            printf("书名：%s\n",boo[i].name);
            d=distance(now(),boo[i].boday);
            if(d==100)printf("输入错误");
            else if(d==-1)printf("你已超出还书期限！");
                 else printf("距离还书期限还有%d天",d);
        }
    }


}

void search(book *boo,int n)/*按条件查询*/
{	int choice;
    do
    {	 menuSearch( ) ;
        printf("请输入您的选择\n");
        scanf("%d",&choice);
        switch(choice)
        {	case 1:    searchname(boo,n);break;
            case 2:    searchtype(boo,n);break;
            case 0:    break;
        }
    }while(choice);
}


void lossmanage(book *boo,int n,char ID[])/*图书丢失登记*/

{
    int i,flag=1;
    char s3[10];
    printf("请输入您丢失图书的名称：");
    scanf("%s",s3);

    for(i=0;i<n;i++)
        if(strcmp(s3,boo[i].name)==0&&strcmp(ID,boo[i].id)==0)
        {
            flag=0;
            boo[i].lost=1;
            printf("\t编号\t书名\t类别\n");
            printf("\t%s\t%s\t%s",boo[i].number,boo[i].name,boo[i].type);
            printf("您需要赔偿的价格为：");
            printf("\t%f",boo[i].price);
        }
    if(flag)
    {
        printf("此图书不存在!\n");

    }
    getchar();

}


int runmenu_reader(book *boo,int n,int choice,char ID[])/*选择读者一级菜单功能执行*/
{
    switch(choice)
    {


        case 1:circulation(boo,n,ID);
            break;

        case 2:seeBorrowed( boo,n,ID);
            break;
        case 3:search(boo,n) ;
            break;

        case 4:lossmanage(boo,n,ID);
            break;

        case 5:aiGame(ID);
            break;

        case 0: break;
    }
    return n;

}

void readerMenu(char ID[])
{
    book boo[NU];/*定义实参一维数组存储图书记录*/
    int choice,n;
    n=readbookFile(boo);/*首先读取文件，记录条数返回赋值给n*/
    if(!n)/*如果原文件为空*/

        printf("图书馆里暂时没有图书\n");


    do
    {
        menureader();/*显示读者菜单*/
        printf("请输入您的选择:");
        scanf("%d",&choice);
        if (choice>=0&&choice<=4)
            n=runmenu_reader(boo,n,choice,ID);/*选择一级读者菜单对应的功能*/
        else
            printf("请输入有效数字!\n");

    }while(choice);

    savebookFile(boo,n);/*将结果存入文件*/


}

