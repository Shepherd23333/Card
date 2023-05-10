#include"card.h"
int sig(int x){
    return !x?0:x/abs(x);
}
int timeComp(Time x,Time y){
    return !sig(x.year-y.year)?(
    !sig(x.month-y.month)?(
    !sig(x.day-y.day)?(
    !sig(x.hour-y.hour)?
    sig(x.minute-y.minute)
    :sig(x.hour-y.hour)
    ):sig(x.day-y.day)
    ):sig(x.month-y.month)
    ):sig(x.year-y.year);
}
Log* logCreate(){
    Log* head=(Log*)calloc(1,LENLog);
    return head;
}
void logFix(Log* head){
    logPrints(head);
    printf("\u8bf7\u6307\u5b9a\u9700\u8981\u4fee\u6539\u7684\u4ea4\u6613\u8bb0\u5f55\uff1a\n");
    double money;
    int y,mo,d,h,mi,t;
    scanf("%lf %d\\%d\\%d %d:%d",&money,&y,&mo,&d,&h,&mi);
    if(money>=0&&isTime(y,mo,d,h,mi)){
        Time ti={y,mo,d,h,mi};
        Log *l;
        if(l=logSearch(head,money,ti)){
            printf("\u8bf7\u9009\u62e9\u4f60\u8981\u4fee\u6539\u7684\u5185\u5bb9\uff08\u5141\u8bb8\u540c\u65f6\u4fee\u6539\u591a\u9879\u6570\u636e\uff0c\u8f93\u51650\u7ed3\u675f\u4fee\u6539\uff09\uff1a\n");
            printf("(1.\u4ea4\u6613\u91d1\u989d  2.\u4ea4\u6613\u65f6\u95f4)\n");
            int f[3]={0};
            scanf("%d",&t);
            while(t){
                f[t]=1;
                scanf("%d",&t);
            }
            for(int i=1;i<3;i++)
                if(f[i])
                    switch(i){
                        case 1:
                            printf("\u8bf7\u8f93\u5165\u4ea4\u6613\u91d1\u989d\uff1a\n");
                            scanf("%lf",&money);
                            if(money<0)
                                printf("\u9519\u8bef\uff1a\u975e\u6cd5\u6570\u636e\uff01\n");
                            else{
                                l->money=money;
                                printf("\u4fee\u6539\u6210\u529f\uff01\n");
                            }
                            break;
                        case 2:
                            printf("\u8bf7\u8f93\u5165\u4ea4\u6613\u65f6\u95f4\uff1a\n");
                            scanf("%d\\%d\\%d %d:%d",&y,&mo,&d,&h,&mi);
                            if(isTime(y,mo,d,h,mi)){
                                Time tim={y,mo,d,h,mi};
                                l->time=tim;
                                printf("\u4fee\u6539\u6210\u529f\uff01\n");
                            }else
                                printf("\u9519\u8bef\uff1a\u975e\u6cd5\u6570\u636e\uff01\n");
                            break;
                    }
        }else
            printf("\u9519\u8bef\uff1a\u627e\u4e0d\u5230\u8be5\u6570\u636e\uff01\n");
    }else
        printf("\u9519\u8bef\uff1a\u975e\u6cd5\u6570\u636e\uff01\n");
}
Card* cardCreate(){
    Card* head=(Card*)calloc(1,LENCard);
    head->name=(char*)calloc(1,sizeof(char));
    head->number=(char*)calloc(1,sizeof(char));
    head->phone=(char*)calloc(1,sizeof(char));
    head->password=(char*)calloc(1,sizeof(char));
    head->rechargeLog=logCreate();
    head->consumeLog=logCreate();
    return head;
}
void cardFix(Card* c){
    printf("\u8bf7\u9009\u62e9\u4f60\u8981\u4fee\u6539\u7684\u5185\u5bb9\uff08\u5141\u8bb8\u540c\u65f6\u4fee\u6539\u591a\u9879\u6570\u636e\uff0c\u8f93\u51650\u7ed3\u675f\u4fee\u6539\uff09\uff1a\n");
    printf("(1.\u7528\u6237\u540d  2.\u4f1a\u5458\u5361\u5361\u53f7  3.\u7528\u6237\u624b\u673a\u53f7  4.\u4f1a\u5458\u5361\u5bc6\u7801\n");
    printf("5.\u4f1a\u5458\u5361\u7b49\u7ea7  6.\u603b\u5145\u503c\u91d1\u989d  7.\u521b\u5efa\u65f6\u95f4  8.\u4e22\u5931\u72b6\u6001\n");
    printf("9.\u5145\u503c\u8bb0\u5f55  10.\u6d88\u8d39\u8bb0\u5f55)\n");
    int f[11]={0},t,y,mo,d,h,mi;
    double money;
    char *s;
    Card tc=c0;
    scanf("%d",&t);
    while(t){
        f[t]=1;
        scanf("%d",&t);
    }
    for(int i=1;i<11;i++)
        if(f[i])
            switch(i){
                case 1:
                    printf("\u8bf7\u8f93\u5165\u65b0\u7528\u6237\u540d\uff1a\n");
                    s=getstr();
                    if(isalpha(s[0])&&(s[0]!='c'||strlen(s)==1||strspn(s+1,"0123456789")!=strlen(s+1))||s[0]<0){
                        strcpy(c->name,s);
                        printf("\u4fee\u6539\u6210\u529f\uff01\n");
                    }
                    else
                        printf("\u9519\u8bef\uff1a\u975e\u6cd5\u6570\u636e\uff01\n");
                    break;
                case 2:
                    if(authorize()){
                        printf("\u8bf7\u8f93\u5165\u65b0\u5361\u53f7\uff1a\n");
                        s=getstr();
                        memcpy(tc.number,s,sizeof(s));
                        if(s[0]!='c'||strlen(s)==1||strspn(s+1,"0123456789")!=strlen(s+1))
                            printf("\u9519\u8bef\uff1a\u975e\u6cd5\u6570\u636e\uff01\n");
                        else if(!cardSearch(cards,tc)){
                            strcpy(c->number,s);
                            printf("\u4fee\u6539\u6210\u529f\uff01\n");
                        }else
                            printf("\u9519\u8bef\uff1a\u8be5\u5361\u53f7\u5df2\u5b58\u5728\uff01\n");
                    }
                    break;
                case 3:
                    if(authority!=2){
                        printf("\u8bf7\u8f93\u5165\u65b0\u624b\u673a\u53f7\uff1a\n");
                        s=getstr();
                        memcpy(tc.phone,s,sizeof(s));
                        if(strlen(s)!=11||strspn(s,"0123456789")!=strlen(s))
                            printf("\u9519\u8bef\uff1a\u975e\u6cd5\u6570\u636e\uff01\n");
                        else if(!cardSearch(cards,tc)){
                            strcpy(c->phone,s);
                            printf("\u4fee\u6539\u6210\u529f\uff01\n");
                        }else
                            printf("\u9519\u8bef\uff1a\u8be5\u624b\u673a\u53f7\u5df2\u88ab\u4f7f\u7528\uff01\n");
                    }else
                        cardUpdatePhone(c);
                    break;
                case 4:
                    if(authority!=2)
                        cardUpdatePassword(c);
                    else{
                        printf("\u8bf7\u8f93\u5165\u65b0\u5bc6\u7801\uff1a\n");
                        s=getPassword();
                        strcpy(c->password,s);
                        printf("\u4fee\u6539\u6210\u529f\uff01\n");
                    }
                    break;
                case 5:
                    if(authorize()){
                        printf("\u8bf7\u8f93\u5165\u4f1a\u5458\u5361\u7b49\u7ea7\uff1a\n");
                        scanf("%d",&t);
                        if(0<=t&&t<=8){
                            c->level=t;
                            printf("\u4fee\u6539\u6210\u529f\uff01\n");
                        }else
                            printf("\u9519\u8bef\uff1a\u975e\u6cd5\u6570\u636e\uff01\n");
                    }
                    break;
                case 6:
                    if(authorize()){
                        printf("\u8bf7\u8f93\u5165\u603b\u5145\u503c\u91d1\u989d\uff1a\n");
                        scanf("%lf",&money);
                        if(money<0)
                            printf("\u9519\u8bef\uff1a\u975e\u6cd5\u6570\u636e\uff01\n");
                        else{
                            c->total_charge=money;
                            printf("\u4fee\u6539\u6210\u529f\uff01\n");
                        }
                    }
                    break;
                case 7:
                    if(authorize()){
                        printf("\u8bf7\u8f93\u5165\u521b\u5efa\u65f6\u95f4\uff1a\n");
                        scanf("%d\\%d\\%d %d:%d",&y,&mo,&d,&h,&mi);
                        if(isTime(y,mo,d,h,mi)){
                            Time ti={y,mo,d,h,mi};
                            c->createTime=ti;
                            printf("\u4fee\u6539\u6210\u529f\uff01\n");
                        }else
                            printf("\u9519\u8bef\uff1a\u975e\u6cd5\u6570\u636e\uff01\n");
                    }
                    break;
                case 8:
                    if(authority!=2){
                        printf("\u8bf7\u8f93\u5165\u8981\u627e\u56de\u7684\u4f1a\u5458\u5361\u5361\u53f7\u6216\u7528\u6237\u624b\u673a\u53f7\uff1a\n");
                        s=getstr();
                        cardFind(s);
                    }else{
                        c->isLost=!c->isLost;
                        printf("\u4fee\u6539\u6210\u529f\uff01\n");
                    }
                    break;
                case 9:
                    if(authorize())
                        logFix(c->rechargeLog);
                    break;
                case 10:
                    if(authorize())
                        logFix(c->consumeLog);
                    break;
                default:
                    break;
            }
    system("pause");
    system("cls");
}