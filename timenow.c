//
// Created by 王义文 on 2020-04-22.
//

#include"timenow.h"
#include<stdio.h>
#include<time.h>
#include<stdint.h>
#include<stdlib.h>

int now(){


    unsigned long long a = 0;
    char timeStr[9];


    time_t timer;
    struct tm *tblock;
    time(&timer);
    tblock = gmtime(&timer);


    a = (tblock->tm_year+1900)*100;
    a = (a+tblock->tm_mon+1)*100;
    a = (a+tblock->tm_mday)*100;

    sprintf(timeStr, "%llu", a);

    printf("现在时间是 %d 年 %d 月 %d 日 .\n",tblock->tm_year+1900, tblock->tm_mon+1, tblock->tm_mday);


    return a;
}


int distance(int now,int b){
    int flag=1;
    if (((now/10000)%400==0)||((now/10000)%100!=0&&(now/10000)%4==0))
        flag=0;




    if((now/10000)==(b/10000)){
        if((now/100)==(b/100)){
            if(now-b<=3)
                return now-b;
            else
                return -1;
        }
        else if(now%100==1||now%100==2||now%100==3){
            switch(b/100%100){
                case 1: case 3:case 5: case 7: case 8: case 10:
                    if((31-(b%100)+(now%10))<=3)
                        return (31-(b%100)+(now%10));
                    else
                        return -1;
                    break;
                case 4:case 6:case 9:case 11:
                    if((30-(b%100)+(now%10))<=3)
                        return (30-(b%100)+(now%10));
                    else
                        return -1;
                    break;
                case 2:
                    if(flag==0)
                        if((29-(b%100)+(now%10))<=3)
                            return (29-(b%100)+(now%10));
                        else
                            return -1;
                    else
                        if((28-(b%100)+(now%10))<=3)
                        return (28-(b%100)+(now%10));
                        else
                        return -1;
            }


      }
            return -1;

    }
    else  if((now/10000)==(b/10000)+1){
            if ((31-(b%100)+(now%10))<=3)
                return (31-(b%100)+(now%10));
            else
                return -1;
            }
             return 100;
}