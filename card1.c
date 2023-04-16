#include "card.h"
Log *logCreate()
{
    int n = 0;
    Log *head;
    Log *p1, *p2;
    p1 = p2 = (Log *)malloc(LENLog);
    p1->time.year = 0, p1->time.month = 0, p1->time.day = 0, p1->time.hour = 0, p1->time.minute, p1->money;
    head = NULL;
    while (p1->time.year != 0)
    {
        n = n + 1;
        if (n == 1)
            head = p1;
        else
            p2->next = p1;
        p2 = p1;
        p1 = (Log *)malloc(LENLog);
        p1->time.year = 0, p1->time.month = 0, p1->time.day = 0, p1->time.hour = 0, p1->time.minute, p1->money;
    }
    p2->next = NULL;
    return (head);
}
Log *logExtend(Log *head)
{
    Log *p1 = head;
    if (head != NULL)
    {
        while (p1->next != NULL)
        {
            p1 = p1->next;
        }
        p1 = p1->next = (Log *)malloc(LENLog);
        p1->time.year = 0, p1->time.month = 0, p1->time.day = 0, p1->time.hour = 0, p1->time.minute, p1->money;
    }
    return (p1);
}
Log *logDelete(Log *head, Time detime)
{
    Log *p1 = head;
    Log *p2;
    if ((head->time.year == detime.year) && (head->time.month == detime.month) && (head->time.day == detime.day) && (head->time.hour == detime.hour) && (head->time.minute == detime.minute))
    {
        head = head->next;
        free(p1);
        return (head);
    }
    while (p1->next != NULL)
    {
        p2 = p1->next;
        if ((p1->next->time.year == detime.year) && (p1->next->time.month == detime.month) && (p1->next->time.day == detime.day) && (p1->next->time.hour == detime.hour) && (p1->next->time.minute == detime.minute))
        {
            p1->next = p1->next->next;
            free(p2);
            return (head);
        }
        p1 = p1->next;
    }
    return (head);
} /*
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

     return NULL;


 }*/
Card *cardCreate()
{
    int n = 0;
    Card *head;
    Card *p1, *p2;
    p1 = p2 = (Card *)malloc(LENCard);

    p1->level = 0;
    strcpy(p1->name, "");
    strcpy(p1->number, "");
    strcpy(p1->password, "");
    p1->remaining_sum = 0.0f, p1->total_charge = 0.0f, p1->createTime.year = 0, p1->createTime.month = 0, p1->createTime.day = 0, p1->createTime.hour = 0, p1->createTime.minute = 0;
    p1->validTime.year = 0, p1->validTime.month = 0, p1->validTime.day = 0, p1->validTime.hour = 0, p1->validTime.minute = 0;
    p1->rechargeLog->time.year = 0, p1->rechargeLog->time.month = 0, p1->rechargeLog->time.day = 0, p1->rechargeLog->time.hour = 0, p1->rechargeLog->time.minute = 0, p1->rechargeLog->money = 0.0f;
    p1->consumeLog->time.year = 0, p1->consumeLog->time.month = 0, p1->consumeLog->time.day = 0, p1->consumeLog->time.hour = 0, p1->consumeLog->time.minute = 0, p1->consumeLog->money = 0.0f;
    head = NULL;
    while (p1->level != 9)
    {
        n = n + 1;
        if (n == 1)
            head = p1;
        else
            p2->next = p1;
        p2 = p1;
        p1 = (Card *)malloc(LENCard);

        p1->level = 0;
        strcpy(p1->name, "");
        strcpy(p1->number, "");
        strcpy(p1->password, "");
        p1->remaining_sum = 0.0f, p1->total_charge = 0.0f, p1->createTime.year = 0, p1->createTime.month = 0, p1->createTime.day = 0, p1->createTime.hour = 0, p1->createTime.minute = 0;
        p1->validTime.year = 0, p1->validTime.month = 0, p1->validTime.day = 0, p1->validTime.hour = 0, p1->validTime.minute = 0;
        p1->rechargeLog->time.year = 0, p1->rechargeLog->time.month = 0, p1->rechargeLog->time.day = 0, p1->rechargeLog->time.hour = 0, p1->rechargeLog->time.minute = 0, p1->rechargeLog->money = 0.0f;
        p1->consumeLog->time.year = 0, p1->consumeLog->time.month = 0, p1->consumeLog->time.day = 0, p1->consumeLog->time.hour = 0, p1->consumeLog->time.minute = 0, p1->consumeLog->money = 0.0f;
        p1->isLost = 0;
        head = NULL;
    }
    p2->next = NULL;
    return (head);
}
Card *cardExtend(Card *head)
{
    Card *p1 = head;
    if (head != NULL)
    {
        while (p1->next != NULL)
        {
            p1 = p1->next;
        }
        p1 = p1->next = (Card *)malloc(LENCard);
        p1->level = 0;
        strcpy(p1->name, "");
        strcpy(p1->number, "");
        strcpy(p1->password, "");
        p1->remaining_sum = 0.0f, p1->total_charge = 0.0f, p1->createTime.year = 0, p1->createTime.month = 0, p1->createTime.day = 0, p1->createTime.hour = 0, p1->createTime.minute = 0;
        p1->validTime.year = 0, p1->validTime.month = 0, p1->validTime.day = 0, p1->validTime.hour = 0, p1->validTime.minute = 0;
        p1->rechargeLog->time.year = 0, p1->rechargeLog->time.month = 0, p1->rechargeLog->time.day = 0, p1->rechargeLog->time.hour = 0, p1->rechargeLog->time.minute = 0, p1->rechargeLog->money = 0.0f;
        p1->consumeLog->time.year = 0, p1->consumeLog->time.month = 0, p1->consumeLog->time.day = 0, p1->consumeLog->time.hour = 0, p1->consumeLog->time.minute = 0, p1->consumeLog->money = 0.0f;
        p1->isLost = 0;
    }
    return (p1);
}
Card* cardDelete(char* demessage)
{
    Card *p1 = cards;
    if (p1 != NULL)
    {
        while (p1->next != NULL)
        {
            Card *p2 = p1->next;
            if (strcmp(p1->next->name, demessage) || strcmp(p1->next->number, demessage) == 0)
            {
                p1->next = p1->next->next;
                free(p2);
                return (cards);
            }
            p1 = p1->next;
        }
    }
    else
        return NULL;
} /*
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
 }*/
