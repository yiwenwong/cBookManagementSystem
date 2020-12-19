//
// Created by 王义文 on 2020-04-22.
//

#include <stdio.h>
#include <stdlib.h>
#include "mainMenu.h"
#include "adminLog.h"
#include "account.h"


int main()
{int m;
    do{
        showMenu();
        m=chooseMenu();
    }while(m!=0);
    return 0;
}
void showMenu(){
    printf("┏-----------------M  E  N  U--------------------------------------┓\n");
    printf("|                  1.读者登陆                                      |\n");
    printf("|                  2.管理员登录                                    |\n");
    printf("|                  3.读者注册                                      |\n");
    printf("|                  0.退出系统                                      |\n");
    printf("┗-----------------------------------------------------------------┛\n");
    printf("请输入数字执行相应操作：");

}


int chooseMenu()
{
    int choose;
    scanf("%d",&choose);
    switch (choose){
        case 1:readerLog();
            break;
        case 2:adminLog();
            break;
        case 3:readerRegister();
            break;
        case 0:break;
        default:printf("请输入有效数字！");
            break;
    }
    return choose;

}
