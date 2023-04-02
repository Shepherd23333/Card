#ifndef _CARD_H_
#define _CARD_H_

//所有变量及函数的内容在README.md
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include<stdarg.h>
struct Time{
    int year, month, day, hour, minute;
};
typedef struct Time Time;
void setTime(Time,int,int,int,int,int);

struct Log{
    Time time;
    float money;
    struct Log *next;
};
typedef struct Log Log;
Log* logCreate();
Log* logDelete(Log*, Time);
Log* logExtend(Log*);
Log* logSearch(Log*, int,...);
Log* logSearchs(Log*, int,...);
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
Card *cards;
Card* cardCreate();
Card* cardDelete(Card*, char*);     
Card* cardExtend(Card*);
void cardSort(Card*);   
Card* cardSearch(Card*, char*);    
Card* cardSearchs(Card*, char*);    
Card* cardFix(Card*);
Card* cardLost(Card*,char*);
bool cardLogIn(char*, char*);
void cardRecharge(Card*, float); 
void cardComsume(Card*, float);
void cardFind(Card*, char*);

struct Admin{
    char *username,*password;
    bool isSuper;
    struct Admin *next;
};
typedef struct Admin Admin;
Admin *admins;
Admin* adminCreate();
Admin* adminDelete(Admin*, char*);     
Admin* adminExtend(Admin*);
Admin* adminSearch(Admin*, char*);    

int authority;
bool authorize();
void logIn();
void logOut();
void backUp();
void restore();
void read();
void write();

#endif