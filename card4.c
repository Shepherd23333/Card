#include"card.h"
void setTime(Time t,int y,int mo,int d,int h,int mi){
    t.year=y;t.month=mo;t.day=d;t.hour=h;t.minute=mi;
}
Log* logFix(Log* head){
    //todo
}
Card* cardFix(Card* c){
    printf("��ѡ����Ҫ�޸ĵ����ݣ�\n");
    printf("(1.�û���  2.��Ա������  3.��Ա���ȼ�  4.�����ѽ��\n");
    printf("5.����ʱ��  6.��ʧ״̬  7.��ֵ��¼  8.���Ѽ�¼)\n");
    int f,t,y,month,d,h,mi;
    float money;
    char *s;
    scanf("%d",&f);
    switch(f){
        case 1:
            printf("���������û�����\n");
            gets(s);
            strcpy(c->name,s);
            printf("�޸ĳɹ���\n");
            break;
        case 2:
            printf("�������¿��ţ�\n");
            gets(s);
            strcpy(c->number,s);
            printf("�޸ĳɹ���\n");
            break;
        case 3:
            if(authorize()){
                printf("�������Ա���ȼ���\n");
                scanf("%d",&t);
                c->level=t;
                printf("�޸ĳɹ���\n");
            }
            break;
        case 4:
            if(authorize()){
                printf("�����������ѽ�\n");
                scanf("%f",&money);
                c->comsumption=money;
                printf("�޸ĳɹ���\n");
            }
            break;
        case 5:
            if(authorize()){
                printf("�����봴��ʱ�䣺\n");
                scanf("%d %d %d %d %d",&y,&month,&d,&h,&mi);
                setTime(c->createTime,y,month,d,h,mi);
                printf("�޸ĳɹ���\n");
            }
            break;
        case 6:
            //todo
            break;
        case 7:
    }
    printf("�����������...");
    getchar();
    system("cls");
}