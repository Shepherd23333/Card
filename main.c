#include"card.h"
int main(){
    read();
    printf("*****************************\n");
    printf("*****会员卡交易系统 v1.0*****\n");
    printf("*****************************\n");
    printf("请登录系统账户：\n");
    while(!isLoggedIn)
        logIn();
    system("cls");

    system("pause");
    return 0;
}