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
}*/
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
}

