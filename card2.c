#include"card.h"

void logPrint(Log* l) 
{
    if (l == NULL) return;
    printf("\u4ea4\u6613\u65f6\u95f4\uff1a%u\\%02u\\%02u %02u:%02u\n", l->time.year, l->time.month, l->time.day, l->time.hour, l->time.minute);
    printf("\u4ea4\u6613\u91d1\u989d\uff1a%.2lf\n", l->money);
}
void logPrints(Log* head)
{
    if (head == NULL) return;
    Log* cur = head;
    while (cur != NULL) 
    {

        printf("\u4ea4\u6613\u65f6\u95f4\uff1a%u\\%02u\\%02u %02u:%02u\n", cur->time.year, cur->time.month, cur->time.day, cur->time.hour, cur->time.minute);
        printf("\u4ea4\u6613\u91d1\u989d\uff1a%.2lf\n", cur->money);
        cur = cur->next;
    }
}
void cardPrint(Card* c)  //card2
{
    if(c==NULL) 
    {
    printf("\u8be5\u4f1a\u5458\u4e0d\u5b58\u5728\n");
    return;
    }
    else
    {
    Card *cur = c;
    printf("\u59d3\u540d\uff1a %s\n", cur->name);
    printf("\u5361\u53f7\uff1a %s\n", cur->number);
    printf("\u624b\u673a\u53f7\uff1a %s\n", cur->phone);
    printf("\u5bc6\u7801\uff1a %s\n", cur->password);
    printf("\u7b49\u7ea7\uff1a %d\n", cur->level);
    printf("\u4f59\u989d\uff1a %.2lf\n", cur->remaining_sum);
    printf("\u603b\u5145\u503c\uff1a %.2lf\n", cur->total_charge);
    printf("\u603b\u6d88\u8d39\uff1a %.2lf\n", cur->total_charge - cur->remaining_sum);
    printf("\u521b\u5efa\u65f6\u95f4\uff1a %u\\%02u\\%02u\\%02u\\%02u\n", cur->createTime.year, cur->createTime.month, cur->createTime.day, cur->createTime.hour, cur->createTime.minute);
    printf("\u6709\u6548\u65f6\u95f4\uff1a %u\\%02u\\%02u\\%02u\\%02u\n", cur->createTime.year, cur->createTime.month, cur->createTime.day, cur->createTime.hour, cur->createTime.minute);
    printf("\u662f\u5426\u6302\u5931\uff1a ");
    if (cur->isLost)
        printf("\u662f\n");
    else
        printf("\u5426\n");
    }
        
}

void cardPrints() 
{
    if (cards == NULL) return;
    Card* cur = cards;
    while (cur != NULL) 
    {
    printf("\u59d3\u540d\uff1a %s\n", cur->name);
    printf("\u5361\u53f7\uff1a %s\n", cur->number);
    printf("\u624b\u673a\u53f7\uff1a %s\n", cur->phone);
    printf("\u5bc6\u7801\uff1a %s\n", cur->password);
    printf("\u7b49\u7ea7\uff1a %d\n", cur->level);
    printf("\u4f59\u989d\uff1a %.2lf\n", cur->remaining_sum);
    printf("\u603b\u5145\u503c\uff1a %.2lf\n", cur->total_charge);
    printf("\u603b\u6d88\u8d39\uff1a %.2lf\n", cur->total_charge - cur->remaining_sum);
    printf("\u521b\u5efa\u65f6\u95f4\uff1a %u\\%02u\\%02u\\%02u\\%02u\n", cur->createTime.year, cur->createTime.month, cur->createTime.day, cur->createTime.hour, cur->createTime.minute);
    printf("\u6709\u6548\u65f6\u95f4\uff1a %u\\%02u\\%02u\\%02u\\%02u\n", cur->createTime.year, cur->createTime.month, cur->createTime.day, cur->createTime.hour, cur->createTime.minute);
    printf("\u662f\u5426\u6302\u5931\uff1a ");
    if (cur->isLost)
        printf("\u662f\n");
    else
        printf("\u5426\n");
        cur = cur->next;
    }
}

