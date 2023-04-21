#include "card.h"
void logPrint(Log *l)
{
    if (l == NULL)
        return;
    printf("\u4ea4\u6613\u65f6\u95f4\uff1a%u\\%02u\\%02u %02u:%02u\n", l->time.year, l->time.month, l->time.day, l->time.hour, l->time.minute);
    printf("\u4ea4\u6613\u91d1\u989d\uff1a%.2lf\n", l->money);
}
void logPrints(Log *head)
{
    if (head == NULL)
        return;
    Log *cur = head;
    while (cur != NULL)
    {
        printf("\u4ea4\u6613\u65f6\u95f4\uff1a%u\\%02u\\%02u %02u:%02u\n", cur->time.year, cur->time.month, cur->time.day, cur->time.hour, cur->time.minute);
        printf("\u4ea4\u6613\u91d1\u989d\uff1a%.2lf\n", cur->money);
        cur = cur->next;
    }
}
void cardPrint(Card *c) // card2
{
    if (c == NULL)
    {
        printf("\u8be5\u4f1a\u5458\u4e0d\u5b58\u5728\n");
        return;
    }
    else
    {
        Card *cur = c;
        printf("\u59d3\u540d\uff1a %s\n", cur->name);
        printf("\u5361\u53f7\uff1a %s\n", cur->number);
        printf("\u624b\u673a\u53f7\uff1a %s\n", cur->phone);
        printf("\u5bc6\u7801\uff1a %s\n", cur->password);
        printf("\u7b49\u7ea7\uff1a %d\n", cur->level);
        printf("\u4f59\u989d\uff1a %.2lf\n", cur->remaining_sum);
        printf("\u603b\u5145\u503c\uff1a %.2lf\n", cur->total_charge);
        printf("\u603b\u6d88\u8d39\uff1a %.2lf\n", cur->total_charge - cur->remaining_sum);
        printf("\u521b\u5efa\u65f6\u95f4\uff1a %u\\%02u\\%02u\\%02u\\%02u\n", cur->createTime.year, cur->createTime.month, cur->createTime.day, cur->createTime.hour, cur->createTime.minute);
        printf("\u6709\u6548\u65f6\u95f4\uff1a %u\\%02u\\%02u\\%02u\\%02u\n", cur->createTime.year, cur->createTime.month, cur->createTime.day, cur->createTime.hour, cur->createTime.minute);
        printf("\u662f\u5426\u6302\u5931\uff1a ");
        if (cur->isLost)
            printf("\u662f\n");
        else
            printf("\u5426\n");
        printf("\u6d88\u8d39\u8bb0\u5f55\n");
        Log *q = cur->consumeLog;
        while (q != NULL)
        {
            printf("  \u65f6\u95f4:%u\\%02u\\%02u\\%02u\\%02u,\u91d1\u989d: %d\n", q->time.year, q->time.month, q->time.day, q->time.hour, q->time.minute, q->money);
            q = q->next;
        }
        printf("\n");
        printf("\u5145\u503c\u8bb0\u5f55\uff1a\n");
        Log *w = cur->rechargeLog;
        while (w != NULL)
        {
            printf(" \u65f6\u95f4:\\%02u\\%02u\\%02u\\%02u,\u91d1\u989d: %d\n", w->time.year, w->time.month, w->time.day, w->time.hour, w->time.minute, w->money);
            w = w->next;
        }
        printf("\n");
    }
}