void cardLost(char* lostmessage)
{
    Card *p1 = cards;
    if (p1 != NULL)
    {
        if ((strcmp(cards->name, lostmessage) == 0) || (strcmp(cards->number, lostmessage) == 0))
        {
            cards->isLost = 1;
            
        }
        while (p1->next != NULL)
        {
            if ((strcmp(p1->name, lostmessage) == 0) || (strcmp(p1->number, lostmessage) == 0))
            {
                p1->isLost = 1;
                
            }
            p1 = p1->next;
        }
    }
}
void write()
{
    FILE *fp;
    if ((fp = fopen("data\\card.txt", "wb")) == NULL)
    {
        printf("File open error\n");
        exit(0);
    }
    while (cards != NULL)
    {
        fwrite(&cards->name, 80, 1, fp);
        fwrite(&cards->number, 40, 1, fp);
        fwrite(&cards->phone, 44, 1, fp);
        fwrite(&cards->password, 60, 1, fp);
        fwrite(&cards->level, 2, 1, fp);
        fwrite(&cards->remaining_sum, 8, 1, fp);
        fwrite(&cards->total_charge, 8, 1, fp);

        fwrite(&cards->createTime.year, 4, 1, fp);
        fwrite(&cards->createTime.month, 4, 1, fp);
        fwrite(&cards->createTime.day, 4, 1, fp);
        fwrite(&cards->createTime.hour, 4, 1, fp);
        fwrite(&cards->createTime.minute, 4, 1, fp);

        fwrite(&cards->validTime.year, 4, 1, fp);
        fwrite(&cards->validTime.month, 4, 1, fp);
        fwrite(&cards->validTime.day, 4, 1, fp);
        fwrite(&cards->validTime.hour, 4, 1, fp);
        fwrite(&cards->validTime.minute, 4, 1, fp);

        fwrite(&cards->isLost, 1, 1, fp);

        while (cards->rechargeLog != NULL)
        {
            fwrite(&cards->rechargeLog->time.year, 4, 1, fp);
            fwrite(&cards->rechargeLog->time.month, 4, 1, fp);
            fwrite(&cards->rechargeLog->time.day, 4, 1, fp);
            fwrite(&cards->rechargeLog->time.hour, 4, 1, fp);
            fwrite(&cards->rechargeLog->time.minute, 4, 1, fp);
            fwrite(&cards->rechargeLog->money, 8, 1, fp);
            cards->rechargeLog = cards->rechargeLog->next;
        }
        while (cards->consumeLog != NULL)
        {
            fwrite(&cards->consumeLog->time.year, 4, 1, fp);
            fwrite(&cards->consumeLog->time.month, 4, 1, fp);
            fwrite(&cards->consumeLog->time.day, 4, 1, fp);
            fwrite(&cards->consumeLog->time.hour, 4, 1, fp);
            fwrite(&cards->consumeLog->time.minute, 4, 1, fp);
            fwrite(&cards->isLost, 1, 1, fp);
            cards->consumeLog = cards->consumeLog->next;
        }

        cards = cards->next;
    }
    fclose(fp);

    if ((fp = fopen("data\\admin.txt", "wb")) == NULL)
    {
        printf("File open error\n");
        exit(0);
    }
    while (admins != NULL)
    {
        fwrite(&admins->username, 80, 1, fp);
        fwrite(&admins->password, 60, 1, fp);
        fwrite(&admins->isSuper, 1, 1, fp);
        admins = admins->next;
    }
    fclose(fp);
}

