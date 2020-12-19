//
// Created by 王义文 on 2020-04-22.
//

#ifndef UNTITLED_ACCOUNT_H
#define UNTITLED_ACCOUNT_H
#define sizeAcc sizeof(account)
#define NUM 100
typedef struct account{
    char id[10]; //读者id
    char password[10]; //密码
}account;
int readerRegister();
void addReader(char * ID, char * pw,account a[]);
void readerLog();
int readAcc(account  *acc );
#endif //UNTITLED_ACCOUNT_H

