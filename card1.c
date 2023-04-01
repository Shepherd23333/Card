#include"card.h"
#define LENLog sizeof(Log)
Log *logCreate()   
{
    int n=0;
    Log *head;
    Log *p1,*p2;
    int n=0;
    p1=p2=(Log*)malloc(LENLog);
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
        p1=(Log*)malloc(LENLog);
        scanf("%d %d %d %d %d %f",&p1->time.year,&p1->time.month,&p1->time.day,&p1->time.hour,&p1->time.minute,&p1->money);
    }
    p2->next=NULL;
    return (head);
}
Log* logExtend(Log* head)
{
    Log* p1=head;
    if(head!=NULL)
    {
        while(p1->next!=NULL)
    {
        p1=p1->next;
    }
    p1=p1->next=(Log*)malloc(LENLog);
    scanf("%d %d %d %d %d %f",&p1->time.year,&p1->time.month,&p1->time.day,&p1->time.hour,&p1->time.minute,&p1->money);
    } 
    return (head);
}
Log* logDelete(Log* head,Time detime)
{
    Log* p1=head;
    Log* p2;
    if((head->time.year==detime.year)&&(head->time.month==detime.month)&&(head->time.day==detime.day)&&(head->time.hour==detime.hour)&&(head->time.minute==detime.minute))
    {
        head=head->next;
        free(p1);
        return (head);
    }
    while(p1->next!=NULL)
    {
        p2=p1->next;
        if((p1->time.year==detime.year)&&(p1->time.month==detime.month)&&(p1->time.day==detime.day)&&(p1->time.hour==detime.hour)&&(p1->time.minute==detime.minute))
        {
            p1=p1->next->next;
            free(p2);
            return (head);
        }
        p1=p1->next;
    }
    return (head);
}
Log* logSearch(Log* head,Time setime)
{
    Log* p1=head;
    if(head!=NULL)
    {
        if((head->time.year==setime.year)&&(head->time.month==setime.month)&&(head->time.day==setime.day)&&(head->time.hour==setime.hour)&&(head->time.minute==setime.minute))
        {
            printf("%dÄê%dÔÂ%dÈÕ%d:%d\n",head->time.year,head->time.month,head->time.day,head->time.hour,head->time.minute);
            return (head);
        }
        while(p1->next!=NULL)
        {
            if((p1->time.year==setime.year)&&(p1->time.month==setime.month)&&(p1->time.day==setime.day)&&(p1->time.hour==setime.hour)&&(p1->time.minute==setime.minute))
            {
                return p1;
            }
        }
    }
}
#define LENCard sizeof(Card)
