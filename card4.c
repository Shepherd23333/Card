#include"card.h"
void setTime(Time *t,int y,int mo,int d,int h,int mi){
    t->year=y;t->month=mo;t->day=d;t->hour=h;t->minute=mi;
}
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
    //todo
}
Card* cardFix(Card* c){
    printf("请选择你要修改的内容：\n");
    printf("(1.用户名  2.会员卡卡号  3.用户手机号  4.会员卡等级\n");
    printf("5.总消费金额  6.创建时间  7.丢失状态  8.充值记录\n");
    printf("9.消费记录)");
    int f,t,y,month,d,h,mi;
    double money;
    char *s;
    scanf("%d",&f);
    switch(f){
        case 1:
            printf("请输入新用户名：\n");
            s=getstr();
            strcpy(c->name,s);
            printf("修改成功！\n");
            break;
        case 2:
            if(authorize()){
                printf("请输入新卡号：\n");
                s=getstr();
                if(!cardSearch(cards,s)){
                    strcpy(c->number,s);
                    printf("修改成功！\n");
                }else
                    printf("错误：该卡号已存在！\n");
            }
            break;
        case 3:

            break;
        case 4:
            if(authorize()){
                printf("请输入会员卡等级：\n");
                scanf("%d",&t);
                c->level=t;
                printf("修改成功！\n");
            }
            break;
        case 5:
            if(authorize()){
                printf("请输入总消费金额：\n");
                scanf("%lf",&money);
                c->consumption=money;
                printf("修改成功！\n");
            }
            break;
        case 6:
            if(authorize()){
                printf("请输入创建时间：\n");
                scanf("%d %d %d %d %d",&y,&month,&d,&h,&mi);
                setTime(&(c->createTime),y,month,d,h,mi);
                printf("修改成功！\n");
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