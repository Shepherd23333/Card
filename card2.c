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
Card* cardSort()
{
    Card *p, *q, *tail;
    int exchange; //������־
    if(cards->next == NULL){ //������ֱ�ӷ���
        return cards;
    }
    do{
        exchange = 0; //��ʼ��������־
        tail = cards; //β�ڵ�ָ��ͷ�ڵ�
        p = cards->next; //pָ���һ���ڵ� //?
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

void cardFind(char* n)    //card2
{

}



 
void cardConsume(Card* c,double m)//��Ա�����Ѽ����ۿ�
{	                                                     	
	Card *p=c;
    double cost=m;                  
	system("cls");      
	if(p->short level>=5)//short level	��Ա���ȼ������ۿ��йأ�
	{                                                         
		printf("���Ļ�Ա���Ѿ��弶����������9���Żݡ�\n"); 
		printf("����ʵ������%.2fԪ��",cost*0.9);              
		cost*=0.9;
		if((p->remaining_sum-cost)<0)
		{                                                     //�ж�����Ƿ����
			printf("�Բ������㣬�뼰ʱ��ֵ��");
			getchar();
			menu();            
		}
		//p->cost+=cost;  //��ô��log���Ѽ�¼���θ� ��                                      
		p->remaining_sum-=cost;                                       //����
		getchar();
	}
	else
	{
		if((p->remaining_sum-cost)<0)
		{                                 //ͬ��
			printf("�Բ������㣬�뼰ʱ��ֵ��");
			getchar();
			menu();
		}
		//p->cost+=cost;//ͬ��
		p->remaining_sum-=cost;  
	}
	//modify_file(p);// ���ñ����޸Ļ�Ա��Ϣ�������ĸ���                                  
	system("cls");                                         
	//display_one(p);  //������ʾһ���������ĸ���������
	printf("����ɹ������������!");
	getch();
	menu();                                               //���ò˵�����
}





 //card2
//��¼����Ա�˺�֮�����
void menu()//��Ա��ϵͳ����
{
    printf("-----------------�˵�����----------------\n");
    printf("      1.�»�Աע��       2.��¼\n");
    printf("      3.��ʧ             4.�����Ϣ\n");
    printf("      5.��ѯ��Ϣ         6.��������\n");
    printf("      7.����ͳ��         8.�һ�\n");
    printf("      9.����             10.ϵͳά��\n");
    printf("      11.�˿�            0.�˳�\n");
    printf("----------��ӭʹ�û�Ա���Ʒ�ϵͳ----------\n");
    //���������ţ����룬
    //��ʱ��ͽ�����ĳ�����ݣ�������ֵ�����Ѽ�¼��
    
}
void test01() 
{
    int n=0,aa=0;
    do{
        menu();
        printf("��ѡ�������");
        scanf("%d", &n);
        switch(n)
        {
            case 1:
                cardSignUp();
                break;
            case 2:
                char* numorphone;
                char* password;
                
                printf("�������Ա�����Ż��ֻ��ţ� \n");
                scanf("%s",numorphone);
                printf("�������Ա�����룺 \n");
                scanf("%s",password);
                Card *c=cardLogIn(numorphone,password);
                printf("��ѡ��Ҫ���еĲ����� \n");
                printf("1.�޸���Ϣ   2.����\n");
                printf("3.��ֵ       0.�˳�\n");
                int a=0;
                scanf("%d", &a);
                switch(a)//��û�д�����
                {
                    case 1:
                        cardFix(c);
                        break;
                    case 2:
                        double m;
                        printf("�����뻨�ѽ�");
                        scanf("%lf", &m);
                        cardConsume(c,m);
                        break;
                    case 3:
                        double n;
                        printf("�������ֵ��");
                        scanf("%lf", &n);
                        cardRecharge(c,n);
                        break;
                    case 0:
                        cardLogOut();
                        printf("���˳����˺�\n");
                        break;
                    default:
                        printf("ERROR\n");
                        break;    
                }
                break;
            case 3:
                if(authorize())
                {
                     //cardLost();
                }
                break;
            case 4:
                
                printf("1.���������Ϣ     2.���ָ����������\n");
                scanf("%d", &aa);
                switch(aa)
                {
                    case 1:
                        cardPrints();
                        break;
                    case 2:
                        //cardPrint();//��ɶ����
                        break;
                    default:
                        printf("ERROR\n");
                        break;
                }
                break;
            case 5:
                //cardSearch();
                break;
            case 6:
                //cardSort();
                break;
            case 7:
                //cardSearchs();
                break;
            case 8:
            if(authorize())
                {
                     //cardFind();
                }
                break;
            case 9:
                
                break;
            case 10:
                
                break;
            case 11:
                //cardDelete(); //û����   
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