#include"card.h"
/*
Card* cardExtend(Card *head) {
    Card card;
    printf("�������Ա����Ϣ��");
    printf("��Ա���ţ�");
    scanf("%s", card.number);
    printf("������");
    scanf("%s", card.name);
    printf("��");
    scanf("%f", &card.remaining_sum);

    Card *p_new = (Card *)malloc(sizeof(Card));
    p_new->Card = card;//����е�data������ģ��Ͻ�ѧ
    p_new->next = NULL;
//�����ѽ���ȼ��йأ���ûд
//�ȼ���ûд
    Card*p = head;
    while (p->next) {
        p = p->next;
    }
    p->next = p_new;
    printf("��Ա����ӳɹ���");
}*//*
void cardSort(Card* head)
{
    Card *p, *q, *tail;
    int exchange; //������־
    if(head->next == NULL){ //������ֱ�ӷ���
        return;
    }
    do{
        exchange = 0; //��ʼ��������־
        tail = head; //β�ڵ�ָ��ͷ�ڵ�
        p = head->next; //pָ���һ���ڵ�
        while(p->next != NULL){ //��������
            q = p->next; //qָ����һ���ڵ�
            if(p->number > q->number){ //���p�ڵ����q�ڵ�
                tail->next = q; //��q�ڵ���뵽β�ڵ����
                p->next = q->next;
                q->next = p;
                tail = q; //����β�ڵ�
                exchange = 1; //���ý�����־
            }else{ //�������κβ���
                tail = p;
                p = p->next;
            }
        }
    }while(exchange); //�����ڽ���ʱ��������
}*/


//��¼����Ա�˺�֮�����
void menu()
{
    printf("*****************�˵�����****************\n");
    printf("      1.�»�Ա�Ǽ�       2.��Ա��Ϣά��\n");
    printf("      3.����             4.����\n");
    printf("      5.�˿�             6.��ʧ\n");
    printf("      7.��ѯ             8.����\n");
    printf("      9.ͳ��             10.ϵͳά��\n");
    printf("      11.����            0.�˳�\n");
    printf("**********��ӭʹ�û�Ա���Ʒ�ϵͳ**********\n");
    //���������ţ����룬
    //��ʱ��ͽ�����ĳ�����ݣ�������ֵ�����Ѽ�¼��
}
void test01() 
{
    int n=0;
    do{
    
        menu();
        printf("��ѡ��Ҫ���ԵĲ�����");
        scanf("%d", &n);
        switch(n)
        {
            case 1:
                
                break;
            case 2:
                
                break;
            case 3:
                
                break;
            case 4:
                
                break;
            case 5:
                
                break;
            case 6:
                Card* cardLost(Card*,char*);
                break;
            case 7:
                
                break;
            case 8:
                
                break;
            case 9:
                
                break;
            case 10:
                
                break;
            case 11:
                
                break;
            case 0:
                printf("�˳�ϵͳ\n");
                break;
            default:
            printf("ERROR\n");
                break;
        }
    }
    while(n != 0);
    
}