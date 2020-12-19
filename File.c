//
// Created by 王义文 on 2020-04-22.
//

#include "File.h"
#include <stdio.h>
#include <stdlib.h>
#include "account.h"

/*函数功能：将文件中内容读出置于数组中
函数参数：形参是结构体指针
函数返回值：从文件中读出的实际记录条数
*/
int readFile(account *acc )
{
    FILE *fp;
    int i=0;
    if((fp=fopen("~/account.dat", "rb")) == NULL)   /*以读方式打开指定文件*/
    {   printf("文件不存在，请先创建:\n");   /*若打开失败输出提示信息*/
        return 0;                               /*然后返回0*/
    }
    fread(&acc[i],sizeAcc,1,fp);                   /*读出第一条记录*/
    while(!feof(fp))                            /*文件未结束时循环*/
    {
        i++;
        fread(&acc[i],sizeAcc,1,fp);               /*再读出下一条记录*/
    }
    fclose(fp);                                /*关闭文件*/
    return i;                                  /*返回记录条数*/
}
/*函数功能：将结构体数组内容写入文件
函数参数：两个形参分别是结构体指针、实际记录条数
函数返回值：无返回值
*/
void saveFile(account *acc ,int n)
{      FILE *fp;
    if((fp=fopen("~/account.dat", "wb")) == NULL) /*以写方式打开指定文件*/
    {
        printf("无法打开文件 !\n");            /*若打开失败，输出提示信息*/
        exit(0);                              /*然后退出*/
    }
    fwrite(acc,sizeAcc,n,fp);                     /*一次性向文件写入n条记录*/
    fclose(fp) ;                               /*关闭文件*/
}
/*函数功能：建立初始的数据文件
函数参数：形参分别为结构体指针
函数返回值：返回写入文件的记录条数
*/
int  createFile(account *acc)
{  FILE *fp;

    if((fp=fopen("~/account.dat", "wb")) == NULL) /*指定文件名，以写方式打开*/
    {   printf("无法打开文件 !\n");            /*若打开失败，输出提示信息*/
        exit(0);                              /*然后退出*/
    }
    printf("请输入账号\' 信息:\n");
    fwrite(acc,sizeAcc,1,fp);                   /*将读入的所有记录全写入文件*/
    fclose(fp);                              /*关闭文件*/
    return 1;                               /*返回记录条数*/
}
