//
// Created by 王义文 on 2020-04-22.
//


#include <stdio.h>
#include <string.h>
#include "adminMenu.h"
#include "AIgame.h"
#include "book.h"
#include "timenow.h"



void borrowed(book *boo,int n,char ID[] )//借书
{
    int i;
    char * b;
    printf("输入要借书的书名：");
    scanf("%s",&b);
    for(i=0;i<n;i++)
    {
        if(strcmp(boo[i].name,b)==0&&boo[i].flag==1)//判断书名是否存在
        {
            printf("您要借的书是：\n");
            printf("\t编号\t书名\t类别\n");
            printf("\t%s\t%s\t%s\t%d",boo[i].number,boo[i].name,boo[i].type);



            printf("借书成功");
            boo[i].flag=0;
            boo[i].id[0]=*ID;
            boo[i].boday=now();



        }



        printf("\n");
        printf("\n");
        printf("\n");
    }
    if(i==n)printf("图书库存为0！\n");

}




void back(book *boo,int n)//归还
{

    int i;
    char * d;
    printf("输入要还书的编号：");
    scanf("%s",&d);
    for(i=0;i<n;i++)
    {
        if(strcmp(boo[i].number,d)==0)
        {
            if(boo[i].flag==0)
            {
                printf("您要归还的书是：\n");
                printf("\t编号\t书名\t类别\t \n");
                printf("\t%s\t%s\t%s\t%d",boo[i].number,boo[i].name,boo[i].type);

                boo[i].flag=1;
                printf("还书成功!\n");
            }
            else {
                printf("编号输入错误！请重新输入。\n");
                back(boo,n);

            }
        }
    }

    if(i==n)
    {
        printf("此图书不存在");

    }

    printf("\n");
    printf("\n");
    printf("\n");
}



void searchname(book *boo,int n)//按种类查询
{
    char s1[10];
    int flag=1,i;
    printf("请输入要查询的书名：");
    scanf("%s",s1);
    printf("\t编号\t书名\t类别\t借阅状态\n");
    for(i=0;i<n;i++)
        if(strcmp(s1,boo[i].name)==0)
        {
            flag=0;
            printf("\t%s\t%s\t%s\t%d",boo[i].number,boo[i].name,boo[i].type,boo[i].flag);
        }
    if(flag)
    {
        printf("图书不存在\n");

    }
    getchar();

}


void searchtype(book *boo,int n)//按种类查询
{
    char s2[10];
    int flag=1,i;
    printf("请输入要查询的书的种类：");
    scanf("%s",s2);
    printf("\t编号\t书名\t类别\t借阅状态\n");
    for(i=0;i<n;i++)
        if(strcmp(s2,boo[i].type)==0)
        {
            flag=0;
            printf("\t%s\t%s\t%s\t%d",boo[i].number,boo[i].name,boo[i].type,boo[i].flag);
        }
    if(flag)
    {
        printf("图书不存在\n");

    }
    getchar();

}