Card* cardSort() 
{
    printf("\u8bf7\u9009\u62e9\u5347\u5e8f\u6216\u964d\u5e8f\u6392\u5217\uff08\u0030\u8868\u793a\u5347\u5e8f\uff0c\u0031\u8868\u793a\u964d\u5e8f\uff09\n");
    int turn,sortNum=0;
    scanf("%d",&turn);
    printf("\u8bf7\u9009\u62e9\u6309\u4ee5\u4e0b\u54ea\u79cd\u65b9\u5f0f\u6392\u5e8f\uff08\u53ef\u4ee5\u591a\u9009\uff09\n");
    printf("1.\u59d3\u540d      2.\u5361\u53f7\n");
    printf("3.\u624b\u673a\u53f7    4.\u7b49\u7ea7\n");
    printf("5.\u7f34\u8d39\u603b\u989d  6.\u6d88\u8d39\u91d1\u989d\n");
    printf("7.\u5361\u5185\u4f59\u989d\n");
    int sortIndex[10];
    while(scanf("%d", &sortIndex[sortNum])!=EOF)
    {
        sortNum++;
    }
    if (cards == NULL || sortIndex == NULL || sortNum == 0) return cards;
    Card* arr[10000];
    int len = 0;
    Card* cur = cards;
    while (cur != NULL) 
    {
        arr[len++] = cur;
        cur = cur->next;
    }
    for (int i = 0; i < sortNum; i++) {
    
        switch(sortIndex[i])
         {
            case 1://byname
                for (int i = 0; i < len; i++)
                {
                    for (int j = 0; j < len - i - 1; j++)
                    {
                        if (strcmp(arr[j]->name, arr[j+1]->name) > 0)
                        {
                            Card* tmp = arr[j];
                            arr[j] = arr[j+1];
                            arr[j+1] = tmp;
                        }
                    }
                }
                 break;
            case 2://bynumber
                for (int i = 0; i < len; i++)
                {
                    for (int j = 0; j < len - i - 1; j++)
                    {
                        if (strcmp(arr[j]->number, arr[j+1]->number) > 0)
                        {
                            Card* tmp = arr[j];
                            arr[j] = arr[j+1];
                            arr[j+1] = tmp;
                        }
                    }
                }
                 break;
            case 3://byphone
                for (int i = 0; i < len; i++)
                {
                    for (int j = 0; j < len - i - 1; j++)
                    {
                        if (strcmp(arr[j]->phone, arr[j+1]->phone) > 0)
                        {
                            Card* tmp = arr[j];
                            arr[j] = arr[j+1];
                            arr[j+1] = tmp;
                        }
                    }
                }
                break;
            case 4://bylevel
                for (int i = 0; i < len; i++)
                {
                    for (int j = 0; j < len - i - 1; j++)
                    {
                        if (arr[j]->level > arr[j+1]->level)
                        {
                            Card* tmp = arr[j];
                            arr[j] = arr[j+1];
                            arr[j+1] = tmp;
                        }
                    }
                }
                break;
            case 5://bytotal_charge
                for (int i = 0; i < len; i++)
                {
                    for (int j = 0; j < len - i - 1; j++)
                    {
                        if (arr[j]->total_charge > arr[j+1]->total_charge)
                        {
                            Card* tmp = arr[j];
                            arr[j] = arr[j+1];
                            arr[j+1] = tmp;
                        }
                    }
                }
                break;
            case 6://bycost
                for (int i = 0; i < len; i++)
                {
                    for (int j = 0; j < len - i - 1; j++)
                    {
                        if (arr[j]->total_charge-arr[j]->remaining_sum > arr[j+1]->total_charge-arr[j+1]->remaining_sum)
                        {
                            Card* tmp = arr[j];
                            arr[j] = arr[j+1];
                            arr[j+1] = tmp;
                        }
                    }
                } 
                break;
                
            case 7:  //byremaining_sum
                for (int i = 0; i < len; i++)
                {
                    for (int j = 0; j < len - i - 1; j++)
                    {
                        if (arr[j]->remaining_sum > arr[j+1]->remaining_sum)
                        {
                            Card* tmp = arr[j];
                            arr[j] = arr[j+1];
                            arr[j+1] = tmp;
                        }
                    }
                }
                break;
            default:
                printf("\u65e0\u6cd5\u8bc6\u522b\u7684\u6392\u5e8f\u9009\u9879\uff1a%d\n", sortIndex[i]); 
                break;
        }
    }
    
    Card* head = arr[0];
    cur = arr[0];
    if(turn==0)
    {
        for (int i = 1; i < len; i++)
        {
            cur->next = arr[i];
            cur = cur->next;
        }
        cur->next = NULL;
        return head;
    }
    else
    {
        for (int i = len-1; i > 0; i--)
        {
            cur->next = arr[i];
            cur = cur->next;
        }
        cur->next = NULL;
        return head;
    }
}

