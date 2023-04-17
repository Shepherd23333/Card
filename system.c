#include"card.h"
char* getstr(){
    char *str,*_str;
    int i = 1;
    str = (char*)malloc(sizeof(char)*(i+1));
    while((str[i-1]=getchar())!='\n'){
        i++;
        _str = (char*)malloc(strlen(str)+1);
        str[i-1]='\0';
        strcpy(_str, str);
        free(str);
        str = (char*)malloc(sizeof(char)*(i+1));
        if(!str){
            free(_str);
            printf("错误：内存溢出!");
            return NULL;
        }
        strcpy(str, _str);
        free(_str);
    }
    str[i-1]='\0';  
    return str;
}
bool isTime(int y,int mo,int d,int h,int mi){
    if(y>=1970&&1<=mo&&mo<=12){
        int b=y%4?0:(y%25||y%400==0);
        int ds[]={31,28+b,31,30,31,30,31,31,30,31,30,31};
        return 0<d&&d<=ds[mo]&&0<=h&&h<24&&0<=mi&&mi<60;
    }
    return 0;
}
void initialize(){
    printf("系统初始化中，请等待……\n");
    admins=adminCreate();
    cards=cardCreate();
    read();
    printf("初始化完成！\n");
    Sleep(1500);
    system("cls");
}
void adminLogIn(){
    printf("请输入账号（输入NULL返回系统）：\n");
    char* u;
    u=getstr();
    if(!strcmp(u,"NULL")){
        system("cls");
        System();
    }
    Admin *a=adminSearch(u);
    if(!a)
        printf("管理员帐户不存在！\n");
    else{
        printf("请输入密码：\n");
        char *p;
        p=getstr();
        if(!strcmp(p,a->password)){
            authority=a->isSuper+1;
            printf("登录成功！\n");
            isLoggedIn=1;
        }else
            printf("密码错误！\n"); 
    }
    system("pause");
}
void SASignUp(){
    printf("请输入密钥：\n");
    char *s;
    s=getstr();
    if(!strcmp(md5C(s),"79e70d8cf6d56c831544a24ee970d5ed")){
        printf("验证成功！\n");
        char *u,*p;
        printf("请输入账户名：\n");
        u=getstr();
        if(!adminSearch(u)){
            printf("请输入密码：\n");
            p=getstr();
            Admin *a=adminExtend(),t={u,p,1,NULL};
            *a=t;
            printf("注册成功！\n");
        }else
            printf("错误：该账户名已存在！\n");
    }else
        printf("密钥错误！\n");
}
void System(){
    printf("*****************************\n");
    printf("*****会员卡交易系统 v1.0*****\n");
    printf("*****************************\n");
    printf("请选择操作：\n");
    printf("（0.退出系统  1.注册超级管理员账户  2.登录（超级）管理员账户）\n");
    int f;
    scanf("%d",&f);
    if(f)
        f==1?SASignUp():adminLogIn();
    else
        exit(0);
    system("cls");
    if(!isLoggedIn)
        System();
}
bool authorize(){
    if(authority!=2){
        printf("错误：拒绝访问！\n该操作需要超级管理员权限。\n");
        return 0;
    }
    return 1;
}