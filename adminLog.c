//
// Created by 王义文 on 2020-04-22.
//


#include <stdio.h>
#include <string.h>
#include "mainMenu.h"
#include "adminLog.h"
#include "adminMenu.h"



static char password[]="8888888888\0";
void adminLog()
{
    char   inpassword[20];
    char ch;
    int j=0;

    int in,i=0;
    printf("┏----------------------管理员登陆----------------------------------┓\n");
    printf("|                     密码:");
    scanf("%s",inpassword);
    printf("|                                                                 |\n");
    printf("|                                                                 |\n");
    printf("|           输入1确认登陆，输入0返回上级菜单                          |\n");
    printf("┗-----------------------------------------------------------------┛\n");
    scanf("%d",&in);
    while (in!=1&&in!=0)
    {
        printf("请输入有效数字！");
        adminLog();
    }
    if(in==1){
        if(strcmp(password,inpassword)==0){
            if(password=="8888888888\0") {
                printf("请修改密码：");
                scanf("%s", password);
            }
            choice();
        }
        else
            adminLog();

    }
}

