//
// Created by 王义文 on 2020-04-22.
//


#include "adminMenu.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"bookFile.h"


#define N 20


static int n;      //全局变量
book ook[N];
#define sizeBoo sizeof(book);



void showadminMenu()
{
    printf("---------------------图书馆-------------------------");
    printf("\n 1.增加图书\n");
    printf("\n 2.删除图书\n");
    printf("\n 3.修改图书\n");
    printf("\n 4.查询图书\n");
    printf("\n 5.丢失图书\n");
    printf("\n 6.返回上一层");
    printf("\n 请按键选择，回车确定\n");
    printf("----------------------------------------------------");
}






void choice()
{
    int choose;

    showadminMenu();
    while(scanf("%d",&choose) != 1 || choose < 1 || choose > 6)
    {
        printf("你输入的值是错误的！按任意键返回");
        getchar();
        showadminMenu();
        fflush(stdin); //清除缓冲区
    }

    switch(choose)
    {
        case 1:add();
            break;
        case 2:del();
            break;
        case 3:revise();
            break;
        case 4:inquiry();
            break;
        case 5:lost();
            break;

        case 6:
            break;
    }
}





int add()
{
    int flag;
    int amount;
    int type;
    int i;
    char number[10];
    int s;
    s=readbookFile(ook);
    if(!s)
    {
        s=createbookFile(ook,N);
    }
    if(n>=N)
    {
        printf("书库已经存满，无法继续存入!\n");
        return 0;
    }


    printf("请输入同名书的个数");
    scanf("%d",&amount);
    printf("请输入书的编号：");
    scanf("%10s",ook[n].number);
    printf("请输入书的名字：");
    scanf("%20s",ook[n].name);
    printf("请输入书的地址：");
    scanf("%d",&ook[n].address);
    printf("请输入书的类别：(1.小说类 2.杂志类 3.文学类)");
    while(scanf("%d",&type)!= 1 || type < 1 || type >3)
    {
        printf("你输入的有错误");
        fflush(stdin);
    }
    switch(type)
    {
        case 1:
            ook[n].type = "novel";
            break;
        case 2:
            ook[n].type = "magazine";
            break;
        case 3:ook[n].type = "programming";
            break;
    }
    printf("输入书的价格：");
    scanf("%lf",&ook[n].price);
    printf("输入书的入库日期(格式为20000101)：");
    scanf("%d",&ook[n].time);
    ook[n].time=0;
    if(amount > 1)
    {

        for(i=0;i<amount;i++)
        {
            ook[n+1]=ook[n];
            printf("书的编码：");
            scanf("%10s",&number);
            strcpy(ook[n+1].number,number);
            n++;


        }
    }
    else
    {n++;}
    printf("书籍添加成功");
    savebookFile(ook,amount);
    printf("按数字1继续添加，按数字0返回上一级");
    scanf("%d",&flag);
    while (flag!=0&&flag!=1)
    {
        printf("请输入有效数字");
        scanf("%d",&flag);
    }
    if(flag==1) {
        add();
    }
    return 0;
}











void del()
{
    int i,j;
    char index[10];
    int s;
    s=readbookFile(ook);
    if(!s)
    {
        s=createbookFile(ook,N);
    }
    printf("要删除的书的编号：");
    scanf("10%s",index);
    for(i=0;i<n;i++)
    {
        if(strcmp(ook[i].number,index) == 0)
            break;
    }
    for(j=i;j <N;j++)
    {
        ook[j]=ook[j+1];
    }
    savebookFile(ook,1);
    n--;
}







void minmune1()
{
    printf("(1)按种类查询");
    printf("(2)按序号查询");
    printf("(3)按书名查询");
}





