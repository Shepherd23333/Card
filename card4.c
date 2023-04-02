#include"card.h"
void setTime(Time t,int y,int mo,int d,int h,int mi){
    t.year=y;t.month=mo;t.day=d;t.hour=h;t.minute=mi;
}
Log* logFix(Log* head){
    //todo
}
Card* cardFix(Card* c){
    printf("请选择你要修改的内容：\n");
    printf("(1.用户名  2.会员卡卡号  3.会员卡等级  4.总消费金额\n");
    printf("5.创建时间  6.丢失状态  7.充值记录  8.消费记录)\n");
    int f,t,y,month,d,h,mi;
    float money;
    char *s;
    scanf("%d",&f);
    switch(f){
        case 1:
            printf("请输入新用户名：\n");
            gets(s);
            strcpy(c->name,s);
            printf("修改成功！\n");
            break;
        case 2:
            printf("请输入新卡号：\n");
            gets(s);
            strcpy(c->number,s);
            printf("修改成功！\n");
            break;
        case 3:
            if(authorize()){
                printf("请输入会员卡等级：\n");
                scanf("%d",&t);
                c->level=t;
                printf("修改成功！\n");
            }
            break;
        case 4:
            if(authorize()){
                printf("请输入总消费金额：\n");
                scanf("%f",&money);
                c->comsumption=money;
                printf("修改成功！\n");
            }
            break;
        case 5:
            if(authorize()){
                printf("请输入创建时间：\n");
                scanf("%d %d %d %d %d",&y,&month,&d,&h,&mi);
                setTime(c->createTime,y,month,d,h,mi);
                printf("修改成功！\n");
            }
            break;
        case 6:
            //todo
            break;
        case 7:
    }
    printf("按任意键继续...");
    getchar();
    system("cls");
}