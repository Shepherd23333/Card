#ifndef _CARD_H_
#define _CARD_H_

//details in README.md
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
Log* logCreate();   //card3
Log* logDelete(Log*, Time); //card1
Log* logExtend(Log*);   //card1
void logPrint(Log*);
void logPrints(Log*);
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
Card *cards;    //global Card list
Card* cardCreate(); //card3
Card* cardDelete(char*); //card1     
Card* cardExtend();    //card1
void cardPrint(Card*);
void cardPrints();
Card* cardSort();    //card2
Card* cardSearch(Card*, ...);   //card1   
Card* cardSearchs(int*, ...);    
void cardFix(Card*);   //card4
void cardSignUp(); 
Card* cardLogIn(char*, char*);   //card3
void cardLogOut();
bool cardIdentify(Card*);
void cardUpdatePhone(Card*);
void cardUpdatePassword(Card*);
void cardLost(char*); //card1
void cardFind(char*);    //card2
void cardRecharge(Card*, double);   //card3
void cardConsume(Card*, double);    //card2

char* getstr(); //system
bool isTime(int,int,int,int,int);   //system
typedef struct Admin{
    char *username,*password;
    bool isSuper;
    struct Admin *next;
}Admin;
Admin *admins;  //global Admin list
Admin* adminCreate();   //card3
Admin* adminDelete(char*);  //card3
Admin* adminExtend(); //card2
Admin* adminSearch(char*);  //card2  
void adminFix(Admin*);
void adminLogIn();   //system
void SASignUp();
void adminSignUp();
void adminLogOut();

bool isLoggedIn,isCardLoggedIn;
int authority;
void logOut();
bool authorize();   //system
void backUp();
void restore();
void read();    //card1
void write();   //card1
void initialize();  //system
void System();  //system

#endif