#include"card.h"
#define LEN sizeof(Log)
Log *logCreate()   
{
    int n=0;
    Log *head;
    Log *p1,*p2;
    int n=0;
    p1=p2=(Log*)malloc(LEN);
    scanf("%d %d %d %d %d %f",&p1->time.year,&p1->time.month,&p1->time.day,&p1->time.hour,&p1->time.minute,&p1->money);
    head=NULL;
    while(p1->time.year!=0)
    {
        n=n+1;
        if(n==1)
        head=p1;
        else
        p2->next=p1;
        p2=p1;
        p1=(Log*)malloc(LEN);
        scanf("%d %d %d %d %d %f",&p1->time.year,&p1->time.month,&p1->time.day,&p1->time.hour,&p1->time.minute,&p1->money);
    }
    p2->next=NULL;
    return (head);
}