void cardFind(char* c)    //card2
{
    Card* p=c;
    if(p->isLost!=1)
    {
        printf("\u6b64\u5361\u672a\u8fdb\u884c\u6302\u5931\uff0c\u65e0\u6cd5\u8fdb\u884c\u627e\u56de\u64cd\u4f5c\n");
    }
    else
    if(cardIdentify(p))   
    {
        p->isLost=0;
    }
    else 
    {
        printf("\u672a\u901a\u8fc7\u9a8c\u8bc1\uff0c\u65e0\u6cd5\u8fdb\u884c\u627e\u56de\u64cd\u4f5c\n");
    }
    
}
void cardConsume(Card* c,double m)
{	                                                     	
	Card *p=c;
    double cost=m;                  
	system("cls");      
	if(p->level>=5)//short level	
	{                                                         
		printf("\u60a8\u7684\u4f1a\u5458\u5361\u5df2\u7ecf\u4e94\u7ea7\uff0c\u672c\u6b21\u6d88\u8d39\u0039\u6298\u4f18\u60e0\u3002\n"); 
		printf("\u672c\u6b21\u5b9e\u9645\u6d88\u8d39%.2f\u5143\uff01",cost*0.9);              
		cost*=0.9;
		if((p->remaining_sum-cost)<0)
		{                                                     
			printf("\u5bf9\u4e0d\u8d77\uff0c\u4f59\u989d\u4e0d\u8db3\uff0c\u8bf7\u53ca\u65f6\u5145\u503c\uff01");
			getchar();
			menu();            
		}                                      
		p->remaining_sum-=cost;                                       
		getchar();
	}
	else
	{
		if((p->remaining_sum-cost)<0)
		{                                 
			printf("\u5bf9\u4e0d\u8d77\uff0c\u4f59\u989d\u4e0d\u8db3\uff0c\u8bf7\u53ca\u65f6\u5145\u503c\uff01");
			getchar();
			menu();
		}
		  
		p->remaining_sum-=cost;  
	}                                  
	printf("\u7ed3\u7b97\u6210\u529f\uff01");
    system("pause");
	system("cls");                                         
	getch();
}
Admin *adminExtend()  //card2
{
    Admin *p1 = admins;
    if (admins != NULL)
    {
        while (p1->next!= NULL)
            p1 = p1->next;
        p1->next = (Admin *)calloc(1,LENAdmin);
    }
    return (p1->next);
}

void cardUpdatePhone(Card* c)
{
       Card *p=c;
       if (cardIdentify(p))
       {
        printf("\u8bf7\u8f93\u5165\u65b0\u624b\u673a\u53f7\uff1a\n");
        char* s = getstr();
        if (s[0] != 'c' || strlen(s) == 1 || strspn(s + 1, "0123456789") != strlen(s + 1))
            printf("\u9519\u8bef\uff1a\u975e\u6cd5\u6570\u636e\uff01\n");
        else if (!cardSearch(cards, s))
        {
            strcpy(c->number, s);
            printf("\u4fee\u6539\u6210\u529f\uff01\n");
        }
        else
            printf("\u9519\u8bef\uff1a\u8be5\u5361\u53f7\u5df2\u5b58\u5728\uff01\n");
       }
}
void cardUpdatePassword(Card* c)
{
       
       if (cardIdentify(c))
       {
        printf("\u8bf7\u8f93\u5165\u65b0\u5bc6\u7801\uff1a\n");
        char *s = getstr();
        strcpy(c->password, s);
        printf("\u4fee\u6539\u6210\u529f\uff01\n");
       }
}







