#ifndef _CARD_H_
#define _CARD_H_

//所有变量及函数的内容在README.md
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include<stdarg.h>
#include<windows.h>
char* getstr(); //system
typedef struct Time{
    int year, month, day, hour, minute;
}Time;
void setTime(Time,int,int,int,int,int); //card4

typedef struct Log{
    Time time;
    double money;
    struct Log *next;
}Log;
#define LENLog sizeof(Log)
Log* logCreate();
Log* logDelete(Log*, Time);
Log* logExtend(Log*);
Log* logSearch(Log*, ...);
Log* logSearchs(Log*, ...);
Log* logFix(Log*);  //card4

typedef struct Card{
    char *name;
    char *number;
    char *password; 
    short level;
    double remaining_sum,comsumption;
    Time createTime,validTime;
    bool isLost;
    Log *rechargeLog,*comsumeLog;
    struct Card *next;
}Card;
#define LENCard sizeof(Card)
Card *cards;
Card* cardCreate();
Card* cardDelete(Card*, char*);     
Card* cardExtend(Card*);
void cardSort(Card*);   //card2.c
Card* cardSearch(Card*, char*);    
Card* cardSearchs(Card*, char*);    
Card* cardFix(Card*);   //card4
Card* cardLost(Card*,char*);
bool cardLogIn(char*, char*);//card3.c
void cardRecharge(Card*, double); //card3.c
void cardConsume(Card*, double);//card2.c
void cardFind(Card*, char*);//card2.c

typedef struct Admin{
    char *username,*password;
    bool isSuper;
    struct Admin *next;
}Admin;
Admin *admins;
Admin* adminCreate();//card3.c
Admin* adminDelete(Admin*, char*);   //card3.c  
Admin* adminExtend(Admin*);//card2.c
Admin* adminSearch(Admin*, char*); //card2.c   

bool isLoggedIn;
int authority;
bool authorize();   //system
void logIn();   //system
void logOut();
void backUp();
void restore();
void read();
void write();

#endif