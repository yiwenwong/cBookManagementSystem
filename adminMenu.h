//
// Created by 王义文 on 2020-04-22.
//

#ifndef UNTITLED_ADMINMENU_H
#define UNTITLED_ADMINMENU_H
struct Book
{
    int address;    /*书的馆藏地址（根据值判断）*/
    int flag;       /*借阅状态（根据值判断）*/
    char number[10];    /*书的编号*/
    char name[20];  /*书名*/
    char * type ;     /*书的类别*/
    int time;       /*借阅次数*/
    double price; /*书的价格*/
    int lost;     //图书丢失登记
    int innday;     /*入库日期*/
    int backday;    /*归还日期*/
    int boday;
    char id[10];    /*借读者的账号*/
};
typedef struct Book book;
void adminMenu();//管理员函数菜单
void showadminMenu();
void lost();
int add();             //图书的增加
void del();           //图书的删除
void revise();      //图书的修改
void inquiry();     //图书查询
void minmune1();      //图书查询的两个种类
void minmune2();    //要修改的选项
void choice();     //对图书进行的动作
#endif //UNTITLED_ADMINMENU_H
