#include"card.h"
void cardRecharge(Card** head, double money)  
{
    if (*head == NULL)  
    {  
        return;  
    }

    Card* card = *head;  
    while (card != NULL)  
    {  
        if (card->level == 1)  
        {  
            if (card->remaining_sum >= money)  
            {  
                card->remaining_sum -= money;  
                return;  
            }  
            else  
            {  
                return;  
            }  
        }  
        else  
        {  
            double levelPrice = 100;  
            double levelBalance = card->remaining_sum;  
            card->remaining_sum = card->level * levelPrice + levelBalance;  
            if (card->remaining_sum < 0)  
            {  
                printf("Error: level1 card balance is insufficient.\n");  
                return;  
            }  
            card = card->next;  
        }  
    }  

}

Card *cardLogIn(char *numorphone, char *password)
{
    Card *c = NULL;
    int q = 0;
    
    Card *ptr = cards;
    for (; ptr != NULL; ptr = ptr->next)
    {
        if (strcmp(ptr->number, numorphone) == 0 || strcmp(ptr->phone, numorphone) == 0)
        { 
            c = ptr;
            break;
        }
    }
    if (c == NULL)
    {
        printf("");
        return NULL;
    }
    else if (strcmp(c->password, password) != 0)
    {
        printf("");
        c = NULL;
        printf("");
        scanf("%d",&q);
        switch (q)
        {
        case 1:
            printf(" \n");
            password = getstr();
            if (strcmp(c->password, password) != 0)
            {
                printf("");
                return NULL;
            }
            else
            {
                printf("");
                return c;
            }
            break;
        case 0:
            return NULL;
            break;
        }
    }
    else
    {
        printf("");
        return c;
    }
}

Admin* adminCreate()
{
    Admin *head=(Admin*)malloc(LENAdmin);
    head->username=(char*)malloc(sizeof(char));
    head->password=(char*)malloc(sizeof(char));
    head->isSuper=0;
    head->next=NULL;
    return head;
}

Admin* adminDelete(char* u)  
{
    Admin *p1 = admins;  
    if(p1 == NULL)  
    {  
        return NULL;  
    }

    while(p1 != NULL)  
    {  
        Card *p2 = p1->next;  
        if(!strcmp(p1->next->username,u)||!strcmp(p1->next->password,u))  
        {  
            p1->next = p1->next->next;  
            free(p2);  
            return admins;  
        }  
        p1 = p1->next;  
    }

    return NULL;  

}