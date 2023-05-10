#include <io.h>
#include "card.h"

Log *logExtend(Log *head){
    Log *p1= head, *p2;//*p1 = (Log *)calloc(1, LENLog);
    // while (p_log != NULL)
    //     p_log = p_log->next;
    //   p_log->next = p1;
    if(p1 != NULL)
    {
        while(p1->next!= NULL)
        {
            p1 = p1->next;
        }
        p2=p1->next=(Log *)calloc(1, LENLog);
        p2->time=t0;
        p2->money=0.0;
    }
    return (p2);
}
Log *logDelete(Log *head, Time detime){
    Log *p1 = head, *p2;
    if (!timeComp(head->time, detime)){
        head = head->next;
        free(p1);
        return (head);
    }
    while (p1 != NULL){
        p2 = p1->next;
        if (!timeComp(p2->time, detime)){
            p1->next = p2->next;
            free(p2);
            return (head);
        }
        p1 = p1->next;
    } //
    return (head);
}
Log *logSearch(Log *head, ...){
    Log *p1 = head;
    va_list val;
    va_start(val, head);
    Time t1 = va_arg(val, Time);
    Time t2 = va_arg(val, Time);
    double money = va_arg(val, double);
    if (head != NULL){
        if (!timeComp(t1,t2)){
            while (p1 != NULL){
                if ((timeComp(t1,p1->time)!=-1)||(timeComp(t2,p1->time)!=-1)){
                    va_end(val);
                    return p1;
                }
                p1 = p1->next;
            }
        }
        p1 = head;
        while (p1 != NULL){
            if (p1->money == money){
                va_end(val);
                return p1;
            }
            p1 = p1->next;
        }
    }else
        va_end(val);
    return NULL;
}
Log* logSearchs(Log* p_log,int* j,Time t1,Time t2,double money){
    Log *p1 = p_log;
    *j = 0;
    Log **p;
    while (p1 != NULL)
        if (logSearch(p1,t1,t2,money)!=NULL){
            p[*j] = (Log *)calloc(1, sizeof(Log *));
            p[*j] = logSearch(p1,t1,t2,money);
            *j++;
            p1 = logSearch(p1,t1,t2,money);
        }
    return *p;
}
Card *cardExtend(){
    Card *p1 = cards,*p2;
    if (p1 != NULL){
        while (p1->next != NULL){
            p1 = p1->next;
        } /*
         p1 = p1->next = (Card *)malloc(LENCard);
         p1->level = 0;
         p1->password = (char *)malloc(sizeof(p1->password));
         p1->remaining_sum = 0.0f, p1->total_charge = 0.0f, p1->createTime.year = 0, p1->createTime.month = 0, p1->createTime.day = 0, p1->createTime.hour = 0, p1->createTime.minute = 0;
         p1->validTime.year = 0, p1->validTime.month = 0, p1->validTime.day = 0, p1->validTime.hour = 0, p1->validTime.minute = 0;
         p1->rechargeLog->time.year = 0, p1->rechargeLog->time.month = 0, p1->rechargeLog->time.day = 0, p1->rechargeLog->time.hour = 0, p1->rechargeLog->time.minute = 0, p1->rechargeLog->money = 0.0f;
         p1->consumeLog->time.year = 0, p1->consumeLog->time.month = 0, p1->consumeLog->time.day = 0, p1->consumeLog->time.hour = 0, p1->consumeLog->time.minute = 0, p1->consumeLog->money = 0.0f;
         p1->isLost = 0;*/
        
        p2=p1->next = (Card *)calloc(1, LENCard);
        p2->name = (char*)calloc(1,80);
        p2->number = (char*)calloc(1,40);
        p2->phone = (char*)calloc(1,44);
        p2->password =(char*)calloc(1,80);
        p2->rechargeLog=logCreate();
        p2->consumeLog=logCreate();
    }
    return (p2);
}
Card *cardDelete(char *demessage){
    Card *p1 = cards;
    if (p1 != NULL){
        while (p1 != NULL){
            Card *p2 = p1->next;
            if (!strcmp(p1->next->name, demessage) || !strcmp(p1->next->number, demessage)){
                p1->next = p1->next->next;
                free(p2);
                return (cards);
            }
            p1 = p1->next;
        }
    }else
        return NULL;
}
// bool test(char* str1,char* str2)
// {
//     if (str1 == NULL && str2 == NULL)
//     return false;
//     else
//     return true;
// }

