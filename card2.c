#include"card.h"
/*
Card* cardExtend(Card *head) {
    Card card;
    printf("请输入会员卡信息：");
    printf("会员卡号：");
    scanf("%s", card.number);
    printf("姓名：");
    scanf("%s", card.name);
    printf("余额：");
    scanf("%f", &card.remaining_sum);

    Card *p_new = (Card *)malloc(sizeof(Card));
    p_new->Card = card;//这句中的data还不会改，赶紧学
    p_new->next = NULL;
//总消费金额（与等级有关）还没写
//等级还没写
    Card*p = head;
    while (p->next) {
        p = p->next;
    }
    p->next = p_new;
    printf("会员卡添加成功！");
}*/
/*Card* cardSort()
{
    Card *p, *q, *tail;
    int exchange; //交换标志
    if(cards->next == NULL){ //空链表直接返回
        return cards;
    }
    do{
        exchange = 0; //初始化交换标志
        tail = cards; //尾节点指向头节点
        p = cards->next; //p指向第一个节点 //?
        while(p->next != NULL){ //遍历链表
            q = p->next; //q指向下一个节点
            if(p->number > q->number){ //如果p节点大于q节点
                tail->next = q; //将q节点插入到尾节点后面
                p->next = q->next;
                q->next = p;
                tail = q; //更新尾节点
                exchange = 1; //设置交换标志
            }else{ //否则不做任何操作
                tail = p;
                p = p->next;
            }
        }
    }while(exchange); //当存在交换时继续排序
}*/
//还未修改稍等
void cardPrint(Card* c);  //card2
{
    if(c==NULL) return;
    Card *member = c;
    printf("序号  姓名  性别  电话  余额\n");//把会员信息对应上并都输入进去，时间什么的也写上
    if (member)
    {
        printf("%s %s %s %.1f %.1f\n\n", member->name, member->sex, member->phone, member->money,member->paysum);
    }
    else
        printf("该会员不存在\n");
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
Card *cardSort()//用把这里的head改成cards吗？用！
{      
    printf("请选择按以下哪种方式排序（可以多选）\n");
    printf("1.按缴费总额升序排序    2.按消费金额升序排序\n");
    printf("3.按缴费总额降序排序    4.按消费金额降序排序\n");
    printf("5.按会员卡等级升序排序  6.按会员卡等级降序排序\n");
    printf("7.按会员卡卡号升序排序  8.按会员卡卡号降序排序\n");
    printf("9.按手机号升序排序      10.按手机号降序排序\n");
    int t;
    scanf("%d", &t);//怎么多选
    switch(t)
    case 1:                           
            Card *q,*tail,*p=(Card*)malloc(sizeof(Card)); //按缴费总额排序
            p->next=cards;
            cards=p;
            tail=NULL;                                                  //定义 tail
            while(tail!=cards->next)
            {
                p=cards;
                q=p->next;
                while(q->next!=tail)
                {                                                        //判断 q是否为空
                    if(p->next->total_charge>q->next->total_charge)
                    {
                        p->next=q->next;                                 //比较大小，排序
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
            return cards;                                                  //返回值
            break;
    case 3:                           
            Card *q,*tail,*p=(Card*)malloc(sizeof(Card)); //按缴费总额排序
            p->next=cards;
            cards=p;
            tail=NULL;                                                  //定义 tail
            while(tail!=cards->next)
            {
                p=cards;
                q=p->next;
                while(q->next!=tail)
                {                                                        //判断 q是否为空
                    if(p->next->total_charge<q->next->total_charge)
                    {
                        p->next=q->next;                                 //比较大小，排序
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
            card *q,*tail,*p=(card*)malloc(sizeof(card));                 //按消费金额排序
            p->next=cards;
            cards=p;
            tail=NULL;                                                     //定义 tail
            while(tail!=cards->next)
            {
                p=cards;
                q=p->next;
                while(q->next!=tail)
                {
                    if(p->next->total_charge-remaining_sum>q->next->total_charge-remaining_sum)
                    {                                                    //比较大小，排序
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
            return cards;                                        //返回值
            break;   
    case 4:                                                
            card *q,*tail,*p=(card*)malloc(sizeof(card));                 //按消费金额排序
            p->next=cards;
            cards=p;
            tail=NULL;                                                     //定义 tail
            while(tail!=cards->next)
            {
                p=cards;
                q=p->next;
                while(q->next!=tail)
                {
                    if(p->next->total_charge-remaining_sum<q->next->total_charge-remaining_sum)
                    {                                                    //比较大小，排序
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
            return cards;                                        //返回值
            break;          

}

void logPrint(Log* l) 
{
    if (l == NULL) return;
    printf("交易时间：%u年%02u月%02u日%02u时%02u分\n", l->time.year, l->time.month, l->time.day, l->time.hour, l->time.minute);
    printf("交易金额：%.2lf元\n", l->money);
}
void logPrints(Log* head)
{
    if (head == NULL) return;
    Log* cur = head;
    while (cur != NULL) 
    {

        printf("交易时间：%u年%02u月%02u日%02u时%02u分\n", cur->time.year, cur->time.month, cur->time.day, cur->time.hour, cur->time.minute);
        printf("交易金额：%.2lf元\n", cur->money);
        cur = cur->next;
    }
}


void cardFind(char* c)    //card2//解冻
{
    Card* p=cardSearch(c);
    if(p->isLost!=1)
    {
        printf("此卡未进行挂失，无法进行找回操作\n");
    }
    else
    if(cardIdentity(p))   //bool isLost	是否丢失（已丢失的卡无法使用）
    {
        p->isLost=0;
    }
    else 
    {
        printf("未通过验证，无法进行找回操作\n");
    }
    
}
void cardConsume(Card* c,double m)//会员卡消费及其折扣
{	                                                     	
	Card *p=c;
    double cost=m;                  
	system("cls");      
	if(p->short level>=5)//short level	会员卡等级（与折扣有关）
	{                                                         
		printf("您的会员卡已经五级，本次消费9折优惠。\n"); 
		printf("本次实际消费%.2f元！",cost*0.9);              
		cost*=0.9;
		if((p->remaining_sum-cost)<0)
		{                                                     //判断余额是否充足
			printf("对不起，余额不足，请及时充值！");
			getchar();
			menu();            
		}
		//p->cost+=cost;  //怎么用log消费记录，廖哥 ？                                      
		p->remaining_sum-=cost;                                       //消费
		getchar();
	}
	else
	{
		if((p->remaining_sum-cost)<0)
		{                                 //同上
			printf("对不起，余额不足，请及时充值！");
			getchar();
			menu();
		}
		//p->cost+=cost;   //同上
		p->remaining_sum-=cost;  
	}
	//modify_file(p);// 调用保存修改会员信息函数是哪个？                                  
	system("cls");                                         
	//display_one(p);  //调用显示一条函数是哪个？我懵了
	printf("结算成功，任意键继续!");
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


//登录管理员账号之后界面
void menu()//会员卡系统界面
{
    printf("-----------------菜单管理----------------\n");
    printf("      1.新会员注册       2.登录\n");
    printf("      3.  空           4.输出信息\n");
    printf("      5.查询信息         6.数据排序\n");
    printf("      7.数据统计         8.空\n");
    printf("      9.  空               10.系统维护\n");
    printf("      11.空            0.退出\n");
    printf("----------欢迎使用会员卡计费系统----------\n");
    //姓名，卡号，密码，
    //按时间和金额查找某个数据（包括充值和消费记录）
    
}
void test01() 
{
    int n=0,aa=0;
    do{
        system("cls");
        menu();
        printf("请选择操作：");
        scanf("%d", &n);
        switch(n)
        {
            case 1://注册
                cardSignUp();
                break;
            case 2://会员登录
                char* numorphone;
                char* password;
                printf("请输入会员卡卡号或手机号： \n");
                numorphone=getstr();
                printf("请输入会员卡密码： \n");
                password=getstr();
                Card *c=cardLogIn(numorphone,password);
                if(!c)
                {
                    printf("登录失败！");
                    break;
                }
                else
                {
                    printf("请选择要进行的操作： \n");
                    printf("1.修改信息   2.消费\n");
                    printf("3.充值       4.挂失\n");
                    printf("5.找回       6.退卡\n");
                    printf("0.退出\n");
                    int a=0;
                    scanf("%d", &a);
                    switch (a) // 还没有传参呢
                    {
                        case 1://修改信息
                        cardFix(c);
                        break;
                        case 2://消费
                        double m;
                        printf("请输入花费金额：");
                        scanf("%lf", &m);
                        cardConsume(c, m);
                        break;
                        case 3://充值
                        double n;
                        printf("请输入充值金额：");
                        scanf("%lf", &n);
                        cardRecharge(c, n);
                        break;
                        case 4: // 挂失
                        if (cardIdentify(c))
                        {
                            cardLost(c);
                            printf("挂失成功，任意键继续!");
                            getch();
                        }
                        break;
                        case 5://找回
                        if(cardIdentify(c)){
                            cardFind(c);//随机数
                        }
                        break;
                        case 6://退卡
                        if (cardIdentify(c))
                        {
                            cards=cardDelete(c);
                            printf("退卡成功，任意键继续!");
                            getch();
                        }
                        else
                        {
                        printf("会员卡身份验证错误，请重试！任意键继续\n");//重试怎么回到Identify那里呀
                        getch();
                        }
                        case 0:
                        cardLogOut();
                        printf("已退出此账号\n");
                        break;
                        default:
                        printf("ERROR\n");
                        break;
                    }
                    break;
                }
            case 4://输出信息 
                printf("1.输出所有信息     2.输出指定数据内容\n");
                scanf("%d", &aa);
                switch(aa)
                {
                    case 1:
                        cardPrints();
                        break;
                    case 2:
                        //cardPrint();//传啥参呢
                        break;
                    default:
                        printf("ERROR\n");
                        break;
                }
                break;
            case 5://查询信息
                //cardSearch();
                break;
            case 6://数据排序
                card* c=cardSort();
                cardPrints(c);
                break;
            case 7://数据统计
                //cardSearchs();
                break;
            
            case 9:
                
                break;
            case 10://系统维护
                cards=cardFix();//传什么参，廖哥帮帮，真不会
                break;
            case 0:
                printf("退出系统\n");
                break;
            default:
                printf("ERROR\n");
                break;
        }
    }
    while(n != 0);
    
}