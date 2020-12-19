//
// Created by 王义文 on 2020-04-22.
//


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "AIgame.h"
#include "readerControl.h"

void aiGame(char ID[])
{
    int hard,flag;
    aiMenu();
    scanf("%d",&hard);
    while (hard<0||hard>3)
    {
        printf("请输入有效数字");
        scanf("%d",&hard);
    }
    if(hard==0) {
        readerMenu(ID);
    }
    flag=game(hard,ID);
    if(flag==0)
    {
        readerMenu(ID);
    }
    else aiGame(ID);

}

void aiMenu(){
    printf("┏-----------------欢迎来到AI猜数游戏--------------------------------┓\n");
    printf("|                  1.0-9                                          |\n");
    printf("|                  2.0-99                                         |\n");
    printf("|                  3.0-999                                        |\n");
    printf("|                  0.退出                                         |\n");
    printf("┗-----------------------------------------------------------------┛\n");
    printf("请输入数字选择难度：");
}

int game(int hard,char ID[])
{
    int times,i,max;
    int flag1;
    int flag2;
    switch (hard){
        case 1: max=9;
            break;
        case 2: max=99;
            break;
        case 3: max=999;
            break;
    }
    printf("您当前的难度等级0-%d",max);
    printf("请输入想要猜的次数，0返回上一级\n你的输入：");
    scanf("%d",&times);
    while (times<0){
        printf("请输入有效数字！");
        scanf("%d",&times);
    }
    if(times==0) {
        aiGame(ID);
        return 1;
    }
    else {
        printf("现在开始猜数\n");
        for(i=0;i<times;i++){
            int guessNumber,answer;
            printf("剩余次数%d，请输入数字(0-%d,-1返回难度选择）：",times-i,max);
            scanf("%d",&guessNumber);
            while (guessNumber<-1||guessNumber>=10*hard){
                printf("请输入有效数字！");
                scanf("%d",&guessNumber);
            }
            printf("\n");
            if(guessNumber!=-1){
                srand((int)time(NULL));
                answer=rand()%(10*hard);
                if(guessNumber==answer) {
                    printf("输入的是%d,恭喜你，猜对了", guessNumber);
                    printf("是否继续？\n1.继续，0.退出\n");


                    scanf("%d",&flag1);
                    while (flag1<0||flag1>1){
                        printf("请输入有效数字！");
                        scanf("%d",&flag1);
                    }
                    return flag1;
                }
                else if(guessNumber<answer){
                    printf("输入的是%d,没有猜中，猜小了",guessNumber);
                }
                else
                    printf("输入的是%d,没有猜中，猜大了",guessNumber);

            } else{aiGame(ID);}

        }
        printf("没有猜中，请再接再厉");
        printf("是否继续？\n1.继续，0.退出\n");

        scanf("%d",&flag2);
        while (flag2<0||flag2>1){
            printf("请输入有效数字！");
            scanf("%d",&flag2);
        }
        return flag2;
    }

}
