#include <time.h>
#include <io.h>
#include "card.h"
Log *logCreate()
{
    int n = 0;
    Log *p1;
    // Log *p1, *p2;
    // p1 = p2 = (Log *)malloc(LENLog);
    p1 = (Log *)malloc(LENLog);
    p1->time = t0;
    p1->money = 0.0;
    // p1->time.year = 0, p1->time.month = 0, p1->time.day = 0, p1->time.hour = 0, p1->time.minute, p1->money=0;
    // head = NULL;
    // while (p1->time.year != 0)
    // {
    //     n = n + 1;
    //     if (n == 1)
    //         head = p1;
    //     else
    //         p2->next = p1;
    //     p2 = p1;
    //     p1 = (Log *)malloc(LENLog);
    //     p1->time.year = 0, p1->time.month = 0, p1->time.day = 0, p1->time.hour = 0, p1->time.minute=0, p1->money=0;
    // }
    // p2->next = NULL;
    return (p1);
}

Log *logExtend(Log *head)
{
    Log *p_log = head, *p1 = (Log *)calloc(1, LENLog);
    while (p_log != NULL)
        p_log = p_log->next;
    p_log->next = p1;
    return (p1);
}

Log *logDelete(Log *head, Time detime)
{
    Log *p1 = head, *p2;
    if (!timeComp(head->time, detime))
    {
        head = head->next;
        free(p1);
        return (head);
    }
    while (p1 != NULL)
    {
        p2 = p1->next;
        if (!timeComp(p2->time, detime))
        {
            p1->next = p2->next;
            free(p2);
            return (head);
        }
        p1 = p1->next;
    } //
    return (head);
}

