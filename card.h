#ifndef _CARD_H_
#define _CARD_H_

//details in README.md
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include<windows.h>
#include<math.h>
#include<conio.h>
typedef struct Time{
    unsigned year, month, day, hour, minute;
}Time;
Time t0;
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
void logPrint(Log*);//card2
void logPrints(Log*);//card2
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
Card *cards,c0;    //global Card list
//Card* cardCreate(); //card3
Card* cardDelete(char*); //card1     
Card* cardExtend();    //card1
void cardPrint(Card*);  //card2
void cardPrints();     //card2
Card* cardSort();    //card2
Card* cardSearch(Card);   //card1
Card* cardSearchs(Card);     
void cardFix(Card*);   //card4
void cardSignUp(); //card1
Card* cardLogIn(char*, char*);   //card3
void cardLogOut();//card1
bool cardIdentify(Card*);//card1
void cardUpdatePhone(Card*);//card2
void cardUpdatePassword(Card*);//card2
void cardLost(char*); //card1
void cardFind(char*);    //card2
void cardRecharge(Card*, double);   //card3
void cardConsume(Card*, double);    //card2

char* getstr(); //system
char* getPassword();    //system
bool isTime(int,int,int,int,int);   //system
char* md5C(char*);  //md5

typedef struct Admin{
    char *username,*password;
    bool isSuper;
    struct Admin *next;
}Admin;
#define LENAdmin sizeof(Admin)
Admin *admins;  //global Admin list
//Admin* adminCreate();//card3
Admin* adminDelete(char*);  //card3
Admin* adminExtend(); //card2
Admin* adminSearch(char*);  //card1  
void adminFix(Admin*);
void adminLogIn();   //system
void SASignUp();    //system
void adminSignUp();//card1
void adminLogOut(); //system

bool isLoggedIn,isCardLoggedIn;
int authority;
void logOut();//card1
bool authorize();//system
void backUp();//card1
void restore();//card1
void read_file();//card1
void write_file();//card1
void initialize();  //system
void System();  //system
void menu();//card2
#endif