void cardPrints()
{
    if (cards == NULL)
        return;
    Card *cur = cards;
    while (cur != NULL)
    {
        printf("\u59d3\u540d\uff1a %s\n", cur->name);
        printf("\u5361\u53f7\uff1a %s\n", cur->number);
        printf("\u624b\u673a\u53f7\uff1a %s\n", cur->phone);
        printf("\u5bc6\u7801\uff1a %s\n", cur->password);
        printf("\u7b49\u7ea7\uff1a %d\n", cur->level);
        printf("\u4f59\u989d\uff1a %.2lf\n", cur->remaining_sum);
        printf("\u603b\u5145\u503c\uff1a %.2lf\n", cur->total_charge);
        printf("\u603b\u6d88\u8d39\uff1a %.2lf\n", cur->total_charge - cur->remaining_sum);
        printf("\u521b\u5efa\u65f6\u95f4\uff1a %u\\%02u\\%02u\\%02u\\%02u\n", cur->createTime.year, cur->createTime.month, cur->createTime.day, cur->createTime.hour, cur->createTime.minute);
        printf("\u6709\u6548\u65f6\u95f4\uff1a %u\\%02u\\%02u\\%02u\\%02u\n", cur->createTime.year, cur->createTime.month, cur->createTime.day, cur->createTime.hour, cur->createTime.minute);
        printf("\u662f\u5426\u6302\u5931\uff1a ");
        if (cur->isLost)
            printf("\u662f\n");
        else
            printf("\u5426\n");
        printf("\n");
        Log *q = cur->consumeLog;
        while (q != NULL)
        {
            printf("  \u65f6\u95f4:\\%02u\\%02u\\%02u\\%02u,\u91d1\u989d: %d\n", q->time.year, q->time.month, q->time.day, q->time.hour, q->time.minute, q->money);
            q = q->next;
        }
        printf("\n");
        cur = cur->next;
    }
    printf("");
    Log *w = cur->rechargeLog;
    while (w != NULL)
    {
        printf("  \u65f6\u95f4:\\%02u\\%02u\\%02u\\%02u,\u91d1\u989d: %d\n", w->time.year, w->time.month, w->time.day, w->time.hour, w->time.minute, w->money);
        w = w->next;
    }
    printf("\n");
    cur = cur->next;
}

Card *cardSort()
{
    printf("\u8bf7\u9009\u62e9\u5347\u5e8f\u6216\u964d\u5e8f\u6392\u5217\uff080\u8868\u793a\u5347\u5e8f\uff0c1\u8868\u793a\u964d\u5e8f\uff09\n");
    int turn, sortNum = 0;
    scanf("%d", &turn);
    printf("\u8bf7\u9009\u62e9\u6309\u4ee5\u4e0b\u54ea\u79cd\u65b9\u5f0f\u6392\u5e8f\uff08\u53ef\u4ee5\u591a\u9009\uff09\n");
    printf("1.\u59d3\u540d      2.\u5361\u53f7\n");
    printf("3.\u624b\u673a\u53f7    4.\u7b49\u7ea7\n");
    printf("5.\u7f34\u8d39\u603b\u989d  6.\u6d88\u8d39\u91d1\u989d\n");
    printf("7.\u5361\u5185\u4f59\u989d\n");
    int sortIndex[10];
    while (scanf("%d", &sortIndex[sortNum]) != EOF)
    {
        sortNum++;
    }
    if (cards == NULL || sortIndex == NULL || sortNum == 0)
        return cards;
    Card *arr[10000];
    int len = 0;
    Card *cur = cards;
    while (cur != NULL)
    {
        arr[len++] = cur;
        cur = cur->next;
    }
    for (int i = 0; i < sortNum; i++)
    {

        switch (sortIndex[i])
        {
        case 1: // byname
            for (int i = 0; i < len; i++)
            {
                for (int j = 0; j < len - i - 1; j++)
                {
                    if (strcmp(arr[j]->name, arr[j + 1]->name) > 0)
                    {
                        Card *tmp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = tmp;
                    }
                }
            }
            break;
        case 2: // bynumber
            for (int i = 0; i < len; i++)
            {
                for (int j = 0; j < len - i - 1; j++)
                {
                    if (strcmp(arr[j]->number, arr[j + 1]->number) > 0)
                    {
                        Card *tmp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = tmp;
                    }
                }
            }
            break;
        case 3: // byphone
            for (int i = 0; i < len; i++)
            {
                for (int j = 0; j < len - i - 1; j++)
                {
                    if (strcmp(arr[j]->phone, arr[j + 1]->phone) > 0)
                    {
                        Card *tmp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = tmp;
                    }
                }
            }
            break;
        case 4: // bylevel
            for (int i = 0; i < len; i++)
            {
                for (int j = 0; j < len - i - 1; j++)
                {
                    if (arr[j]->level > arr[j + 1]->level)
                    {
                        Card *tmp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = tmp;
                    }
                }
            }
            break;
        case 5: // bytotal_charge
            for (int i = 0; i < len; i++)
            {
                for (int j = 0; j < len - i - 1; j++)
                {
                    if (arr[j]->total_charge > arr[j + 1]->total_charge)
                    {
                        Card *tmp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = tmp;
                    }
                }
            }
            break;
        case 6: // bycost
            for (int i = 0; i < len; i++)
            {
                for (int j = 0; j < len - i - 1; j++)
                {
                    if (arr[j]->total_charge - arr[j]->remaining_sum > arr[j + 1]->total_charge - arr[j + 1]->remaining_sum)
                    {
                        Card *tmp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = tmp;
                    }
                }
            }
            break;

        case 7: // byremaining_sum
            for (int i = 0; i < len; i++)
            {
                for (int j = 0; j < len - i - 1; j++)
                {
                    if (arr[j]->remaining_sum > arr[j + 1]->remaining_sum)
                    {
                        Card *tmp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = tmp;
                    }
                }
            }
            break;
        default:
            printf("\u65e0\u6cd5\u8bc6\u522b\u7684\u6392\u5e8f\u9009\u9879\uff1a%d\n", sortIndex[i]);
            break;
        }
    }

    Card *head = arr[0];
    cur = arr[0];
    if (turn == 0)
    {
        for (int i = 1; i < len; i++)
        {
            cur->next = arr[i];
            cur = cur->next;
        }
        cur->next = NULL;
        return head;
    }
    else
    {
        for (int i = len - 1; i > 0; i--)
        {
            cur->next = arr[i];
            cur = cur->next;
        }
        cur->next = NULL;
        return head;
    }
}