Log *logSearch(Log *head, ...)
{
    Log *p1 = head;
    va_list val;
    va_start(val, head);
    Time t = va_arg(val, Time);
    double money = va_arg(val, double);
    if (head != NULL)
    {
        while (p1 != NULL)
        {
            if (t.month * t.day * t.hour * t.minute)
            {
                if (!timeComp(p1->time, t))
                {
                    va_end(val);
                    return p1;
                }
                p1 = p1->next;
            }
            else
            {
                if (p1->time.year == t.year)
                {
                    va_end(val);
                    return p1;
                }
            }
        }
        p1 = head;
        while (p1 != NULL)
        {
            if (p1->money == money)
            {
                va_end(val);
                return p1;
            }
            p1 = p1->next;
        }
    }
    else
        va_end(val);
    return NULL;
}
Card *cardCreate()
{
    int n = 0;
    Card *p1;
    // Card *p1, *p2;
    // p1 = p2 = (Card *)malloc(LENCard);
    p1 = (Card *)malloc(LENCard);
    p1->level = 0;
    p1->name = (char *)malloc(sizeof(p1->name));
    p1->number = (char *)malloc(sizeof(p1->number));
    p1->phone = (char *)malloc(sizeof(p1->phone));
    p1->password = (char *)malloc(sizeof(p1->password));
    p1->remaining_sum = 0.0f, p1->total_charge = 0.0f, p1->createTime.year = 0, p1->createTime.month = 0, p1->createTime.day = 0, p1->createTime.hour = 0, p1->createTime.minute = 0;
    p1->validTime.year = 0, p1->validTime.month = 0, p1->validTime.day = 0, p1->validTime.hour = 0, p1->validTime.minute = 0;
    p1->rechargeLog->time.year = 0, p1->rechargeLog->time.month = 0, p1->rechargeLog->time.day = 0, p1->rechargeLog->time.hour = 0, p1->rechargeLog->time.minute = 0, p1->rechargeLog->money = 0.0f;
    p1->consumeLog->time.year = 0, p1->consumeLog->time.month = 0, p1->consumeLog->time.day = 0, p1->consumeLog->time.hour = 0, p1->consumeLog->time.minute = 0, p1->consumeLog->money = 0.0f;
    // head = NULL;
    // while (p1->level != 9)
    // {
    //     n = n + 1;
    //     if (n == 1)
    //         head = p1;
    //     else
    //         p2->next = p1;
    //     p2 = p1;
    //     p1 = (Card *)malloc(LENCard);

    //     p1->level = 0;
    //     p1->name=(char *)malloc(sizeof(p1->name));
    //     p1->number=(char *)malloc(sizeof(p1->number));
    //     p1->phone=(char *)malloc(sizeof(p1->phone));
    //     p1->password=(char *)malloc(sizeof(p1->password));
    //     p1->remaining_sum = 0.0f, p1->total_charge = 0.0f, p1->createTime.year = 0, p1->createTime.month = 0, p1->createTime.day = 0, p1->createTime.hour = 0, p1->createTime.minute = 0;
    //     p1->validTime.year = 0, p1->validTime.month = 0, p1->validTime.day = 0, p1->validTime.hour = 0, p1->validTime.minute = 0;
    //     p1->rechargeLog->time.year = 0, p1->rechargeLog->time.month = 0, p1->rechargeLog->time.day = 0, p1->rechargeLog->time.hour = 0, p1->rechargeLog->time.minute = 0, p1->rechargeLog->money = 0.0f;
    //     p1->consumeLog->time.year = 0, p1->consumeLog->time.month = 0, p1->consumeLog->time.day = 0, p1->consumeLog->time.hour = 0, p1->consumeLog->time.minute = 0, p1->consumeLog->money = 0.0f;
    //     p1->isLost = 0;
    //     head = NULL;
    // }
    // p2->next = NULL;
    return (p1);
}
Card *cardExtend()
{
    Card *p1 = cards;
    if (p1 != NULL)
    {
        while (p1 != NULL)
        {
            p1 = p1->next;
        } /*
         p1 = p1->next = (Card *)malloc(LENCard);
         p1->level = 0;
         p1->name = (char *)malloc(sizeof(p1->name));
         p1->number = (char *)malloc(sizeof(p1->number));
         p1->phone = (char *)malloc(sizeof(p1->phone));
         p1->password = (char *)malloc(sizeof(p1->password));
         p1->remaining_sum = 0.0f, p1->total_charge = 0.0f, p1->createTime.year = 0, p1->createTime.month = 0, p1->createTime.day = 0, p1->createTime.hour = 0, p1->createTime.minute = 0;
         p1->validTime.year = 0, p1->validTime.month = 0, p1->validTime.day = 0, p1->validTime.hour = 0, p1->validTime.minute = 0;
         p1->rechargeLog->time.year = 0, p1->rechargeLog->time.month = 0, p1->rechargeLog->time.day = 0, p1->rechargeLog->time.hour = 0, p1->rechargeLog->time.minute = 0, p1->rechargeLog->money = 0.0f;
         p1->consumeLog->time.year = 0, p1->consumeLog->time.month = 0, p1->consumeLog->time.day = 0, p1->consumeLog->time.hour = 0, p1->consumeLog->time.minute = 0, p1->consumeLog->money = 0.0f;
         p1->isLost = 0;*/
        p1 = (Card *)calloc(1, LENCard);
    }
    return (p1);
}
Card *cardDelete(char *demessage)
{
    Card *p1 = cards;
    if (p1 != NULL)
    {
        while (p1 != NULL)
        {
            Card *p2 = p1->next;
            if (!strcmp(p1->next->name, demessage) || !strcmp(p1->next->number, demessage))
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
}

bool cardComp(char *strings[], Card *point)
{
    for (int i = 0; i < 5; i++)
    {
        if ((!strcmp(strings[i], point->name)) || (!strcmp(strings[i], point->phone)) || (!strcmp(strings[i], point->number)))
            return true;
    }
    return false;
}

Card *cardSearch_level(Card *, short);
Card *cardSearch_consume(Card *, double);

Card *cardSearch_char(Card *head, ...)
{
    Card *p1 = head;
    char *strs[5] = {""};
    va_list val;
    va_start(val, head);
    for (int i = 0; i < 5; i++)
    {
        strs[i] = va_arg(val, char *);
    }

    if (head != NULL)
    {
        if (cardComp(strs, head))
        {
            va_end(val);
            return head;
        }
        while (p1 != NULL)
        {
            if ((cardComp(strs, p1)))
            {
                va_end(val);
                return p1;
            }
            p1 = p1->next;
        }
    }
    va_end(val);
    return NULL;
}

Card *cardSearch_level(Card *head, short lev)
{
    Card *p1 = head;
    if (head != NULL)
    {
        while (p1 != NULL)
        {
            if (p1->level == lev)
            {
                return p1;
            }
            p1 = p1->next;
        }
    }
    return NULL;
}
Card *cardSearch_consume(Card *head, double consume)
{
    Card *p1 = head;
    if (head != NULL)
    {
        while (p1 != NULL)
        {
            if (p1->total_charge == consume)
            {
                return p1;
            }
            p1 = p1->next;
        }
    }
    return NULL;
}

int cardtest(Card a)
{
    if (a.level != 10)
    {
        return (1);
    }
    if (a.total_charge == 0)
    {
        return (2);
    }
    else
        return (3);
}

Card *cardSearch(Card a)
{
    Card *p1 = cards;
    int n = cardtest(a);

    if (n == 3)

        return cardSearch_char(p1, a.name, a.number, a.phone);

    if (cardtest(a) == 2)
        return cardSearch_level(p1, a.level);

    if (cardtest(a) == 1)
        return cardSearch_consume(p1, a.total_charge);
}
Card *cardSearchs(Card a)
{ /*
     Card* p1=cards;
     Card*
     */
}

void cardLost(char *lostmessage)
{
    Card *p1 = cards;
    if (p1 != NULL)
    {
        if ((strcmp(cards->name, lostmessage) == 0) || (strcmp(cards->number, lostmessage) == 0))
        {
            cards->isLost = 1;
        }
        while (p1 != NULL)
        {
            if ((strcmp(p1->name, lostmessage) == 0) || (strcmp(p1->number, lostmessage) == 0))
            {
                p1->isLost = 1;
            }
            p1 = p1->next;
        }
    }
}
void write_file()
{
    Card *p_cards = cards;
    Admin *p_admins = admins;
    FILE *fp;
    if ((fp = fopen("data\\card.txt", "wb")) == NULL)
    {
        printf("File open error\n");
        exit(0);
    }
    while (p_cards != NULL)
    {
        fwrite(&p_cards->name, 80, 1, fp);
        fwrite(&p_cards->number, 40, 1, fp);
        fwrite(&p_cards->phone, 44, 1, fp);
        fwrite(&p_cards->password, 60, 1, fp);
        fwrite(&p_cards->level, 2, 1, fp);
        fwrite(&p_cards->remaining_sum, 8, 1, fp);
        fwrite(&p_cards->total_charge, 8, 1, fp);

        fwrite(&p_cards->createTime.year, 4, 1, fp);
        fwrite(&p_cards->createTime.month, 4, 1, fp);
        fwrite(&p_cards->createTime.day, 4, 1, fp);
        fwrite(&p_cards->createTime.hour, 4, 1, fp);
        fwrite(&p_cards->createTime.minute, 4, 1, fp);

        fwrite(&p_cards->validTime.year, 4, 1, fp);
        fwrite(&p_cards->validTime.month, 4, 1, fp);
        fwrite(&p_cards->validTime.day, 4, 1, fp);
        fwrite(&p_cards->validTime.hour, 4, 1, fp);
        fwrite(&p_cards->validTime.minute, 4, 1, fp);

        fwrite(&p_cards->isLost, 1, 1, fp);

        while (p_cards->rechargeLog != NULL)
        {
            fwrite(&p_cards->rechargeLog->time.year, 4, 1, fp);
            fwrite(&p_cards->rechargeLog->time.month, 4, 1, fp);
            fwrite(&p_cards->rechargeLog->time.day, 4, 1, fp);
            fwrite(&p_cards->rechargeLog->time.hour, 4, 1, fp);
            fwrite(&p_cards->rechargeLog->time.minute, 4, 1, fp);
            fwrite(&p_cards->rechargeLog->money, 8, 1, fp);
            p_cards->rechargeLog = p_cards->rechargeLog->next;
        }
        while (p_cards->consumeLog != NULL)
        {
            fwrite(&p_cards->consumeLog->time.year, 4, 1, fp);
            fwrite(&p_cards->consumeLog->time.month, 4, 1, fp);
            fwrite(&p_cards->consumeLog->time.day, 4, 1, fp);
            fwrite(&p_cards->consumeLog->time.hour, 4, 1, fp);
            fwrite(&p_cards->consumeLog->time.minute, 4, 1, fp);
            fwrite(&p_cards->isLost, 1, 1, fp);
            p_cards->consumeLog = p_cards->consumeLog->next;
        }

        p_cards = p_cards->next; // cards has changed
    }
    fclose(fp);

    if ((fp = fopen("data\\admin.txt", "wb")) == NULL)
    {
        printf("File open error\n");
        exit(0);
    }
    while (p_admins != NULL)
    {
        fwrite(&p_admins->username, 80, 1, fp);
        fwrite(&p_admins->password, 60, 1, fp);
        fwrite(&p_admins->isSuper, 1, 1, fp);
        p_admins = p_admins->next; // admins has changed
    }
    fclose(fp);
}

void read_file()
{

    FILE *fp;
    if ((fp = fopen("data\\card.txt", "rb")) == NULL)
    {
        printf("File card open error\n");
        exit(0);
    } // if(!cards) cards=cardCreate();
    if (cards == NULL)
    {
        cards = cardCreate();
    }
    if (admins == NULL)
    {
        admins = adminCreate();
    }
    Card *p_cards = cards;
    Admin *p_admins = admins;
    while (p_cards != NULL)
    {
        fread(&p_cards->name, 80, 1, fp);
        fread(&p_cards->number, 40, 1, fp);
        fread(&p_cards->phone, 44, 1, fp);
        fread(&p_cards->password, 60, 1, fp);
        fread(&p_cards->level, 2, 1, fp);
        fread(&p_cards->remaining_sum, 8, 1, fp);
        fread(&p_cards->total_charge, 8, 1, fp);

        fread(&p_cards->createTime.year, 4, 1, fp);
        fread(&p_cards->createTime.month, 4, 1, fp);
        fread(&p_cards->createTime.day, 4, 1, fp);
        fread(&p_cards->createTime.hour, 4, 1, fp);
        fread(&p_cards->createTime.minute, 4, 1, fp);

        fread(&p_cards->validTime.year, 4, 1, fp);
        fread(&p_cards->validTime.month, 4, 1, fp);
        fread(&p_cards->validTime.day, 4, 1, fp);
        fread(&p_cards->validTime.hour, 4, 1, fp);
        fread(&p_cards->validTime.minute, 4, 1, fp);

        fread(&p_cards->isLost, 1, 1, fp);

        while (p_cards->rechargeLog != NULL)
        {
            fread(&p_cards->rechargeLog->time.year, 4, 1, fp);
            fread(&p_cards->rechargeLog->time.month, 4, 1, fp);
            fread(&p_cards->rechargeLog->time.day, 4, 1, fp);
            fread(&p_cards->rechargeLog->time.hour, 4, 1, fp);
            fread(&p_cards->rechargeLog->time.minute, 4, 1, fp);
            fread(&p_cards->rechargeLog->money, 8, 1, fp);
            p_cards->rechargeLog = p_cards->rechargeLog->next;
        }
        while (p_cards->consumeLog != NULL)
        {
            fread(&p_cards->consumeLog->time.year, 4, 1, fp);
            fread(&p_cards->consumeLog->time.month, 4, 1, fp);
            fread(&p_cards->consumeLog->time.day, 4, 1, fp);
            fread(&p_cards->consumeLog->time.hour, 4, 1, fp);
            fread(&p_cards->consumeLog->time.minute, 4, 1, fp);
            fread(&p_cards->isLost, 1, 1, fp);
            p_cards->consumeLog = p_cards->consumeLog->next;
        }

        p_cards = p_cards->next; // cards has changed
    }
    fclose(fp);
    if ((fp = fopen("data\\admin.txt", "rb")) == NULL)
    {
        printf("File admin open error\n");
        exit(0);
    }
    while (p_admins != NULL)
    {
        fread(&p_admins->username, 80, 1, fp);
        fread(&p_admins->password, 60, 1, fp);
        fread(&p_admins->isSuper, 1, 1, fp);
        p_admins = p_admins->next; // admins has changed
    }
    fclose(fp);
}

void backup()
{
    FILE *f1;
    FILE *f2;
    typedef struct tm tm;
    time_t current;
    time(&current);
    tm *point = localtime(&current);
    char *bctime = asctime(point);

    if ((f1 = fopen("data.txt", "rb")) == NULL)
    {
        printf("File not found\n");
        return;
    }
    if ((f2 = fopen("bctime.txt", "wb")) == NULL)
    {
        printf("File not found\n");
        return;
    }
    while (!feof(f1))
    {
        char ch = fgetc(f1);
        fputc(ch, f2);
    }
    fclose(f1);
    fclose(f2);
}
// void restore()
// {
//     FILE* f1;
//     FILE* f2;
//     typedef struct tm tm;
//     time_t current;
//     time(&current);
//     tm *point = localtime(&current);
//     char* bctime=asctime(point);

//     if((f1=fopen("file.txt", "rb"))==NULL)//the name of the file needs to be changed
//     {
//         printf("File not found\n");
//         return;
//     }
//     if((f2=fopen("bctime.txt","rb"))==NULL)
//     {
//         printf("File not found\n");
//         return;
//     }
//     while(!feof(f2))
//     {
//         char ch=fgetc(f2);
//         fputc(ch,f1);
//     }
//     fclose(f1);
//     fclose(f2);
// }

#define MAX_FILENAME_LENGTH 500
void getFiles(char *path, char *suffixname)
{
    long hFile = 0;
    struct _finddata_t singlefileinfo;
    strcat(path, "\\*");
    if ((hFile = _findfirst(path, &singlefileinfo)) != -1)
    {
        do
        {
            if ((singlefileinfo.attrib & _A_SUBDIR))
            {
                if (strcmp(singlefileinfo.name, ".") != 0 && strcmp(singlefileinfo.name, "..") != 0)
                    continue;
            }
            else
            {
                int length = strlen(singlefileinfo.name);
                char *filename = singlefileinfo.name;
                int pos_lastdot = -1;
                for (int j = length - 1; j > 0; j--)
                    if (filename[j] == '.')
                    {
                        pos_lastdot = j;
                        break;
                    }
                if (pos_lastdot != -1)
                {
                    int actualsuffix_len = length - pos_lastdot;
                    char actualsuffix[actualsuffix_len];
                    if (actualsuffix_len == strlen(suffixname))
                    {
                        memcpy(actualsuffix, filename + pos_lastdot, actualsuffix_len);
                        int flag = 1;
                        for (int k = 0; k < actualsuffix_len; k++)
                            if (actualsuffix[k] != suffixname[k])
                            {
                                flag = -1;
                                break;
                            }
                        if (flag == 1)
                            printf("%s\n", filename);
                    }
                }
            }
        } while (_findnext(hFile, &singlefileinfo) == 0);
        _findclose(hFile);
    }
}

void print_file_name()
{

    printf("%u8BF7%u8F93%u5165%u5907%u4EFD%u6587%u4EF6%u6240%u5728%u6587%u4EF6%u5939\n");
    char path[MAX_FILENAME_LENGTH];

    char *str1 = gets(path);

    char suffixname[6] = ".txt";

    getFiles(str1, suffixname);
}
void restore()
{
    print_file_name();
    printf("Please select a backup file and enter its name\n");

    char file_name[25];
    gets(file_name);

    FILE *f1;
    FILE *f2;
    typedef struct tm tm;
    time_t current;
    time(&current);
    tm *point = localtime(&current);
    char *bctime = asctime(point);

    if ((f1 = fopen("file_name", "rb")) == NULL) // the name of the file needs to be changed
    {
        printf("File not found\n");
        return;
    }
    if ((f2 = fopen("bctime.txt", "rb")) == NULL)
    {
        printf("File not found\n");
        return;
    }
    while (!feof(f2))
    {
        char ch = fgetc(f2);
        fputc(ch, f1);
    }
    fclose(f1);
    fclose(f2);
}
void logOut()
{
    exit(0);
}

void adminSignUp()
{
    Admin *ap = adminExtend();

    printf("qing shu ru guan li yuan zhang hao\n");
    scanf("%s", ap->username);
    printf("qing shu ru guan li yuan mi ma\n");
    scanf("%s", ap->password);
}

Admin *adminSearch(char *s)
{
    Admin *ap = admins;
    while (ap != NULL)
    {
        if (strcmp(ap->username, s) == 0)
        {
            return ap;
        }
        ap = ap->next;
    }
    return NULL;
}

// void cardUpdatePassword(Card* head){}

// void cardUpdatePhone(Card* head){}

char *generate_random()
{
    int test_num;
    srand(time(NULL));
    test_num = rand() % 9999 + 1000; // generate random number-test_num
    char *test_message;
    test_message = (char *)malloc(sizeof(test_message));
    sprintf(test_message, "%d", test_num);
    return test_message;
}

char *send_message(Card *p, char *message)
{

    char *mes1;
    strcpy(mes1, message);
    strcat(mes1, p->phone);
    return mes1;
}

bool cardIdentify(Card *p)
{

    char *mes;
    mes = (char *)malloc(sizeof(mes));

    strcpy(mes, generate_random());

    printf("Verification code sent successfully\n");

    char *str;
    str = (char *)malloc(sizeof(str));
    strcpy(str, send_message(p, mes));

    char mes3[4];

    strncpy(mes3, str, 4);

    if (!(strcmp(mes3, mes)))
    {
        return true;
    }
    return false;
}

void cardLogOut()
{
    void menu();
}

void cardSignUp()
{
    printf("Please enter your phone number\n");
    char *phoneNum = getstr();
    Card a = c0;
    strcpy(a.phone, phoneNum);
    if (!cardSearch(a))
    {
        Card *p1 = cardExtend(cards);
        char *card_num = generate_random();
        strcpy(p1->number, card_num);
        strcpy(p1->phone, phoneNum);
        printf("Please enter your name\n");
        char *name = getstr();
        strcpy(p1->name, name);

        printf("Please enter your password\n");
        char *password = getstr();
        strcpy(p1->password, password);
        printf("Please confirm your password\n");
        while (1)
        {
            char *confirm = getstr();
            if (strcmp(p1->password, confirm) == 0)
            {
                printf("User registration successful\n");
                break;
            }
            else
            {
                printf("Wrong password\n");
                printf("Please enter your password again\n");
                continue;
            }
        }
    }
    else if (cardSearch(a)->isLost)
    {
        printf("\u6b64\u53f7\u7801\u5df2\u7ed1\u5b9a\u4e00\u5f20\u5361\u4e14\u5df2\u6302\u5931\n");
        printf("\u8f93\u5165 1 \u627e\u56de\u4f1a\u5458\u5361\n");
        printf("\u8f93\u5165 2 \u521b\u5efa\u65b0\u5361(\u4f60\u5361\u4e2d\u7684\u4f59\u989d\u5c06\u88ab\u8f6c\u79fb\u5230\u65b0\u5361\uff0c\u4f46\u6d88\u8d39\u8bb0\u5f55\u4e0d\u4f1a\u88ab\u4fdd\u7559)\n");
        Card *p1;
        char n;
        n = getchar();
        switch (n)
        {
        case 1:
            cardFind(cardSearch(a)->number);
            cardUpdatePassword(cardSearch(a));
            break;
        case 2:
            p1 = cardExtend(cards);
            strcpy(p1->phone, phoneNum);
            p1->total_charge = cardSearch(a)->total_charge;
            //strcpy()
        }
    }
}
void backUp(){}