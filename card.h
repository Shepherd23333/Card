#ifndef _CARD_H_
#define _CARD_H_

//所有变量及函数的内容在README.md
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
    float remaining_sum,comsumption;
    Time createTime,validTime;
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
Card* cardFix(Card*);
Card* cardLost(Card*,char*);
bool cardLogIn(char*, char*);
void cardRecharge(Card*, float); 
void cardComsume(Card*, float);
void cardFind(Card*, char*);

void logIn();
void backUp();
void restore();
void read();
void write();

#endif