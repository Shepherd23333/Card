#ifndef _CARD_H_
#define _CARD_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
struct Time{
    int year, month, day, hour, minute;
};
typedef struct Time Time;

struct Log{
    Time time;
    float money;
    struct Log *next;
};
typedef struct Log Log;
Log* logCreate();
Log* logDelete(Log*, Time);
Log* logExtend(Log*);
Log* logSearch(Log*, Time);
Log* logFix(Log*,Log*);

struct Card{
    char *name;
    char *number;
    char *password; 
    short level;
    float remaining_sum,comsumption;  //余额，消费额
    Time createTime,validTime;  //创建时间，有效时间
    bool isLost;
    Log *rechargeLog,*comsumeLog;   //充值、消费记录
    struct Card *next;
};
typedef struct Card Card;
Card* cardCreate();
Card* cardDelete(Card*, char*);     //按卡号或用户名字删除，即退卡等
Card* cardExtend(Card*);
void cardSort(Card*);   //依次按关键词排序
Card* cardSearch(Card*, char*);    //按卡号、用户名字查找
Card* cardFix(Card*);   //信息修改
Card* cardLost(Card*,char*);
bool cardLogIn(char*, char*); //会员卡登录
void cardRecharge(Card*, float);    //充值续费，升级
void cardComsume(Card*, float);     //消费，打折
void cardFind(Card*, char*); //找回密码

void logIn();   //系统登录
void backUp();  //数据备份
void restore(); //数据恢复
void read();    //文件读取
void write();   //文件写入

#endif