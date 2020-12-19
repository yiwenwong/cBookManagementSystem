//
// Created by 王义文 on 2020-04-22.
//

#include "account.h"
#include <stdio.h>
#include "account.h"
#include <string.h>
#include "mainMenu.h"
#include "readerControl.h"
#include "File.h"



int readerRegister()
{ static account a[100]={"\0","\0"};
    int in;
    char  new_ID[10],new_password[10];
    printf("┏----------------------读者注册------------------------------------┓\n");
    printf("|                     自定义ID:");
    scanf("%s",new_ID);
    printf("|                                                                 |\n");
    printf("|                      自定义密码：");
    scanf("%s",new_password);
    printf("|           输入1确认注册，输入0返回上级菜单                          |\n");
    printf("┗-----------------------------------------------------------------┛\n");
    scanf("%d",&in);
    while (in!=1&&in!=0){
        printf("请输入有效数字！");
        readerRegister();
    }
    if(in==0) {
        return 0;
    } else {
        int n;
        n=readFile(a);
        if(!n)
            n=createFile(a);
        addReader(new_ID, new_password,a);
        printf("注册成功！\n");
        saveFile(a,n+1);
        return 0;

    }
}

void addReader(char * ID,char * pw,account a[]){
    int flag=1,i;
    for ( i = 0; strcmp(a[i].id,"\0")!=0; i++) {
        if(strcmp(a[i].id,ID)==0 ){
            flag=0;
        }
    }
    if(flag){
        strcpy(a[i].id,ID);
        strcpy(a[i].password,pw);
    }
    else{
        printf("用户名已被占用，请重新设置用户名！");
        readerRegister();
    }
}

void readerLog()
{  account a[100];
    int in;
    int	i=0,j=0;
    int m=0;
    char   inID[10],inpassword[10],ch;
    m=readFile(a);


    printf("┏----------------------读者登陆----------------------------------┓\n");
    printf("|                     ID:");
    scanf("%s",inID);
    printf("|                                                                 |\n");
    printf("|                     密码:");

    scanf("%s",inpassword);
    printf("|                                                                 |\n");
    printf("|                                                                 |\n");
    printf("|           输入1确认登陆，输入0返回上级菜单                          |\n");
    printf("┗-----------------------------------------------------------------┛\n");
    scanf("%d",&in);
    while (in!=1&&in!=0){
        printf("请输入有效数字！");
        readerLog();
    }
    if(in==1)
    {
        while (strcmp(a[i].id,inID)!=0||i<m-1)
        {
            i++;
        }
        if(i==m-1)
        {
            printf("用户ID输入错误，请重新输入！\n");
            readerLog();
        }
        else if(strcmp(a[i].password,inpassword)==0){
            printf("登陆成功！\n");
            readerMenu(a[i].id);
        }
        else{
            printf("密码错误，请重新输入！\n");
            readerLog();
        }
    }

}

