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
    printf("��ѡ����Ҫ�޸ĵ����ݣ�\n");
    printf("(1.�û���  2.��Ա������  3.�û��ֻ���  4.��Ա���ȼ�\n");
    printf("5.�����ѽ��  6.����ʱ��  7.��ʧ״̬  8.��ֵ��¼\n");
    printf("9.���Ѽ�¼)");
    int f,t,y,month,d,h,mi;
    double money;
    char *s;
    scanf("%d",&f);
    switch(f){
        case 1:
            printf("���������û�����\n");
            s=getstr();
            strcpy(c->name,s);
            printf("�޸ĳɹ���\n");
            break;
        case 2:
            if(authorize()){
                printf("�������¿��ţ�\n");
                s=getstr();
                if(!cardSearch(cards,s)){
                    strcpy(c->number,s);
                    printf("�޸ĳɹ���\n");
                }else
                    printf("���󣺸ÿ����Ѵ��ڣ�\n");
            }
            break;
        case 3:

            break;
        case 4:
            if(authorize()){
                printf("�������Ա���ȼ���\n");
                scanf("%d",&t);
                c->level=t;
                printf("�޸ĳɹ���\n");
            }
            break;
        case 5:
            if(authorize()){
                printf("�����������ѽ�\n");
                scanf("%lf",&money);
                c->consumption=money;
                printf("�޸ĳɹ���\n");
            }
            break;
        case 6:
            if(authorize()){
                printf("�����봴��ʱ�䣺\n");
                scanf("%d %d %d %d %d",&y,&month,&d,&h,&mi);
                setTime(&(c->createTime),y,month,d,h,mi);
                printf("�޸ĳɹ���\n");
            }
            break;
        case 7:
            if(authority!=2){
                printf("������Ҫ�һصĻ�Ա�����Ż��û��ֻ��ţ�\n");
                s=getstr();
                cardFind(c,s);
            }else{
                c->isLost=!c->isLost;
                printf("�޸ĳɹ���\n");
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