#include"card.h"
void logIn(){
    printf("请输入账号：");
    char* u;
    gets(u);
    Admin a=*adminSearch(admins,u);
    printf("请输入密码：");
    char *p;
    gets(p);
    
}
bool authorize(){
    if(authority!=2){
        printf("错误：拒绝访问。\n该操作需要超级管理员权限。\n");
        return 0;
    }
    return 1;
}