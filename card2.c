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
void cardSort(Card* head)
{
    Card *p, *q, *tail;
    int exchange; //交换标志
    if(head->next == NULL){ //空链表直接返回
        return;
    }
    do{
        exchange = 0; //初始化交换标志
        tail = head; //尾节点指向头节点
        p = head->next; //p指向第一个节点
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
//登录用户的会员卡之后的界面
void menu()
{
    printf("**************************************\n");
    printf("******1.查询交易记录*******************\n");//按时间和金额查找某个数据
    printf("******2.查询卡内余额*******************\n");
    printf("******3.查询总消费金额*****************\n");
    printf("******4.会员卡挂失*********************\n");
    printf("******5.修改账户信息*******************\n");//
    printf("**************************************\n");
    printf("**************************************\n");

   
}
//登录管理员账号之后界面








