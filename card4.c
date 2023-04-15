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
void logFix(Log* head){
    logPrint(head);
    printf("��ָ����Ҫ�޸ĵĽ��׼�¼��\n");
    double money;
    int y,mo,d,h,mi,t;
    scanf("%lf %d\\%d\\%d %d:%d",&money,&y,&mo,&d,&h,&mi);
    if(money>=0&&isTime(y,mo,d,h,mi)){
        Time ti={y,mo,d,h,mi};
        Log *l;
        if(l=logSearch(head,money,ti)){
            printf("��ѡ����Ҫ�޸ĵ����ݣ�����ͬʱ�޸Ķ������ݣ�����0�����޸ģ���\n");
            printf("(1.���׽��  2.����ʱ�䣩\n");
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
                            printf("�����뽻�׽�\n");
                            scanf("%lf",&money);
                            if(money<0)
                                printf("���󣺷Ƿ����ݣ�\n");
                            else{
                                l->money=money;
                                printf("�޸ĳɹ���\n");
                            }
                            break;
                        case 2:
                            printf("�����뽻��ʱ�䣺\n");
                            scanf("%d\\%d\\%d %d:%d",&y,&mo,&d,&h,&mi);
                            if(isTime(y,mo,d,h,mi)){
                                Time tim={y,mo,d,h,mi};
                                l->time=tim;
                                printf("�޸ĳɹ���\n");
                            }else
                                printf("���󣺷Ƿ����ݣ�\n");
                            break;
                    }
        }else
            printf("�����Ҳ��������ݣ�\n");
    }else
        printf("���󣺷Ƿ����ݣ�\n");
}
void cardFix(Card* c){
    printf("��ѡ����Ҫ�޸ĵ����ݣ�����ͬʱ�޸Ķ������ݣ�����0�����޸ģ���\n");
    printf("(1.�û���  2.��Ա������  3.�û��ֻ���  4.��Ա������\n");
    printf("5.��Ա���ȼ�  6.�ܳ�ֵ���  7.����ʱ��  8.��ʧ״̬\n");
    printf("9.��ֵ��¼  10.���Ѽ�¼)\n");
    int f[11]={0},t,y,mo,d,h,mi;
    double money;
    char *s;
    scanf("%d",&t);
    while(t){
        f[t]=1;
        scanf("%d",&t);
    }
    for(int i=1;i<11;i++)
        if(f[i])
            switch(i){
                case 1:
                    printf("���������û�����\n");
                    s=getstr();
                    if(isalpha(s[0])||s[0]<=-1731190){
                        strcpy(c->name,s);
                        printf("�޸ĳɹ���\n");
                    }
                    else
                        printf("���󣺷Ƿ����ݣ�\n");
                    break;
                case 2:
                    if(authorize()){
                        printf("�������¿��ţ�\n");
                        s=getstr();
                        if(s[0]!='c'||strspn(s+1,"0123456789")!=strlen(s+1))
                            printf("���󣺷Ƿ����ݣ�\n");
                        else if(!cardSearch(cards,s)){
                            strcpy(c->number,s);
                            printf("�޸ĳɹ���\n");
                        }else
                            printf("���󣺸ÿ����Ѵ��ڣ�\n");
                    }
                    break;
                case 3:
                    if(authorize()){
                        printf("���������ֻ��ţ�\n");
                        s=getstr();
                        if(strlen(s)!=11||strspn(s,"0123456789")!=strlen(s))
                            printf("���󣺷Ƿ����ݣ�\n");
                        else if(!cardSearch(cards,s)){
                            strcpy(c->phone,s);
                            printf("�޸ĳɹ���\n");
                        }else
                            printf("���󣺸��ֻ����ѱ�ʹ�ã�\n");
                    }else
                        cardUpdatePhone(c);
                    break;
                case 4:
                    if(authority!=2)
                        cardUpdatePassword(c);
                    else{
                        printf("�����������룺\n");
                        s=getstr();
                        strcpy(c->password,s);
                        printf("�޸ĳɹ���\n");
                    }
                    break;
                case 5:
                    if(authorize()){
                        printf("�������Ա���ȼ���\n");
                        scanf("%d",&t);
                        if(0<=t&&t<=8){
                            c->level=t;
                            printf("�޸ĳɹ���\n");
                        }else
                            printf("���󣺷Ƿ����ݣ�\n");
                    }
                    break;
                case 6:
                    if(authorize()){
                        printf("�������ܳ�ֵ��\n");
                        scanf("%lf",&money);
                        if(money<0)
                            printf("���󣺷Ƿ����ݣ�\n");
                        else{
                            c->total_charge=money;
                            printf("�޸ĳɹ���\n");
                        }
                    }
                    break;
                case 7:
                    if(authorize()){
                        printf("�����봴��ʱ�䣺\n");
                        scanf("%d\\%d\\%d %d:%d",&y,&mo,&d,&h,&mi);
                        if(isTime(y,mo,d,h,mi)){
                            Time ti={y,mo,d,h,mi};
                            c->createTime=ti;
                            printf("�޸ĳɹ���\n");
                        }else
                            printf("���󣺷Ƿ����ݣ�\n");
                    }
                    break;
                case 8:
                    if(authority!=2){
                        printf("������Ҫ�һصĻ�Ա�����Ż��û��ֻ��ţ�\n");
                        s=getstr();
                        cardFind(s);
                    }else{
                        c->isLost=!c->isLost;
                        printf("�޸ĳɹ���\n");
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