void read()
{
    FILE *fp;
    if ((fp = fopen("data\\card.txt", "rb")) == NULL)
    {
        printf("File open error\n");
        exit(0);
    }
    while (cards != NULL)
    {
        fread(&cards->name, 80, 1, fp);
        fread(&cards->number, 40, 1, fp);
        fread(&cards->phone, 44, 1, fp);
        fread(&cards->password, 60, 1, fp);
        fread(&cards->level, 2, 1, fp);
        fread(&cards->remaining_sum, 8, 1, fp);
        fread(&cards->total_charge, 8, 1, fp);

        fread(&cards->createTime.year, 4, 1, fp);
        fread(&cards->createTime.month, 4, 1, fp);
        fread(&cards->createTime.day, 4, 1, fp);
        fread(&cards->createTime.hour, 4, 1, fp);
        fread(&cards->createTime.minute, 4, 1, fp);

        fread(&cards->validTime.year, 4, 1, fp);
        fread(&cards->validTime.month, 4, 1, fp);
        fread(&cards->validTime.day, 4, 1, fp);
        fread(&cards->validTime.hour, 4, 1, fp);
        fread(&cards->validTime.minute, 4, 1, fp);

        fread(&cards->isLost, 1, 1, fp);

        while (cards->rechargeLog != NULL)
        {
            fread(&cards->rechargeLog->time.year, 4, 1, fp);
            fread(&cards->rechargeLog->time.month, 4, 1, fp);
            fread(&cards->rechargeLog->time.day, 4, 1, fp);
            fread(&cards->rechargeLog->time.hour, 4, 1, fp);
            fread(&cards->rechargeLog->time.minute, 4, 1, fp);
            fread(&cards->rechargeLog->money, 8, 1, fp);
            cards->rechargeLog = cards->rechargeLog->next;
        }
        while (cards->consumeLog != NULL)
        {
            fread(&cards->consumeLog->time.year, 4, 1, fp);
            fread(&cards->consumeLog->time.month, 4, 1, fp);
            fread(&cards->consumeLog->time.day, 4, 1, fp);
            fread(&cards->consumeLog->time.hour, 4, 1, fp);
            fread(&cards->consumeLog->time.minute, 4, 1, fp);
            fread(&cards->isLost, 1, 1, fp);
            cards->consumeLog = cards->consumeLog->next;
        }

        cards = cards->next;
    }
    fclose(fp);
    if ((fp = fopen("data\\admin.txt", "wb")) == NULL)
    {
        printf("File open error\n");
        exit(0);
    }
    while (admins!= NULL)
    {
        fread(&admins->username, 80, 1, fp);
        fread(&admins->password, 60, 1, fp);
        fread(&admins->isSuper, 1, 1, fp);
        admins = admins->next;
    }
    fclose(fp);

}


Admin *adminSearch(char *s)
{
}