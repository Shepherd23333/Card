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
Log* logSearch(Log* head,int num,...)
{
    Log* p1=head;
    va_list val;
    
    if(head!=NULL)
    {
        if(num==5)
        {
            va_start(val,5);
            if((head->time.year==va_arg(val,int))&&(head->time.month==va_arg(val,int))&&(head->time.day==va_arg(val,int))&&(head->time.hour==va_arg(val,int))&&(head->time.minute==va_arg(val,int)))
            {
                printf("%d年%d月%d日%d:%d\n",head->time.year,head->time.month,head->time.day,head->time.hour,head->time.minute);
                return (head);
            }
            while(p1->next!=NULL)
        {
            if((p1->time.year==va_arg(val,int))&&(p1->time.month==va_arg(val,int))&&(p1->time.day==va_arg(val,int))&&(p1->time.hour==va_arg(val,int))&&(p1->time.minute==va_arg(val,int)))
            {
                return p1;
            }
            p1=p1->next;
            return (head);
        }

        }
        if(num==1)
        {
            va_start(val,1);
            if(head->money==va_arg(val,float))
            {
                return (head);
            }
            
            while(p1->next!=NULL)
            {
                if(p1->money==va_arg(val,float))
                {
                    return (p1);
                }
                p1=p1->next;
                return (head);
            }
        }
        return (head);
    }
    else
    printf("用户为空\n");


}
#define LENCard sizeof(Card)
Card* cardCreate()
{
    int n=0;
    Card *head;
    Card *p1,*p2;
    int n=0;
    p1=p2=(Card*)malloc(LENCard);
    
    scanf("%d",&p1->level);
    gets(p1->name);
    gets(p1->number);
    gets(p1->password);
    scanf("%f,%f,%d,%d,%d,%d,%d",&p1->remaining_sum,&p1->comsumption,&p1->createTime.year,&p1->createTime.month,&p1->createTime.day,&p1->createTime.hour,&p1->createTime.minute);
    scanf("%d,%d,%d,%d,%d",&p1->validTime.year,&p1->validTime.month,&p1->validTime.day,&p1->validTime.hour,&    p1->validTime.minute);
    scanf("%d %d %d %d %d %f",&p1->rechargeLog->time.year,&p1->rechargeLog->time.month,&p1->rechargeLog->time.day,&p1->rechargeLog->time.hour,&p1->rechargeLog->time.minute,&p1->rechargeLog->money);
    scanf("%d %d %d %d %d %f",&p1->comsumeLog->time.year,&p1->comsumeLog->time.month,&p1->comsumeLog->time.day,&p1->comsumeLog->time.hour,&p1->comsumeLog->time.minute,&p1->comsumeLog->money);
    head=NULL;
    while(p1->level!=9)
    {
        n=n+1;
        if(n==1)
        head=p1;
        else
        p2->next=p1;
        p2=p1;
        p1=(Log*)malloc(LENCard);
       
        scanf("%d",&p1->level);
        gets(p1->name);
        gets(p1->number);
        gets(p1->password);
        scanf("%f,%f,%d,%d,%d,%d,%d",&p1->remaining_sum,&p1->comsumption,&p1->createTime.year,&p1->createTime.month,&p1->createTime.day,&p1->createTime.hour,&p1->createTime.minute);
        scanf("%d,%d,%d,%d,%d",&p1->validTime.year,&p1->validTime.month,&p1->validTime.day,&p1->validTime.hour,&    p1->validTime.minute);
        scanf("%d %d %d %d %d %f",&p1->rechargeLog->time.year,&p1->rechargeLog->time.month,&p1->rechargeLog->time.day,&p1->rechargeLog->time.hour,&p1->rechargeLog->time.minute,&p1->rechargeLog->money);
        scanf("%d %d %d %d %d %f",&p1->comsumeLog->time.year,&p1->comsumeLog->time.month,&p1->comsumeLog->time.day,&p1->comsumeLog->time.hour,&p1->comsumeLog->time.minute,&p1->comsumeLog->money);
        
    }
    p2->next=NULL;
    return (head);
}
