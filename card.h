#ifndef _CARD_H_
#define _CARD_H_

//所有变量及函数的内容在README.md
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include<stdarg.h>
#include<windows.h>
#include<math.h>
typedef struct Time{
    unsigned year, month, day, hour, minute;
}Time;
int timeComp(Time,Time);    //card4
typedef struct Log{
    Time time;
    double money;
    struct Log *next;
}Log;
#define LENLog sizeof(Log)
Log* logCreate();   //card1
Log* logDelete(Log*, Time); //card1
Log* logExtend(Log*);   //card1
void logPrint(Log*);
Log* logSearch(Log*, ...);  //card1
Log* logSearchs(Log*, int*,...);
void logFix(Log*);  //card4

typedef struct Card{
    char *name,*number,*phone,*password; 
    short level;
    double remaining_sum,total_charge;
    Time createTime,validTime;
    bool isLost;
    Log *rechargeLog,*consumeLog;
    struct Card *next;
}Card;
#define LENCard sizeof(Card)
Card *cards;    //全局Card动态链表，用于存放用户数据
Card* cardCreate(); //card1
Card* cardDelete(Card*, char*); //card1     
Card* cardExtend(Card*);    //card1
void cardPrint(Card*);
Card* cardSort(Card*,char*);    //card2
Card* cardSearch(Card*, ...);   //card1   
Card* cardSearchs(Card*, int*, ...);    
void cardFix(Card*);   //card4
Card* cardSignUp(Card*); 
bool cardLogIn(char*, char*);   //card3
void cardLogOut();
bool identify(Card*);
void cardNewPhone(Card*,char*);
void cardLost(Card*,char*); //card1
void cardFind(Card*, char*);    //card2
void cardRecharge(Card*, double);   //card3
void cardConsume(Card*, double);    //card2

char* getstr(); //system
bool isTime(int,int,int,int,int);   //system
typedef struct Admin{
    char *username,*password;
    bool isSuper;
    struct Admin *next;
}Admin;
Admin *admins;  //全局Admin动态链表，用于存放管理员数据
Admin* adminCreate();   //card3
Admin* adminDelete(Admin*, char*);  //card3
Admin* adminExtend(Admin*); //card2
Admin* adminSearch(Admin*, char*);  //card2  
Admin* adminFix(Admin*);
void adminLogIn();   //system
Admin* SASignUp(Admin*);
Admin* adminSignUp(Admin*);
void adminLogOut();

bool isLoggedIn;
int authority;
void logOut();
bool authorize();   //system
void backUp();
void restore();
void read();
void write();
void initialize();
void System();

#endif