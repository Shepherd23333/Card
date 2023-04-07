#include"card.h"
void logIn(){
    printf("请输入账号：\n");
    char* u;
    gets(u);
    Admin *a=adminSearch(admins,u);
    if(a==NULL){
        printf("管理员帐户不存在！\n");
    }else{
        printf("请输入密码：\n");
        char *p;
        gets(p);
        if(!strcmp(p,(*a).password)){
            authority=(*a).isSuper+1;
            printf("登录成功！\n");
        }else{
            printf("密码错误！\n");
        }
    }
}
bool authorize(){
    if(authority!=2){
        printf("错误：拒绝访问。\n该操作需要超级管理员权限。\n");
        return 0;
    }
    return 1;
}