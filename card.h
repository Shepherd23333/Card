#ifndef _CARD_H_
#define _CARD_H_

//���б�����������������README.md
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include<stdarg.h>
#include<windows.h>
#include<math.h>
typedef struct Time{
    int year, month, day, hour, minute;
}Time;
void setTime(Time*,int,int,int,int,int); //card4
int timeComp(Time,Time);
typedef struct Log{
    Time time;
    double money;
    struct Log *next;
}Log;
#define LENLog sizeof(Log)
Log* logCreate();//card1
Log* logDelete(Log*, Time);//card1
Log* logExtend(Log*);//card1
Log* logSearch(Log*, ...);//card1
Log* logSearchs(Log*, ...);
Log* logFix(Log*);  //card4

typedef struct Card{
    char *name,*number,*phone,*password; 
    short level;
    double remaining_sum,consumption;
    Time createTime,validTime;
    bool isLost;
    Log *rechargeLog,*consumeLog;
    struct Card *next;
}Card;
#define LENCard sizeof(Card)
Card *cards;    //ȫ��Card��̬�������ڴ���û�����
Card* cardCreate();//card1
Card* cardDelete(Card*, char*);//card1     
Card* cardExtend(Card*);//card1
Card* cardSort(Card*,char*);   //card2.c
Card* cardSearch(Card*, ...); //card1   
Card* cardSearchs(Card*, ...);    
Card* cardFix(Card*);   //card4
Card* cardSignUp(Card*); 
bool cardLogIn(char*, char*);//card3.c
void cardNewPhone(Card*,char*);
void cardLost(Card*,char*);//card1
void cardFind(Card*, char*);//card2.c
void cardRecharge(Card*, double); //card3.c
void cardConsume(Card*, double);//card2.c

char* getstr(); //system
typedef struct Admin{
    char *username,*password;
    bool isSuper;
    struct Admin *next;
}Admin;
Admin *admins;  //ȫ��Admin��̬�������ڴ�Ź���Ա����
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