void cardFind(char *c) // card2
{
    Card *p = c;
    if (p->isLost != 1)
    {
        printf("\u6b64\u5361\u672a\u8fdb\u884c\u6302\u5931\uff0c\u65e0\u6cd5\u8fdb\u884c\u627e\u56de\u64cd\u4f5c\n");
    }
    else if (cardIdentify(p))
    {
        p->isLost = 0;
    }
    else
    {
        printf("\u672a\u901a\u8fc7\u9a8c\u8bc1\uff0c\u65e0\u6cd5\u8fdb\u884c\u627e\u56de\u64cd\u4f5c\n");
    }
}
void cardConsume(Card *c, double m)
{
    Card *p = c;
    double cost = m;
    system("cls");
    int e = p->level;
    switch (e)
    {
    case 0: // 1
        printf("\u60a8\u7684\u4f1a\u5458\u5361\u5df2\u7ecf\u7ea7");
        printf("\u672c\u6b21\u5b9e\u9645\u6d88\u8d39%.2f\u5143\uff01", cost);
        cost *= 1;
        if ((p->remaining_sum - cost) < 0)
        {
            printf("\u5bf9\u4e0d\u8d77\uff0c\u4f59\u989d\u4e0d\u8db3\uff0c\u8bf7\u53ca\u65f6\u5145\u503c\uff01");
            getchar();
            menu();
        }
        p->remaining_sum -= cost;
        break;
    case 1: // 0.898

        break;
    case 2: // 0.844

        break;
    case 3: // 0.807

        break;
    case 4: // 0.78

        break;
    case 5: // 0.758

        break;
    case 6: // 0.74

        break;
    case 7: // 0.725

        break;
    case 8: // 0.712

        break;
    }
    if (p->level >= 5) // short level
    {
        printf("\u60a8\u7684\u4f1a\u5458\u5361\u5df2\u7ecf\u4e94\u7ea7\uff0c\u672c\u6b21\u6d88\u8d399\u6298\u4f18\u60e0\u3002\n");
        printf("\u672c\u6b21\u5b9e\u9645\u6d88\u8d39%.2f\u5143\uff01", cost * 0.9);
        cost *= 0.9;
        if ((p->remaining_sum - cost) < 0)
        {
            printf("\u5bf9\u4e0d\u8d77\uff0c\u4f59\u989d\u4e0d\u8db3\uff0c\u8bf7\u53ca\u65f6\u5145\u503c\uff01");
            getchar();
            menu();
        }
        p->remaining_sum -= cost;
        getchar();
    }
    else
    {
        if ((p->remaining_sum - cost) < 0)
        {
            printf("\u5bf9\u4e0d\u8d77\uff0c\u4f59\u989d\u4e0d\u8db3\uff0c\u8bf7\u53ca\u65f6\u5145\u503c\uff01");
            getchar();
            menu();
        }

        p->remaining_sum -= cost;
    }
    printf("\u7ed3\u7b97\u6210\u529f\uff01");
    system("pause");
    system("cls");
    getch();
}
Admin *adminExtend() // card2
{
    Admin *p1 = admins;
    if (admins != NULL)
    {
        while (p1->next != NULL)
            p1 = p1->next;
        p1->next = (Admin *)calloc(1, LENAdmin);
    }
    return (p1->next);
}