// bool cardComp(char *strings[],int num, Card *point){
//     for (int i = 0; i < 5; i++)
//         if ( (!strcmp(strings[i], point->name)&&test(strings[i],point->name)) || (!strcmp(strings[i], point->phone)&&test(strings[i],point->phone)) || (!strcmp(strings[i], point->number)&&test(strings[i],point->number)))
//             return true;
//     return false;
//     }



Card *cardSearch_char(Card *head,char* string){
    Card *p1 = head;
    char* strs="";
    strs = (char *)calloc(1,sizeof(char*));
    strcpy(strs,string);
    if (head != NULL){
    //     if (!strcmp(head->name, strs)|| !strcmp(head->phone, strs)||!strcmp(head->number, strs)){
    //         return head;
    //     }
        while (p1 != NULL){
            if (strcmp(p1->name, strs)!=0)
                return p1;
            
            if(!strcmp(p1->phone,strs))
                return p1;
            if(!strcmp(p1->number,strs))
                return p1;
            p1 = p1->next;
        }
    }
    return NULL;
}
Card *cardSearch_level(Card *head, short lev){
    Card *p1 = head;
    if (head != NULL)
        while (p1 != NULL){
            if (p1->level == lev){
                return p1;
            }
            p1 = p1->next;
        }
    return NULL;
}
Card *cardSearch_consume(Card *head, double consume){
    Card *p1 = head;
    if (head != NULL)
        while (p1 != NULL){
            if (p1->total_charge == consume){
                return p1;
            }
            p1 = p1->next;
        }
    return NULL;
}
int cardtest(Card a){
    if (a.level != 0)
        return (1);
    if (a.total_charge != 0)
        return (2);
    else
        return (3);
}
Card *cardSearch(Card *head, Card a){
    Card *p1 = cards;
    int i = cardtest(a);
    if (i == 3)
    {
        if(strcmp(a.name,""))
        return cardSearch_char(p1,a.name);
        if(strcmp(a.phone,""))
        return cardSearch_char(p1,a.phone);
        if(strcmp(a.number,""))
        return cardSearch_char(p1,a.number);
    }
    if (i == 1)
        return cardSearch_level(p1, a.level);
    if (i == 2)
        return cardSearch_consume(p1, a.total_charge);
}
Card *cardSearchs(int *n, Card a){
    Card *p1 = cards;
    *n = 0;
    Card **p;
    while (p1 != NULL)
        if (!cardSearch(p1, a)){
            p[*n] = (Card *)calloc(1, sizeof(Card *));
            p[*n] = cardSearch(cards, a);
            *n++;
            p1 = cardSearch(p1, a);
        }
    return p;
}
void cardLost(char *lostmessage){
    Card *p1 = cards;
    if (p1 != NULL){
        if ((strcmp(cards->name, lostmessage) == 0) || (strcmp(cards->number, lostmessage) == 0))
            cards->isLost = 1;
        while (p1 != NULL){
            if ((strcmp(p1->name, lostmessage) == 0) || (strcmp(p1->number, lostmessage) == 0))
                p1->isLost = 1;
            p1 = p1->next;
        }
    }
}
void write_file(){
    Card *p_cards = cards;
    Admin *p_admins = admins;
    FILE *fp1;
    FILE *fp2;
    if ((fp1 = fopen("data\\card.txt", "w")) == NULL){
        printf("File open error\n");
        exit(0);
    }
    while (p_cards != NULL){
        fwrite(p_cards, sizeof(Card), 1, fp1);
        // fwrite(p_cards->number, 40, 1, fp);//error
        // fwrite(p_cards->phone, 44, 1, fp);  
        // fwrite(p_cards->password, 60, 1, fp);
        // fwrite(&p_cards->level, 2, 1, fp);
        // fwrite(&p_cards->remaining_sum, 8, 1, fp);
        // fwrite(&p_cards->total_charge, 8, 1, fp);
        // fwrite(&p_cards->createTime.year, 4, 1, fp);
        // fwrite(&p_cards->createTime.month, 4, 1, fp);
        // fwrite(&p_cards->createTime.day, 4, 1, fp);
        // fwrite(&p_cards->createTime.hour, 4, 1, fp);
        // fwrite(&p_cards->createTime.minute, 4, 1, fp);
        // fwrite(&p_cards->validTime.year, 4, 1, fp);
        // fwrite(&p_cards->validTime.month, 4, 1, fp);
        // fwrite(&p_cards->validTime.day, 4, 1, fp);
        // fwrite(&p_cards->validTime.hour, 4, 1, fp);
        // fwrite(&p_cards->validTime.minute, 4, 1, fp);
        // fwrite(&p_cards->isLost, 1, 1, fp);
        // while (p_cards->rechargeLog != NULL){
        //     fwrite(&p_cards->rechargeLog->time.year, 4, 1, fp);
        //     fwrite(&p_cards->rechargeLog->time.month, 4, 1, fp);
        //     fwrite(&p_cards->rechargeLog->time.day, 4, 1, fp);
        //     fwrite(&p_cards->rechargeLog->time.hour, 4, 1, fp);
        //     fwrite(&p_cards->rechargeLog->time.minute, 4, 1, fp);
        //     fwrite(&p_cards->rechargeLog->money, 8, 1, fp);
        //     p_cards->rechargeLog = p_cards->rechargeLog->next;
        // }
        // while (p_cards->consumeLog != NULL){
        //     fwrite(&p_cards->consumeLog->time.year, 4, 1, fp);
        //     fwrite(&p_cards->consumeLog->time.month, 4, 1, fp);
        //     fwrite(&p_cards->consumeLog->time.day, 4, 1, fp);
        //     fwrite(&p_cards->consumeLog->time.hour, 4, 1, fp);
        //     fwrite(&p_cards->consumeLog->time.minute, 4, 1, fp);
        //     fwrite(&p_cards->isLost, 1, 1, fp);
        //     p_cards->consumeLog = p_cards->consumeLog->next;
        // }
          
        p_cards = p_cards->next; // cards has changed
    }
    fclose(fp1);
    if ((fp2 = fopen("data\\admin.txt", "w")) == NULL){
        printf("File open error\n");
        exit(0);
    }
    while (p_admins != NULL){
          printf("%s\n",p_admins->username);
        fwrite(p_admins, sizeof(Admin), 1, fp2);
      
        // fwrite(p_admins->password, sizeof(char*), 1, fp);
        // fwrite(&p_admins->isSuper, 1, 1, fp);
        p_admins = p_admins->next; // admins has changed
    }
    fclose(fp2);
}
void read_file(){
    FILE *fp1;
    FILE *fp2;
    if ((fp1 = fopen("data\\card.txt", "r")) == NULL){
        printf("File card open error\n");
        exit(0);
    } 
    if (cards == NULL)
        cards=(Card *)calloc(1,sizeof(Card*));
    if (admins == NULL)
        admins =(Admin *)calloc(1,sizeof(Admin*));
    Card *p_cards = cards;
    Admin *p_admins = admins;
    if ((fp2 = fopen("data\\admin.txt", "r")) == NULL){
        printf("File admin open error\n");
        exit(0);
    }
    while (p_admins != NULL){
        p_admins=(Admin*)malloc(sizeof(Admin));
        fread(p_admins, sizeof(Admin), 1, fp2);
        // puts(p_admins->username);
        // fread(p_admins->password, 60, 1, fp);
        // fread(&p_admins->isSuper, 1, 1, fp);
        p_admins = p_admins->next; 
    }
    fclose(fp2);
    while (p_cards != NULL){
        fread(p_cards->name, sizeof(Card), 1, fp1);
        fread(p_cards->number, 40, 1, fp1);
        fread(p_cards->phone, 44, 1, fp1);
        fread(p_cards->password, 60, 1, fp1);
        fread(&p_cards->level, 2, 1, fp1);
        fread(&p_cards->remaining_sum, 8, 1, fp1);
        fread(&p_cards->total_charge, 8, 1, fp1);
        fread(&p_cards->createTime.year, 4, 1, fp1);
        fread(&p_cards->createTime.month, 4, 1, fp1);
        fread(&p_cards->createTime.day, 4, 1, fp1);
        fread(&p_cards->createTime.hour, 4, 1, fp1);
        fread(&p_cards->createTime.minute, 4, 1, fp1);
        fread(&p_cards->validTime.year, 4, 1, fp1);
        fread(&p_cards->validTime.month, 4, 1, fp1);
        fread(&p_cards->validTime.day, 4, 1, fp1);
        fread(&p_cards->validTime.hour, 4, 1, fp1);
        fread(&p_cards->validTime.minute, 4, 1, fp1);
        fread(&p_cards->isLost, 1, 1, fp1);
        while (p_cards->rechargeLog != NULL){
            fread(&p_cards->rechargeLog->time.year, 4, 1, fp1);
            fread(&p_cards->rechargeLog->time.month, 4, 1, fp1);
            fread(&p_cards->rechargeLog->time.day, 4, 1, fp1);
            fread(&p_cards->rechargeLog->time.hour, 4, 1, fp1);
            fread(&p_cards->rechargeLog->time.minute, 4, 1, fp1);
            fread(&p_cards->rechargeLog->money, 8, 1, fp1);
            p_cards->rechargeLog = p_cards->rechargeLog->next;
        }
        while (p_cards->consumeLog != NULL){
            fread(&p_cards->consumeLog->time.year, 4, 1, fp1);
            fread(&p_cards->consumeLog->time.month, 4, 1, fp1);
            fread(&p_cards->consumeLog->time.day, 4, 1, fp1);
            fread(&p_cards->consumeLog->time.hour, 4, 1, fp1);
            fread(&p_cards->consumeLog->time.minute, 4, 1, fp1);
            fread(&p_cards->isLost, 1, 1, fp1);
            p_cards->consumeLog = p_cards->consumeLog->next;
        }
        p_cards = p_cards->next; 
    }
    fclose(fp1);
    
}
void backUp(){
    Card *p_cards = cards;
    Admin *p_admins = admins;
    FILE *fp;

    typedef struct tm tm;
    time_t current;
    time(&current);
    tm *point = localtime(&current);
    char *bctime = asctime(point);

    char* c;
    if((c=strstr(bctime, "\n")))
    {
        *c = '\0';
    }

    char* name1=(char*)malloc(strlen(bctime)+20);
    strcpy(name1,"data\\c");
    strcat(name1,bctime);
    strcat(name1,".txt");
    char* name2;
    name2=(char*)calloc(1,sizeof(200));
    strcpy(name1,strcat("a", bctime));    

    if ((fp = fopen(name1, "w")) == NULL){
        printf("File open error\n");
        return;
    }
    while (p_cards != NULL){
        fwrite(p_cards, sizeof(Card), 1, fp);
        // fwrite(p_cards->number, 40, 1, fp);
        // fwrite(p_cards->phone, 44, 1, fp);
        // fwrite(p_cards->password, 60, 1, fp);
        // fwrite(&p_cards->level, 2, 1, fp);
        // fwrite(&p_cards->remaining_sum, 8, 1, fp);
        // fwrite(&p_cards->total_charge, 8, 1, fp);
        // fwrite(&p_cards->createTime.year, 4, 1, fp);
        // fwrite(&p_cards->createTime.month, 4, 1, fp);
        // fwrite(&p_cards->createTime.day, 4, 1, fp);
        // fwrite(&p_cards->createTime.hour, 4, 1, fp);
        // fwrite(&p_cards->createTime.minute, 4, 1, fp);
        // fwrite(&p_cards->validTime.year, 4, 1, fp);
        // fwrite(&p_cards->validTime.month, 4, 1, fp);
        // fwrite(&p_cards->validTime.day, 4, 1, fp);
        // fwrite(&p_cards->validTime.hour, 4, 1, fp);
        // fwrite(&p_cards->validTime.minute, 4, 1, fp);
        // fwrite(&p_cards->isLost, 1, 1, fp);
        // while (p_cards->rechargeLog != NULL){
        //     fwrite(&p_cards->rechargeLog->time.year, 4, 1, fp);
        //     fwrite(&p_cards->rechargeLog->time.month, 4, 1, fp);
        //     fwrite(&p_cards->rechargeLog->time.day, 4, 1, fp);
        //     fwrite(&p_cards->rechargeLog->time.hour, 4, 1, fp);
        //     fwrite(&p_cards->rechargeLog->time.minute, 4, 1, fp);
        //     fwrite(&p_cards->rechargeLog->money, 8, 1, fp);
        //     p_cards->rechargeLog = p_cards->rechargeLog->next;
        // }
        // while (p_cards->consumeLog != NULL){
        //     fwrite(&p_cards->consumeLog->time.year, 4, 1, fp);
        //     fwrite(&p_cards->consumeLog->time.month, 4, 1, fp);
        //     fwrite(&p_cards->consumeLog->time.day, 4, 1, fp);
        //     fwrite(&p_cards->consumeLog->time.hour, 4, 1, fp);
        //     fwrite(&p_cards->consumeLog->time.minute, 4, 1, fp);
        //     fwrite(&p_cards->isLost, 1, 1, fp);
        //     p_cards->consumeLog = p_cards->consumeLog->next;
        // }
        p_cards = p_cards->next; 
    }
    fclose(fp);
    if ((fp = fopen("data\\name2.txt", "w")) == NULL){
        printf("File open error\n");
        return;
    }
    while (p_admins != NULL){
        fwrite(p_admins, sizeof(Admin), 1, fp);
        // fwrite(p_admins->password, sizeof(char*), 1, fp);
        // fwrite(&p_admins->isSuper, 1, 1, fp);
        p_admins = p_admins->next; 
    }
    fclose(fp);
}
/*{
    FILE *f1;
    FILE *f2;
    typedef struct tm tm;
    time_t current;
    time(&current);
    tm *point = localtime(&current);
    char *bctime = asctime(point);
    if ((f1 = fopen("data.txt", "rb")) == NULL){
        printf("File not found\n");
        return;
    }
    if ((f2 = fopen("bctime.txt", "wb")) == NULL){
        printf("File not found\n");
        return;
    }
    while (!feof(f1)){
        char ch = fgetc(f1);
        fputc(ch, f2);
    }
    fclose(f1);
    fclose(f2);
}*/
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
void getFiles(char *path, char *suffixname){
    long hFile = 0;
    struct _finddata_t singlefileinfo;
    strcat(path, "\\*");
    if ((hFile = _findfirst(path, &singlefileinfo)) != -1){
        do{
            if ((singlefileinfo.attrib & _A_SUBDIR)){
                if (strcmp(singlefileinfo.name, ".") != 0 && strcmp(singlefileinfo.name, "..") != 0)
                    continue;
            }else{
                int length = strlen(singlefileinfo.name);
                char *filename = singlefileinfo.name;
                int pos_lastdot = -1;
                for (int j = length - 1; j > 0; j--)
                    if (filename[j] == '.'){
                        pos_lastdot = j;
                        break;
                    }
                if (pos_lastdot != -1){
                    int actualsuffix_len = length - pos_lastdot;
                    char actualsuffix[actualsuffix_len];
                    if (actualsuffix_len == strlen(suffixname)){
                        memcpy(actualsuffix, filename + pos_lastdot, actualsuffix_len);
                        int flag = 1;
                        for (int k = 0; k < actualsuffix_len; k++)
                            if (actualsuffix[k] != suffixname[k]){
                                flag = -1;
                                break;
                            }
                        if (flag == 1)
                            printf("%s\n", filename);
                    }
                }
            }
        }while (_findnext(hFile, &singlefileinfo) == 0);
        _findclose(hFile);
    }
}
void print_file_name(){
    printf("%u8BF7%u8F93%u5165%u5907%u4EFD%u6587%u4EF6%u6240%u5728%u6587%u4EF6%u5939\n");
    char path[MAX_FILENAME_LENGTH];
    char *str1 = gets(path);
    char suffixname[6] = ".txt";
    getFiles(str1, suffixname);
}
void restore(){
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
    if ((f1 = fopen("file_name", "r")) == NULL){  // the name of the file needs to be changed
        printf("File not found\n");
        return;
    }
    if ((f2 = fopen("bctime.txt", "r")) == NULL){
        printf("File not found\n");
        return;
    }
    while (!feof(f2)){
        char ch = fgetc(f2);
        fputc(ch, f1);
    }
    fclose(f1);
    fclose(f2);
}
void logOut(){
    write_file();

    // remove("data\\admin.txt");
    // remove("data\\card.txt");
    
    exit(0);
}//
void adminSignUp(){
    Admin *ap = adminExtend();
    printf("\u8bf7\u8f93\u5165\u7ba1\u7406\u5458\u8d26\u53f7\n");
    getchar();
    ap->username=getstr();
    printf("\u8bf7\u8f93\u5165\u7ba1\u7406\u5458\u5bc6\u7801\n");
    getchar();
    ap->password=getstr();
}
Admin *adminSearch(char *s){
    Admin *ap = admins;
    while (ap != NULL){
        if (!strcmp(ap->username, s))
            return ap;
        ap = ap->next;
    }
    return NULL;
}
char *generate_random(){
    int test_num;
    srand(time(NULL));
    test_num = rand() % 9999 + 1000; // generate random number-test_num
    char *test_message;
    test_message = (char *)malloc(sizeof(test_message));
    sprintf(test_message, "%d", test_num);
    return test_message;
}
char *send_message(Card *p, char *message){
    char *mes1;
    mes1=(char *)calloc(1,sizeof(char));
    strcpy(mes1, message);
    strcat(mes1, p->phone);
    return mes1;
}
bool cardIdentify(Card *p){
    // char *mes;
    // mes = (char *)malloc(sizeof(mes));
    // strcpy(mes, generate_random());
    // printf("\u9a8c\u8bc1\u7801\u53d1\u9001\u6210\u529f\n");
    // char *str;
    // str = (char *)malloc(sizeof(str));
    // strcpy(str, send_message(p, mes));
    // char mes3[4];
    // strncpy(mes3, str, 4);
    // if (!strcmp(mes3, mes))
    //     return true;
    // return false;
    printf("\u8eab\u4efd\u9a8c\u8bc1\u6210\u529f\n");
    return true;
}
void cardLogOut(){
    void menu();
}
void cardSignUp(){
    printf("\u8bf7\u8f93\u5165\u7535\u8bdd\u53f7\u7801\n");
    getchar();
    char *phoneNum = getstr();
    Card a = {"","",phoneNum},*p1; 
    // if (cardSearch(cards, a)!=NULL){
        if(cards==NULL){
            cards=cardCreate();
            p1=cards;
        }else
            p1 = cardExtend(cards);
        // char *card_num = generate_random();
        // strcpy(p1->number, card_num);
        strcpy(p1->phone, phoneNum);
        printf("\u8bf7\u8f93\u5165\u59d3\u540d\n");
        char *name = getstr();
        strcpy(p1->name, name);
        printf("\u8bf7\u8f93\u5165\u5bc6\u7801\n");
        char *password = getPassword();
        strcpy(p1->password, password);
        printf("\u8bf7\u786e\u8ba4\u5bc6\u7801\n");
        while (1){
            char *confirm = getPassword();
            if (strcmp(p1->password, confirm) == 0){
                printf("\u4f1a\u5458\u5361\u521b\u5efa\u6210\u529f\n");
                break;
            }else{
                printf("\u5bc6\u7801\u9519\u8bef\n");
                printf("\u8bf7\u518d\u6b21\u8f93\u5165\u5bc6\u7801\n");
            }
       
        }
        strcpy(p1->number,generate_random());
        printf("\u60a8\u7684\u5361\u53f7\u4e3a\n");
        printf("%s\n",p1->number);
        p1->level = 1;
        enum{year,month,day,hour,minute};
        time_t t = time(NULL);
        struct tm *lt = localtime(&t);
        char str_time[20];
        sprintf(str_time, "%04d-%02d-%02d %02d:%02d",
                lt->tm_year + 1900, lt->tm_mon + 1, lt->tm_mday,
                lt->tm_hour, lt->tm_min);
        sscanf(str_time, "%d-%d-%d %d:%d",
               &p1->createTime.year, &p1->createTime.month, &p1->createTime.day, &p1->createTime.hour, &p1->createTime.minute);
    // }else if(cardSearch(cards, a)->isLost){
    //     printf("\u6b64\u53f7\u7801\u5df2\u7ed1\u5b9a\u4e00\u5f20\u5361\u4e14\u5df2\u6302\u5931\n");
    //     printf("\u8f93\u5165 1 \u627e\u56de\u4f1a\u5458\u5361\n");
    //     printf("\u8f93\u5165 2 \u521b\u5efa\u65b0\u5361(\u4f60\u5361\u4e2d\u7684\u4f59\u989d\u5c06\u88ab\u8f6c\u79fb\u5230\u65b0\u5361\uff0c\u4f46\u6d88\u8d39\u8bb0\u5f55\u4e0d\u4f1a\u88ab\u4fdd\u7559)\n");
    //     char n;
    //     n = getchar();
    //     switch (n){
    //     case 1:
    //         cardFind(cardSearch(cards, a)->number);
    //         cardUpdatePassword(cardSearch(cards, a));
    //         break;
    //     case 2:
    //         strcpy(cardExtend(cards)->phone, phoneNum);
    //         cardExtend(cards)->total_charge = cardSearch(cards, a)->total_charge;
    //         cardExtend(cards)->remaining_sum = cardSearch(cards, a)->remaining_sum;
    //         strcpy(cardExtend(cards)->name, cardSearch(cards, a)->name);
    //         printf("\u8bf7\u8f93\u5165\u5bc6\u7801\n");
    //         char *password = getstr();
    //         strcpy(cardExtend(cards)->password, password);
    //         printf("\u8bf7\u786e\u8ba4\u5bc6\u7801\n");
    //         while (1){  
    //             char *confirm = getstr();
    //             if (strcmp(cardExtend(cards)->password, confirm) == 0){
    //                 printf("\u4f1a\u5458\u5361\u521b\u5efa\u6210\u529f\n");
    //                 break;
    //             }
    //             else{
    //                 printf("\u5bc6\u7801\u9519\u8bef\n");
    //                 printf("\u8bf7\u518d\u6b21\u8f93\u5165\u5bc6\u7801\n");
    //             }
    //         }
    //     }
    // }
    // system("pause");
}
/*Card* cardSearchs( int* cnt, ...) {
    va_list args;
    va_start(args, cnt);
    Card* res = (Card*) calloc(1,sizeof(Card*));
    int index = 0;
    char* name = NULL;
    char* number = NULL;
    char* phone = NULL;
    short level = -1;
    Time t1;
    t1.hour = t1.minute = -1;
    Time t2;
    t2.hour = t2.minute  = -1;
    for (int i = 0; i < cnt; i++) {
        char* key = va_arg(args, char*);
        if (!strcmp(key, "name")) {
            name = va_arg(args, char*);
        } else if (!strcmp(key, "number")) {
            number = va_arg(args, char*);
        } else if (!strcmp(key, "phone")) {
            phone = va_arg(args, char*);
        } else if (!strcmp(key, "level")) {
            level = va_arg(args, short);
        } else if (!strcmp(key, "timeStart")) {
            t1 = *(va_arg(args, Time*));
        } else {
            t2 = *(va_arg(args, Time*));
        }
    }
    for (Card* p = cards; p != NULL; p = p->next) {
        int match = 1;
        if (name != NULL && strcmp(name, p->name)) {
            match = 0;
        }
        if (number != NULL && strcmp(number, p->number)) {
            match = 0;
        }
        if (phone != NULL && strcmp(phone, p->phone)) {
            match = 0;
        }
        if (level >= 0 && level != p->level) {
            match = 0;
        }
        if (t1.hour >= 0 && t1.minute >= 0 && t2.hour >= 0 && t2.minute >= 0 ) {
                 Log* pr = p->rechargeLog;
            while (pr != NULL) {
                if (timeComp(t1, pr->time) <= 0 && timeComp(pr->time, t2) <= 0) {
                    break;
                }
                pr = pr->next;
            }

            if (pr == NULL) {
                Log* pc = p->consumeLog;
                while (pc != NULL) {
                    if (timeComp(t1, pc->time) <= 0 && timeComp(pc->time, t2) <= 0) {
                        break;
                    }
                    pc = pc->next;
                }

                if (pc == NULL) {
                    match = 0;
                }
            }
        }
        if (match) {
            res = p;
            res=res->next;
        }
    }
    va_end(args);
    *cnt = index;
    return res;
}*/