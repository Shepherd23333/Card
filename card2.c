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
/*Card* cardSort()
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
}*/
//��δ�޸��Ե�
void cardPrint(Card* c);  //card2
{
    if(c==NULL) return;
    Card *member = c;
    printf("���  ����  �Ա�  �绰  ���\n");//�ѻ�Ա��Ϣ��Ӧ�ϲ��������ȥ��ʱ��ʲô��Ҳд��
    if (member)
    {
        printf("%s %s %s %.1f %.1f\n\n", member->name, member->sex, member->phone, member->money,member->paysum);
    }
    else
        printf("�û�Ա������\n");
}
void cardPrints();     //card2
{
    vip *member=NULL;
    int count = 1;
    for (member = head; member != NULL; member = member->next)
    {
        printf("%d %s %s %s %.1f %.1f\n", count++, member->name, member->sex, member->phone, member->money,member->paysum);
    }
    printf("\n\n");
}
Card *cardSort()//�ð������head�ĳ�cards���ã�
{      
    printf("��ѡ���������ַ�ʽ���򣨿��Զ�ѡ��\n");
    printf("1.���ɷ��ܶ���������    2.�����ѽ����������\n");
    printf("3.���ɷ��ܶ������    4.�����ѽ�������\n");
    printf("5.����Ա���ȼ���������  6.����Ա���ȼ���������\n");
    printf("7.����Ա��������������  8.����Ա�����Ž�������\n");
    printf("9.���ֻ�����������      10.���ֻ��Ž�������\n");
    int t;
    scanf("%d", &t);//��ô��ѡ
    switch(t)
    case 1:                           
            Card *q,*tail,*p=(Card*)malloc(sizeof(Card)); //���ɷ��ܶ�����
            p->next=cards;
            cards=p;
            tail=NULL;                                                  //���� tail
            while(tail!=cards->next)
            {
                p=cards;
                q=p->next;
                while(q->next!=tail)
                {                                                        //�ж� q�Ƿ�Ϊ��
                    if(p->next->total_charge>q->next->total_charge)
                    {
                        p->next=q->next;                                 //�Ƚϴ�С������
                        q->next=q->next->next;
                        p->next->next=q;
                    }
                    p=p->next;
                    q=p->next;
                }
                tail=q;
            }
            cards=cards->next;
            free(p);
            return cards;                                                  //����ֵ
            break;
    case 3:                           
            Card *q,*tail,*p=(Card*)malloc(sizeof(Card)); //���ɷ��ܶ�����
            p->next=cards;
            cards=p;
            tail=NULL;                                                  //���� tail
            while(tail!=cards->next)
            {
                p=cards;
                q=p->next;
                while(q->next!=tail)
                {                                                        //�ж� q�Ƿ�Ϊ��
                    if(p->next->total_charge<q->next->total_charge)
                    {
                        p->next=q->next;                                 //�Ƚϴ�С������
                        q->next=q->next->next;
                        p->next->next=q;
                    }
                    p=p->next;
                    q=p->next;
                }
                tail=q;
            }
            cards=cards->next;
            free(p);
            return cards;  
            break;
    case 2:                                                
            card *q,*tail,*p=(card*)malloc(sizeof(card));                 //�����ѽ������
            p->next=cards;
            cards=p;
            tail=NULL;                                                     //���� tail
            while(tail!=cards->next)
            {
                p=cards;
                q=p->next;
                while(q->next!=tail)
                {
                    if(p->next->total_charge-remaining_sum>q->next->total_charge-remaining_sum)
                    {                                                    //�Ƚϴ�С������
                        p->next=q->next;
                        q->next=q->next->next;
                        p->next->next=q;
                    }
                    p=p->next;
                    q=p->next;
                }
                tail=q;
            }
            cards=cards->next;
            free(p);
            return cards;                                        //����ֵ
            break;   
    case 4:                                                
            card *q,*tail,*p=(card*)malloc(sizeof(card));                 //�����ѽ������
            p->next=cards;
            cards=p;
            tail=NULL;                                                     //���� tail
            while(tail!=cards->next)
            {
                p=cards;
                q=p->next;
                while(q->next!=tail)
                {
                    if(p->next->total_charge-remaining_sum<q->next->total_charge-remaining_sum)
                    {                                                    //�Ƚϴ�С������
                        p->next=q->next;
                        q->next=q->next->next;
                        p->next->next=q;
                    }
                    p=p->next;
                    q=p->next;
                }
                tail=q;
            }
            cards=cards->next;
            free(p);
            return cards;                                        //����ֵ
            break;          

}

void logPrint(Log* l) 
{
    if (l == NULL) return;
    printf("����ʱ�䣺%u��%02u��%02u��%02uʱ%02u��\n", l->time.year, l->time.month, l->time.day, l->time.hour, l->time.minute);
    printf("���׽�%.2lfԪ\n", l->money);
}
void logPrints(Log* head)
{
    if (head == NULL) return;
    Log* cur = head;
    while (cur != NULL) 
    {

        printf("����ʱ�䣺%u��%02u��%02u��%02uʱ%02u��\n", cur->time.year, cur->time.month, cur->time.day, cur->time.hour, cur->time.minute);
        printf("���׽�%.2lfԪ\n", cur->money);
        cur = cur->next;
    }
}


