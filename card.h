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
    float remaining_sum,comsumption;  //�����Ѷ�
    Time createTime,validTime;  //����ʱ�䣬��Чʱ��
    bool isLost;
    Log *rechargeLog,*comsumeLog;   //��ֵ�����Ѽ�¼
    struct Card *next;
};
typedef struct Card Card;
Card* cardCreate();
Card* cardDelete(Card*, char*);     //�����Ż��û�����ɾ�������˿���
Card* cardExtend(Card*);
void cardSort(Card*);   //���ΰ��ؼ�������
Card* cardSearch(Card*, char*);    //�����š��û����ֲ���
Card* cardFix(Card*);   //��Ϣ�޸�
Card* cardLost(Card*,char*);
bool cardLogIn(char*, char*); //��Ա����¼
void cardRecharge(Card*, float);    //��ֵ���ѣ�����
void cardComsume(Card*, float);     //���ѣ�����
void cardFind(Card*, char*); //�һ�����

void logIn();   //ϵͳ��¼
void backUp();  //���ݱ���
void restore(); //���ݻָ�
void read();    //�ļ���ȡ
void write();   //�ļ�д��

#endif