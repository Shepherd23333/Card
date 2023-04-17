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
Card* cardSort()
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
}

void cardFind(char* n)    //card2
{

}



void cardConsume(Card* c, double m){
    
}   //card2
//登录管理员账号之后界面
void menu()//会员卡系统界面
{
    printf("-----------------菜单管理----------------\n");
    printf("      1.新会员注册       2.登录\n");
    printf("      3.挂失             4.输出信息\n");
    printf("      5.查询信息         6.数据排序\n");
    printf("      7.数据统计         8.找回\n");
    printf("      9.帮助             10.系统维护\n");
    printf("      11.退卡            0.退出\n");
    printf("----------欢迎使用会员卡计费系统----------\n");
    //姓名，卡号，密码，
    //按时间和金额查找某个数据（包括充值和消费记录）
}
void test01() 
{
    int n=0,aa=0;
    do{
        menu();
        printf("请选择要测试的操作：");
        scanf("%d", &n);
        switch(n)
        {
            case 1:
                cardSignUp();
                break;
            case 2:
                //cardLogIn();
                printf("请选择要进行的操作： \n");
                printf("1.修改信息   2.消费\n");
                printf("3.充值       0.退出\n");
                int a=0;
                scanf("%d", &a);
                switch(a)//还没有传参呢
                {
                    case 1:
                        //cardFix();
                        break;
                    case 2:
                        //cardConsume();
                        break;
                    case 3:
                        //cardRecharge();
                        break;
                    case 0:
                        cardLogOut();
                        printf("已退出此账号\n");
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
                //cardDelete(); //没传参   
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