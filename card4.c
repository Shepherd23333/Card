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
Log* logFix(Log* head){
    logPrint(head);
    printf("请指定需要修改的交易记录：\n");
    double money;
    int y,mo,d,h,mi,t;
    scanf("%lf %d\\%d\\%d %d:%d",&money,&y,&mo,&d,&h,&mi);
    if(money>=0&&isTime(y,mo,d,h,mi)){
        Time ti={y,mo,d,h,mi};
        Log *l;
        if(l=logSearch(head,money,ti)){
            printf("请选择你要修改的内容（允许同时修改多项数据，输入0结束修改）：\n");
            printf("(1.交易金额  2.交易时间）\n");
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
                            printf("请输入交易金额：\n");
                            scanf("%lf",&money);
                            if(money<0)
                                printf("错误：非法数据！\n");
                            else{
                                l->money=money;
                                printf("修改成功！\n");
                            }
                            break;
                        case 2:
                            printf("请输入交易时间：\n");
                            scanf("%d\\%d\\%d %d:%d",&y,&mo,&d,&h,&mi);
                            if(isTime(y,mo,d,h,mi)){
                                Time tim={y,mo,d,h,mi};
                                l->time=tim;
                                printf("修改成功！\n");
                            }else
                                printf("错误：非法数据！\n");
                            break;
                    }
        }else
            printf("错误：找不到该数据！\n");
    }else
        printf("错误：非法数据！\n");
}
Card* cardFix(Card* c){
    printf("请选择你要修改的内容（允许同时修改多项数据，输入0结束修改）：\n");
    printf("(1.用户名  2.会员卡卡号  3.用户手机号  4.会员卡等级\n");
    printf("5.总充值金额  6.创建时间  7.丢失状态  8.充值记录\n");
    printf("9.消费记录)\n");
    int f[10]={0},t,y,mo,d,h,mi;
    double money;
    char *s;
    scanf("%d",&t);
    while(t){
        f[t]=1;
        scanf("%d",&t);
    }
    for(int i=1;i<10;i++)
        if(f[i])
            switch(i){
                case 1:
                    printf("请输入新用户名：\n");
                    s=getstr();
                    if(!isalpha(s[0]))
                        printf("错误：非法数据！\n");
                    else{
                        strcpy(c->name,s);
                        printf("修改成功！\n");
                    }
                    break;
                case 2:
                    if(authorize()){
                        printf("请输入新卡号：\n");
                        s=getstr();
                        if(s[0]!='c')
                            printf("错误：非法数据！\n");
                        else if(!cardSearch(cards,s)){
                            strcpy(c->number,s);
                            printf("修改成功！\n");
                        }else
                            printf("错误：该卡号已存在！\n");
                    }
                    break;
                case 3:
                    if(authorize()){
                        printf("请输入新手机号：\n");
                        s=getstr();
                        if(strlen(s)!=11)
                            printf("错误：非法数据！\n");
                        else if(!cardSearch(cards,s)){
                            strcpy(c->phone,s);
                            printf("修改成功！\n");
                        }else
                            printf("错误：该手机号已被使用！\n");
                    }else
                        cardNewPhone(cards,c->number);
                    break;
                case 4:
                    if(authorize()){
                        printf("请输入会员卡等级：\n");
                        scanf("%d",&t);
                        if(0<=t&&t<=8){
                            c->level=t;
                            printf("修改成功！\n");
                        }else
                            printf("错误：非法数据！\n");
                    }
                    break;
                case 5:
                    if(authorize()){
                        printf("请输入总充值金额：\n");
                        scanf("%lf",&money);
                        if(money<0)
                            printf("错误：非法数据！\n");
                        else{
                            c->total_charge=money;
                            printf("修改成功！\n");
                        }
                    }
                    break;
                case 6:
                    if(authorize()){
                        printf("请输入创建时间：\n");
                        scanf("%d\\%d\\%d %d:%d",&y,&mo,&d,&h,&mi);
                        if(isTime(y,mo,d,h,mi)){
                            Time ti={y,mo,d,h,mi};
                            c->createTime=ti;
                            printf("修改成功！\n");
                        }else
                            printf("错误：非法数据！\n");
                    }
                    break;
                case 7:
                    if(authority!=2){
                        printf("请输入要找回的会员卡卡号或用户手机号：\n");
                        s=getstr();
                        cardFind(c,s);
                    }else{
                        c->isLost=!c->isLost;
                        printf("修改成功！\n");
                    }
                    break;
                case 8:
                    if(authorize())
                        logFix(c->rechargeLog);
                    break;
                case 9:
                    if(authorize())
                        logfix(c->consumeLog);
                    break;
            }
    system("pause");
    system("cls");
}