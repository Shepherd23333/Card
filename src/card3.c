#include "card.h"
void cardRecharge(Card *head, double money){
    if (head == NULL)
        return;
    Card *card = head;
    card->remaining_sum += money;
    card->total_charge += money;
    Log*l1;
    l1=logExtend(head->rechargeLog);
    l1->money=money;
        enum{year,month,day,hour,minute};
        time_t t = time(NULL);
        struct tm *lt = localtime(&t);
        char str_time[20];
        sprintf(str_time, "%04d-%02d-%02d %02d:%02d",
                lt->tm_year + 1900, lt->tm_mon + 1, lt->tm_mday,
                lt->tm_hour, lt->tm_min);
        sscanf(str_time, "%d-%d-%d %d:%d",
               &l1->time.year, &l1->time.month, &l1->time.day, &l1->time.hour, &l1->time.minute);
    double l[]={0,712,2048,8848,23333,65536,114514,524288,1919810,1e100};
    for(int i=0;i<9;i++)
        if(l[i]<=card->remaining_sum&&card->remaining_sum<l[i+1])
            card->level=i+1;
}
Card *cardLogIn(char *numorphone, char *password){
    Card *c = NULL;
    int q = 0;
    Card *ptr = cards;
    for (; ptr != NULL; ptr = ptr->next)
        if (strcmp(ptr->number, numorphone) == 0 || strcmp(ptr->phone, numorphone) == 0){//you wen ti
            c = ptr;
            break;
        }
    if (c == NULL){
        printf("");
        return NULL;
    }else if (strcmp(c->password, password) != 0){
        printf("");
        c = NULL;
        printf("");
        scanf("%d", &q);
        switch (q){
        case 1:
            printf(" \n");
            password = getstr();
            if (strcmp(c->password, password) != 0){
                printf("");
                return NULL;
            }else{
                printf("");
                return c;
            }
            break;
        case 0:
            return NULL;
            break;
        }
    }else{
        printf("");
        return c;
    }
}
Admin *adminDelete(char *u){
    Admin *admins = NULL;
    if (admins == NULL)
        return NULL;
    if (strcmp(u, "") == 0)
        return NULL;
    Admin *p1 = admins;
    Admin *p2 = NULL;
    while (p1 != NULL)
        p2 = p1;
        p1 = p1->next;
    if (p2 == NULL)
        return NULL;
    p2->next = p2->next->next;
    free(p2);
    return admins;
}