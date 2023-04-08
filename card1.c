#include"card.h"
Log *logCreate()   
{
    int n=0;
    Log *head;
    Log *p1,*p2;
    p1=p2=(Log*)malloc(LENLog);
    p1->time.year=0,p1->time.month=0,p1->time.day=0,p1->time.hour=0,p1->time.minute,p1->money;
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
        p1->time.year=0,p1->time.month=0,p1->time.day=0,p1->time.hour=0,p1->time.minute,p1->money;
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
    p1->time.year=0,p1->time.month=0,p1->time.day=0,p1->time.hour=0,p1->time.minute,p1->money;
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
        if((p1->next->time.year==detime.year)&&(p1->next->time.month==detime.month)&&(p1->next->time.day==detime.day)&&(p1->next->time.hour==detime.hour)&&(p1->next->time.minute==detime.minute))
        {
            p1->next=p1->next->next;
            free(p2);
            return (head);
        }
        p1=p1->next;
    }
    return (head);
}/*
Log* logSearch(Log* head,...)
{
    Log* p1=head;
    va_list val;
    va_start(val,head);
    if(head!=NULL)
    {
        if(num==5)
        {
            va_start(val,5);
            if((head->time.year==va_arg(val,int))&&(head->time.month==va_arg(val,int))&&(head->time.day==va_arg(val,int))&&(head->time.hour==va_arg(val,int))&&(head->time.minute==va_arg(val,int)))
            {
                //printf("%d年%d月%d日%d:%d\n",head->time.year,head->time.month,head->time.day,head->time.hour,head->time.minute);
                return (head);
            }
            while(p1->next!=NULL)
        {
            if((p1->time.year==va_arg(val,int))&&(p1->time.month==va_arg(val,int))&&(p1->time.day==va_arg(val,int))&&(p1->time.hour==va_arg(val,int))&&(p1->time.minute==va_arg(val,int)))
            {
                return p1;
            }
            p1=p1->next;
        }

        }
        if(num==1)
        {
            va_start(val,1);
            if(head->money==va_arg(val,double))
            {
                return (head);
            }
            
            while(p1->next!=NULL)
            {
                if(p1->money==va_arg(val,double))
                {
                    return (p1);
                }
                p1=p1->next;
            }
        }
        return (head);
    }
    else
    //printf("用户为空\n");
    return NULL;


}*/
Card* cardCreate()
{
    int n=0;
    Card *head;
    Card *p1,*p2;
    p1=p2=(Card*)malloc(LENCard);
    
    p1->level=0;
    strcpy(p1->name,"");
    strcpy(p1->number,"");
    strcpy(p1->password,"");
    p1->remaining_sum=0.0f,p1->comsumption=0.0f,p1->createTime.year=0,p1->createTime.month=0,p1->createTime.day=0,p1->createTime.hour=0,p1->createTime.minute=0;
    p1->validTime.year=0,p1->validTime.month=0,p1->validTime.day=0,p1->validTime.hour=0, p1->validTime.minute=0;
    p1->rechargeLog->time.year=0,p1->rechargeLog->time.month=0,p1->rechargeLog->time.day=0,p1->rechargeLog->time.hour=0,p1->rechargeLog->time.minute=0,p1->rechargeLog->money=0.0f;
    p1->comsumeLog->time.year=0,p1->comsumeLog->time.month=0,p1->comsumeLog->time.day=0,p1->comsumeLog->time.hour=0,p1->comsumeLog->time.minute=0,p1->comsumeLog->money=0.0f;
    head=NULL;
    while(p1->level!=9)
    {
        n=n+1;
        if(n==1)
        head=p1;
        else
        p2->next=p1;
        p2=p1;
        p1=(Card*)malloc(LENCard);
       
        p1->level=0;
        strcpy(p1->name,"");
        strcpy(p1->number,"");
        strcpy(p1->password,"");
        p1->remaining_sum=0.0f,p1->comsumption=0.0f,p1->createTime.year=0,p1->createTime.month=0,p1->createTime.day=0,p1->createTime.hour=0,p1->createTime.minute=0;
        p1->validTime.year=0,p1->validTime.month=0,p1->validTime.day=0,p1->validTime.hour=0, p1->validTime.minute=0;
        p1->rechargeLog->time.year=0,p1->rechargeLog->time.month=0,p1->rechargeLog->time.day=0,p1->rechargeLog->time.hour=0,p1->rechargeLog->time.minute=0,p1->rechargeLog->money=0.0f;
        p1->comsumeLog->time.year=0,p1->comsumeLog->time.month=0,p1->comsumeLog->time.day=0,p1->comsumeLog->time.hour=0,p1->comsumeLog->time.minute=0,p1->comsumeLog->money=0.0f;
        p1->isLost=0;
    head=NULL;
    }
    p2->next=NULL;
    return (head);
}
Card* cardExtend(Card* head)
{
    Card* p1=head;
    if(head!=NULL)
    {
        while(p1->next!=NULL)
    {
        p1=p1->next;
    }
    p1=p1->next=(Card*)malloc(LENCard);
    p1->level=0;
    strcpy(p1->name,"");
    strcpy(p1->number,"");
    strcpy(p1->password,"");
    p1->remaining_sum=0.0f,p1->comsumption=0.0f,p1->createTime.year=0,p1->createTime.month=0,p1->createTime.day=0,p1->createTime.hour=0,p1->createTime.minute=0;
    p1->validTime.year=0,p1->validTime.month=0,p1->validTime.day=0,p1->validTime.hour=0, p1->validTime.minute=0;
    p1->rechargeLog->time.year=0,p1->rechargeLog->time.month=0,p1->rechargeLog->time.day=0,p1->rechargeLog->time.hour=0,p1->rechargeLog->time.minute=0,p1->rechargeLog->money=0.0f;
    p1->comsumeLog->time.year=0,p1->comsumeLog->time.month=0,p1->comsumeLog->time.day=0,p1->comsumeLog->time.hour=0,p1->comsumeLog->time.minute=0,p1->comsumeLog->money=0.0f;
    p1->isLost=0;
    } 
    return (head);

}
Card* cardDelete(Card* head,char* demessage)
{
    Card* p1=head;
    if(head!=NULL)
    {
        while(p1->next!=NULL)
        {
            Card* p2=p1->next;
            if(strcmp(p1->next->name,demessage)||strcmp(p1->next->number,demessage)==0)
            {
                p1->next=p1->next->next;
                free(p2);
                return (head);
            }
            p1=p1->next;
        }
            
    }
    else 
    return NULL;
}
Card* cardSearch(Card* head, char* semessage)
{
    Card* p1=head;
    if(head!=NULL)
    {
        if((strcmp(head->name,semessage)==0)||(strcmp(head->number,semessage)==0))
        {
            return head;
        }
        while(p1->next!=NULL)
        {
            if((strcmp(p1->name,semessage)==0)||(strcmp(p1->number,semessage)==0))
            {
                return p1;
            }
            p1=p1->next;
        }
    }
}
Card* cardLost(Card* head, char* lostmessage)
{
    Card* p1=head;
    if(head!=NULL)
    {
        if((strcmp(head->name,lostmessage)==0)||(strcmp(head->number,lostmessage)==0))
        {
            head->isLost=1;
            return head;
        }
        while(p1->next!=NULL)
        {
            if((strcmp(p1->name,lostmessage)==0)||(strcmp(p1->number,lostmessage)==0))
            {
                head->isLost=1;
                return head;
            }
            p1=p1->next;
        }
    }
} 

Admin* adminSearch(Admin* head,char* s){

}