void cardFind(char* c)    //card2//�ⶳ
{
    Card* p=cardSearch(c);
    if(p->isLost!=1)
    {
        printf("�˿�δ���й�ʧ���޷������һز���\n");
    }
    else
    if(cardIdentity(p))   //bool isLost	�Ƿ�ʧ���Ѷ�ʧ�Ŀ��޷�ʹ�ã�
    {
        p->isLost=0;
    }
    else 
    {
        printf("δͨ����֤���޷������һز���\n");
    }
    
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
		//p->cost+=cost;   //ͬ��
		p->remaining_sum-=cost;  
	}
	//modify_file(p);// ���ñ����޸Ļ�Ա��Ϣ�������ĸ���                                  
	system("cls");                                         
	//display_one(p);  //������ʾһ���������ĸ���������
	printf("����ɹ������������!");
	getch();
}
Admin *adminExtend(Admin *head)  //card2
{
    Admin *p1 = head;
    if (head != NULL)
    {
        while (p1->next!= NULL)
        {
            p1 = p1->next;
        }
        p1 = p1->next = (Admin *)malloc(LENAdmin);
        strcpy(p1->username, "");
        strcpy(p1->password, "");
        p1->isSuper=false;
    }
    return (p1);
}


//��¼����Ա�˺�֮�����
void menu()//��Ա��ϵͳ����
{
    printf("-----------------�˵�����----------------\n");
    printf("      1.�»�Աע��       2.��¼\n");
    printf("      3.  ��           4.�����Ϣ\n");
    printf("      5.��ѯ��Ϣ         6.��������\n");
    printf("      7.����ͳ��         8.��\n");
    printf("      9.  ��               10.ϵͳά��\n");
    printf("      11.��            0.�˳�\n");
    printf("----------��ӭʹ�û�Ա���Ʒ�ϵͳ----------\n");
    //���������ţ����룬
    //��ʱ��ͽ�����ĳ�����ݣ�������ֵ�����Ѽ�¼��
    
}
void test01() 
{
    int n=0,aa=0;
    do{
        system("cls");
        menu();
        printf("��ѡ�������");
        scanf("%d", &n);
        switch(n)
        {
            case 1://ע��
                cardSignUp();
                break;
            case 2://��Ա��¼
                char* numorphone;
                char* password;
                printf("�������Ա�����Ż��ֻ��ţ� \n");
                numorphone=getstr();
                printf("�������Ա�����룺 \n");
                password=getstr();
                Card *c=cardLogIn(numorphone,password);
                if(!c)
                {
                    printf("��¼ʧ�ܣ�");
                    break;
                }
                else
                {
                    printf("��ѡ��Ҫ���еĲ����� \n");
                    printf("1.�޸���Ϣ   2.����\n");
                    printf("3.��ֵ       4.��ʧ\n");
                    printf("5.�һ�       6.�˿�\n");
                    printf("0.�˳�\n");
                    int a=0;
                    scanf("%d", &a);
                    switch (a) // ��û�д�����
                    {
                        case 1://�޸���Ϣ
                        cardFix(c);
                        break;
                        case 2://����
                        double m;
                        printf("�����뻨�ѽ�");
                        scanf("%lf", &m);
                        cardConsume(c, m);
                        break;
                        case 3://��ֵ
                        double n;
                        printf("�������ֵ��");
                        scanf("%lf", &n);
                        cardRecharge(c, n);
                        break;
                        case 4: // ��ʧ
                        if (cardIdentify(c))
                        {
                            cardLost(c);
                            printf("��ʧ�ɹ������������!");
                            getch();
                        }
                        break;
                        case 5://�һ�
                        if(cardIdentify(c)){
                            cardFind(c);//�����
                        }
                        break;
                        case 6://�˿�
                        if (cardIdentify(c))
                        {
                            cards=cardDelete(c);
                            printf("�˿��ɹ������������!");
                            getch();
                        }
                        else
                        {
                        printf("��Ա�������֤���������ԣ����������\n");//������ô�ص�Identify����ѽ
                        getch();
                        }
                        case 0:
                        cardLogOut();
                        printf("���˳����˺�\n");
                        break;
                        default:
                        printf("ERROR\n");
                        break;
                    }
                    break;
                }
            case 4://�����Ϣ 
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
            case 5://��ѯ��Ϣ
                //cardSearch();
                break;
            case 6://��������
                card* c=cardSort();
                cardPrints(c);
                break;
            case 7://����ͳ��
                //cardSearchs();
                break;
            
            case 9:
                
                break;
            case 10://ϵͳά��
                cards=cardFix();//��ʲô�Σ��θ���治��
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