void inquiry()
{
    int ooo;
    int i;
    char ccc[20];
    char mmm[10];
    char type[10];
    int s;
    s=readbookFile(ook);
    if(!s)
    {
        s=createbookFile(ook,N);
    }
    minmune1();
    scanf("%d",&ooo);
    if(ooo < 1 || ooo > 3)
    {
        printf("你输入的数字是错误的,按任意键返回");
        getchar();
        inquiry();
        fflush(stdin);
    }
    switch(ooo)
    {
        case 1:
            printf("请输入书的种类：novel,magazine,programming");
            scanf("%10s",&type);
            for(i=0;i<n;i++)
            {
                if(strcmp(ook[i].name,type) == 0)
                {
                    char *place;
                    switch(ook[i].address)
                    {
                        case 1:place="三牌楼";
                            break;

                        case 2:place="仙林";
                            break;

                    }

                    printf("馆藏地址 %s 借阅状态 %d 编号 %10s 书名 %20s 类别 %s 借阅次数 %d 价格 %f 入库日期 %d",place,ook[i].flag ,ook[i].number,ook[i].name,ook[i].type,ook[i].time,ook[i].price,ook[i].innday);
                }
            }
            if(i>=N)
                printf("你找的书不存在");
            break;
        case 2:
            printf("请输入书的编号：");
            scanf("%10s",mmm);
            for(i=0;i<n;i++)
            {
                if(strcmp(ook[i].number,mmm) == 0)
                    break;
            }
            if(i>=N)
                printf("你找的书不存在");
            else

            {
                {
                    char *place;
                    switch(ook[i].address)
                    {
                        case 1:place="三牌楼";
                            break;

                        case 2:place="仙林";
                            break;

                    }
                    printf("馆藏地址 %s 借阅状态 %d 编号 %10s 书名 %20s 类别 %s 借阅次数 %d 价格 %f 入库日期 %d",place,ook[i].flag ,ook[i].number,ook[i].name,ook[i].type,ook[i].time,ook[i].price,ook[i].innday);

                }
            }
            break;
        case 3:
            printf("请输入书的书名：");
            scanf("%20s",&ccc);
            for(i=0;i<n;i++)
            {
                if(strcmp(ook[i].name,ccc) == 0)
                {
                    char *place;
                    switch(ook[i].address)
                    {
                        case 1:place="三牌楼";
                            break;

                        case 2:place="仙林";
                            break;

                    }
                    printf("馆藏地址 %s 借阅状态 %d 编号 %10s 书名 %20s 类别 %s 借阅次数 %d 价格 %f 入库日期 %d",place,ook[i].flag ,ook[i].number,ook[i].name,ook[i].type,ook[i].time,ook[i].price,ook[i].innday);
                }
            }
            if(i>=N)
            {printf("你找的书不存在");}
            break;




    }


}







void minmune2()
{
    printf("(1)价格");
    printf("(2)馆藏地址");
}



void revise()
{
    int i;
    int index2;
    double price;
    char name[20];
    int address;
    int s;
    s=readbookFile(ook);
    if(!s)
    {
        s=createbookFile(ook,N);
    }
    printf("要修改的书的书名：");
    scanf("%20s",name);
    for(i=0;i<n;i++)
    {
        if(strcmp(ook[i].name,name) == 0)
            break;
    }
    minmune2();
    scanf("%d",&index2);
    if(index2 < 1 || index2 > 3)
    {
        printf("你输入的数字是错误的,按任意键返回");
        getchar();
        minmune2();
        fflush(stdin);
    }
    switch(index2)
    {
        case 1:
            printf("输入修改后的价格:");
            scanf("%lf",&price);
            ook[i].price=price;

            break;
        case 2:
            printf("输入修改后的馆藏地址\n");
            printf("三牌楼请输入1，仙林请输入2\n");
            scanf("%d",&address);
            while(address!=1&&address!=2)
            {
                printf("请输入有效数字：");
                scanf("%d",&address);

            }
            ook[i].address=address;
            break;

    }
    savebookFile(ook,1);

}

void lost()
{
    int i;
    int s;
    s=readbookFile(ook);
    if(!s)
    {
        s=createbookFile(ook,N);
    }
    printf("以下是丢失的图书清单");
    for(i=0;i<n;i++)
    {

        if(ook[i].lost)
        {
            printf("账号 %s 编号 %s 书名 %s 价格 %f ",ook[i].id,ook[i].number,ook[i].name,ook[i].price);

        }

    }

}



