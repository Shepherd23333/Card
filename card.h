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
struct card{
    char *name;
    char *number;
    short level;
    float remaining_sum,comsumption;  //余额，消费额
    Time createTime,validTime;  //创建时间，有效时间
    bool isLost;
    Log *rechargeLog,*comsumeLog;
    struct Card *next;
};
typedef struct Card Card;
Card* cardCreate();
Card* cardDelete(Card*, char*);
Card* cardExtend(Card*);
void cardSort(Card*);
Card* cardSearch(Card*, char*);
void cardRecharge(Card*, float);
void cardComsume(Card*, float);

#endif