void cardUpdatePhone(Card *c)
{
    Card *p = c, t = c0;
    if (cardIdentify(p))
    {
        printf("\u8bf7\u8f93\u5165\u65b0\u624b\u673a\u53f7\uff1a\n");
        char *s = getstr();
        memcpy(t.phone, s, sizeof(s));
        if (s[0] != 'c' || strlen(s) == 1 || strspn(s + 1, "0123456789") != strlen(s + 1))
            printf("\u9519\u8bef\uff1a\u975e\u6cd5\u6570\u636e\uff01\n");
        else if (!cardSearch(t))
        {
            strcpy(c->number, s);
            printf("\u4fee\u6539\u6210\u529f\uff01\n");
        }
        else
            printf("\u9519\u8bef\uff1a\u8be5\u5361\u53f7\u5df2\u5b58\u5728\uff01\n");
    }
}
void cardUpdatePassword(Card *c)
{

    if (cardIdentify(c))
    {
        printf("\u8bf7\u8f93\u5165\u65b0\u5bc6\u7801\uff1a\n");
        char *s = getstr();
        strcpy(c->password, s);
        printf("\u4fee\u6539\u6210\u529f\uff01\n");
    }
}

void menu()
{
    printf("-----------------\u83dc\u5355\u7ba1\u7406----------------\n");
    printf("      1.\u65b0\u4f1a\u5458\u6ce8\u518c       2.\u767b\u5f55\n");
    printf("      3.\u8f93\u51fa\u4fe1\u606f         4.\u67e5\u8be2\u4fe1\u606f\n");
    printf("      5.\u6570\u636e\u6392\u5e8f         6.\u6570\u636e\u7edf\u8ba1\n");
    printf("      7.\u7cfb\u7edf\u7ef4\u62a4         0.\u9000\u51fa\n");
    printf("----------\u6b22\u8fce\u4f7f\u7528\u4f1a\u5458\u5361\u8ba1\u8d39\u7cfb\u7edf----------\n"); // ????????
    int n = 0, aa = 0;
    printf("\u8bf7\u9009\u62e9\u529f\u80fd\uff1a");
    scanf("%d", &n);
    if (n == 0)
    {
        adminLogOut();
        return;
    }
    char *numorphone;
    char *password;
    Card *c;
    int a = 0;
    Log *l1 = c->consumeLog; // right?
    Log *l2 = c->rechargeLog;
    double m, k;
    switch (n)
    {
    case 1: // cardSignUp
        cardSignUp();
        break;
    case 2: // cardLogIn
        printf("\u8bf7\u8f93\u5165\u4f1a\u5458\u5361\u5361\u53f7\u6216\u624b\u673a\u53f7\uff1a \n");
        numorphone = getstr();
        printf("\u8bf7\u8f93\u5165\u4f1a\u5458\u5361\u5bc6\u7801\uff1a \n");
        password = getstr();
        Card *c = cardLogIn(numorphone, password);
        if (!c)
        {
            printf("\u767b\u5f55\u5931\u8d25\uff01");
            break;
        }
        else
        {
            printf("\u8bf7\u9009\u62e9\u8981\u8fdb\u884c\u7684\u64cd\u4f5c\uff1a \n");
            printf("1.\u4fee\u6539\u4fe1\u606f   2.\u6d88\u8d39\n");
            printf("3.\u5145\u503c       4.\u6302\u5931\n");
            printf("5.\u627e\u56de       6.\u9000\u5361\n");
            printf("7.\u6362\u624b\u673a\u53f7   8.\u66f4\u6539\u5bc6\u7801\n");
            printf("0.\u9000\u51fa\n");
            scanf("%d", &a);
            switch (a)
            {
            case 1: // cardFix
                cardFix(c);
                break;
            case 2: // consume
                printf("\u8bf7\u8f93\u5165\u82b1\u8d39\u91d1\u989d\uff1a");
                scanf("%lf", &m);
                if (m <= 0)
                {
                    printf("\u6d88\u8d39\u91d1\u989d\u5fc5\u987b\u5927\u4e8e0\uff01\n");
                    return;
                }
                cardConsume(c, m);
                // buqueding
                l1 = logExtend(c->consumeLog);
                break;
            case 3: // recharge
                printf("\u8bf7\u8f93\u5165\u5145\u503c\u91d1\u989d\uff1a");
                scanf("%lf", &k);
                cardRecharge(c, k);
                cardPrint(c);
                if (c->total_charge > 1919810)
                    c->level = 8;
                else if (c->total_charge > 524288 && c->total_charge <= 1919810)
                    c->level = 7;
                else if (c->total_charge > 114514 && c->total_charge <= 524288)
                    c->level = 6;
                else if (c->total_charge > 65536 && c->total_charge <= 114514)
                    c->level = 5;
                else if (c->total_charge > 23333 && c->total_charge <= 65536)
                    c->level = 4;
                else if (c->total_charge > 8848 && c->total_charge <= 23333)
                    c->level = 3;
                else if (c->total_charge > 2048 && c->total_charge <= 8848)
                    c->level = 2;
                else if (c->total_charge > 712 && c->total_charge <= 2048)
                    c->level = 1;
                else
                    c->level = 0;
                l2 = logExtend(c->rechargeLog);
                break;
            case 4: // cardLost
                if (cardIdentify(c))
                {
                    cardLost(c);
                    printf("\u6302\u5931\u6210\u529f\uff0c\u4efb\u610f\u952e\u7ee7\u7eed\uff01");
                    getch();
                }
                break;
            case 5: // cardFind
                if (cardIdentify(c))
                {
                    cardFind(c);
                    printf("\u627e\u56de\u6210\u529f\uff0c\u4efb\u610f\u952e\u7ee7\u7eed\uff01");
                    getch();
                }
                break;
            case 6: // delete
                if (cardIdentify(c))
                {
                    cards = cardDelete(c);
                    printf("\u9000\u5361\u6210\u529f\uff0c\u4efb\u610f\u952e\u7ee7\u7eed\uff01");
                    getch();
                }
                else
                {
                    printf("\u4f1a\u5458\u5361\u8eab\u4efd\u9a8c\u8bc1\u9519\u8bef\uff0c\u8bf7\u91cd\u8bd5\uff01\u4efb\u610f\u952e\u7ee7\u7eed\n");
                    getch();
                    printf("1.\u8bf7\u518d\u6b21\u8fdb\u884c\u8eab\u4efd\u9a8c\u8bc1    2.\u9000\u51fa\u6b64\u9009\u9879\n");
                    scanf("%d", &aa);
                    switch (aa)
                    {
                    case 1:
                        if (cardIdentify(c))
                        {
                            cards = cardDelete(c);
                            printf("\u9000\u5361\u6210\u529f\uff0c\u4efb\u610f\u952e\u7ee7\u7eed\uff01");
                            getch();
                        }
                        else
                        {
                            printf("\u4f1a\u5458\u5361\u8eab\u4efd\u9a8c\u8bc1\u9519\u8bef\uff0c\u4efb\u610f\u952e\u7ee7\u7eed\n");
                            getch();
                        }
                        break;
                    case 2:
                        break;
                    }
                }
            case 7: // update phone
                cardUpdatePhone(c);
            case 8: // update password
                cardUpdatePassword(c);
            case 0:
                cardLogOut();
                printf("\u5df2\u9000\u51fa\u6b64\u8d26\u53f7\n");
                break;
            default:
                printf("ERROR\n");
                break;
            }
            break;
        }
    case 3: // print all
        cardPrints();
        break;
    case 4: // search
        // cardSearch();
        break;
    case 5: // sort
        cards = cardSort();
        cardPrints();
        break;
    case 6: // tongji
        // cardSearchs();
        break;
    case 7: // xitong weihu

        printf("1.\u5bc6\u7801\u7ef4\u62a4\n");
        printf("2.\u6570\u636e\u5907\u4efd\n");
        printf("3.\u6570\u636e\u6062\u590d\n");
        printf("0.\u9000\u51fa\n");
        printf("\u8bf7\u9009\u62e9\u529f\u80fd\n");
        scanf("%d", &aa);
        switch (aa)
        {
        case 1: // mima weihu
            printf("\u8bf7\u8f93\u5165\u5361\u53f7\u6216\u624b\u673a\u53f7\n");
            numorphone = getstr();
            cardFix(numorphone);
            printf("\u5bc6\u7801\u7ef4\u62a4\u6210\u529f\uff0c\u4efb\u610f\u952e\u7ee7\u7eed\uff01\n");
            getch();
            break;
        case 2: // backup
            backUp();
            printf("\u6570\u636e\u5907\u4efd\u6210\u529f\uff0c\u4efb\u610f\u952e\u7ee7\u7eed\uff01\n");
            getch();
            break;
        case 3: // restore
            restore();
            printf("\u6570\u636e\u6062\u590d\u6210\u529f\uff0c\u4efb\u610f\u952e\u7ee7\u7eed\uff01\n");
            getch();
            break;
        case 0: // exit
            printf("\u9000\u51fa\u6210\u529f\uff0c\u4efb\u610f\u952e\u7ee7\u7eed\uff01\n");
            getch();
            break;
        default:
            printf("ERROR\n");
            break;
        }
        break;
    default:
        printf("ERROR\n");
        break;
    }
    system("cls");
    menu();
}