//��¼����Ա�˺�֮�����
void menu()//��Ա��ϵͳ����
{
    printf("\u002d\u002d\u002d\u002d\u002d\u002d\u002d\u002d\u002d\u002d\u002d\u002d\u002d\u002d\u002d\u002d\u002d\u83dc\u5355\u7ba1\u7406\u002d\u002d\u002d\u002d\u002d\u002d\u002d\u002d\u002d\u002d\u002d\u002d\u002d\u002d\u002d\u002d\n");
    printf("      1.�»�Աע��       2.��¼\n");
    printf("      3.�����Ϣ         4.��ѯ��Ϣ\n");
    printf("      5.��������         6.����ͳ��\n");
    printf("      7.ϵͳά��         0.�˳�\n");
    printf("----------��ӭʹ�û�Ա���Ʒ�ϵͳ----------\n");//�һ�����Ҫ��Ҫд
    int n=0,aa=0;
        printf("��ѡ���ܣ�");
        scanf("%d", &n);
        if(n==0)
        {
            adminLogOut();
            return;
        }
        char* numorphone;
        char* password;
        Card* c;
        int a=0;
        double m,k;
        switch(n)
        {
            case 1://cardSignUp
                cardSignUp();
                break;
            case 2://cardLogIn
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
                    printf("7.���ֻ���   8.��������\n");
                    printf("0.�˳�\n");
                    scanf("%d", &a);
                    switch (a)
                    {
                        case 1://�޸���Ϣ
                        cardFix(c);
                        break;
                        case 2://����
                        printf("�����뻨�ѽ�");
                        scanf("%lf", &m);
                        cardConsume(c, m);
                        //dd
                        Log* a=logExtend(c->consumeLog);
                        break;
                        case 3://��ֵ

                        printf("�������ֵ��");
                        scanf("%lf", &k);
                        cardRecharge(c, k);
                        logExtend(c->rechargeLog);
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
                        case 7://�����ֻ���
                           cardUpdatePhone(c);
                        case 8://��������
                           cardUpdatePassword(c);
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
            case 3://���������Ϣ 
                cardPrints();
                break;
            case 4://��ѯ��Ϣ
                //cardSearch();
                break;
            case 5://��������
                cards=cardSort();
                cardPrints();
                break;
            case 6://����ͳ��
                //cardSearchs();
                break;
            case 7://ϵͳά��
                //cards=cardFix();//��ʲô�Σ��θ���治��
                printf("1.����ά��\n");
                printf("2.���ݱ���\n");
                printf("3.���ݻָ�\n");
                printf("0.�˳�\n");
                printf("��ѡ����\n");
                scanf("%d", &aa);
                switch(aa)
                {
                    case 1://����ά��
                        printf("�����뿨�Ż��ֻ���\n");
                        numorphone=getstr();
                        cardFix(numorphone);
                        printf("����ά���ɹ������������!\n");
                        getch();
                        break;
                    case 2://���ݱ���
                        backUp();
                        printf("���ݱ��ݳɹ������������!\n");
                        getch();
                        break;
                    case 3://���ݻָ�
                        restore();
                        printf("���ݻָ��ɹ������������!\n");
                        getch();
                        break;
                    case 0://�˳�
                        printf("�˳��ɹ������������!\n");
                        getch();
                        break;
                    default:
                        printf("ERROR\n");
                        break;
                }
                break;
            default:
                printf("ERROR\n");
                break;
        }
        system("cls");
        menu();
}